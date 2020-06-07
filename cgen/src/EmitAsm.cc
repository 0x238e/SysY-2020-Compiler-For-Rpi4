#include "asmgen.hpp"
#include "llvm/ADT/Statistic.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include <iostream>
#include <string>

using namespace llvm;

std::map<Value *, int> var_id;
int var_count;
std::map<Value *, int> stack_id;
int stack_count;
std::map<Value *, int> bb_id;
int bb_count;

std::vector<Instruction *> inst_vec;
std::map<Instruction *, int> inst_id;
int inst_count;

struct LiveInterval {
  Value *vreg;
  int reg; // Registered assigned, if any
  int loc; // Location spilled on stack
  int begin;
  int end;
};

std::map<Value *, LiveInterval *> live_id;
std::list<LiveInterval *> active_list;

// Number of registers used in register allocation
int reg_used;

bool cmp_begin(LiveInterval *a, LiveInterval *b) { return a->begin < b->begin; }

bool cmp_end(LiveInterval *a, LiveInterval *b) { return a->end < b->end; }

constexpr int pool_size = 16;
bool register_pool[pool_size];

int pool_get() {
  // Register for local variable use starts from r4
  for (int i = 4; i < 10; i++) {
    if (register_pool[i] == false) {
      register_pool[i] = true;

      if (i > reg_used)
        reg_used = i;

      return i;
    }
  }

  assert(!"No available register, should not happen\n");
  return -1;
}

void pool_add(int i) {
  assert(i < pool_size);
  register_pool[i] = false;
}

void pool_clear() {
  for (int i = 0; i < pool_size; i++) {
    register_pool[i] = false;
  }
}

StringRef funcName;
ICmpInst::Predicate lastPred;

namespace {
struct EmitAsm : public PassInfoMixin<EmitAsm> {
  PreservedAnalyses run(Module &M, ModuleAnalysisManager &) {
    EmitGlobals(M);
    EmitCode(M);

    return PreservedAnalyses::all();
  }

  void emit_icmp(Instruction &I);
  void emit_br(Instruction &I);
  void emit_load(Instruction &I);
  void emit_store(Instruction &I);
  void emit_call(Instruction &I);
  void emit_ret(Instruction &I);

  void emit_add(Instruction &I);
  void emit_sub(Instruction &I);
  void emit_mul(Instruction &I);
  void emit_sdiv(Instruction &I);
  void emit_srem(Instruction &I);

  void EmitGlobals(Module &M);
  void EmitCode(Module &M);
  void EmitFunction(Function &F);
  void EmitBasicBlock(BasicBlock &BB);
  void EmitDirective(std::string s);
  void EmitLabel(std::string s);
  void EmitBanner(std::string s);
};
} // namespace

void flatten(Function &F) {
  for (auto &BB : F) {
    // Assign index to each basic block
    bb_id[&BB] = bb_count;
    bb_count += 1;

    for (auto &I : BB) {
      // If it is an alloca instruction, assign index
      // to each stack location
      if (I.getOpcode() == Instruction::Alloca) {
        stack_id[&I] = stack_count;
        stack_count += 1;
      }

      // Assign index to each instruction
      inst_vec.push_back(&I);
      inst_id[&I] = inst_count;
      inst_count += 1;

      // Assign index to each local variable
      // Store and branching instructions do not have a return value
      if (!(I.getOpcode() == Instruction::Store ||
            I.getOpcode() == Instruction::Br ||
            I.getOpcode() == Instruction::Ret)) {
        var_id[&I] = var_count;
        var_count += 1;
      }
    }
  }
}

bool contains_operand(Instruction *I, Value *v) {
  for (auto op = I->op_begin(); op != I->op_end(); op++) {
    if (v == *op) {
      return true;
    }
  }

  return false;
}

bool within_inst(Instruction *start, Instruction *end, Instruction *i) {
  return inst_id[start] <= inst_id[i] && inst_id[i] <= inst_id[end];
}

void live_interval_analysis(Function &F) {
  for (auto &I : inst_vec) {
    if (I->getOpcode() == Instruction::Store ||
        I->getOpcode() == Instruction::Br ||
        I->getOpcode() == Instruction::Ret) {
      continue;
    }

    // First definition of variable
    live_id[I] = new LiveInterval();
    live_id[I]->vreg = I;
    live_id[I]->begin = inst_id[I];

    // Last use of variable
    // Scan backward
    auto back = inst_vec.end() - 1;
    while (back != inst_vec.begin()) {
      if (contains_operand(*back, I)) {
        live_id[I]->end = inst_id[*back];
        break;
      }

      back--;
    }

    // Scan forward to look for backward branch
    // Watch out for conditionals in loop
    auto it = back;
    while (it != inst_vec.end()) {
      auto tmp = dyn_cast<BranchInst>(*it);
      if (tmp) {
        for (auto succ : tmp->successors()) {
          if (within_inst(I, *back, succ->getFirstNonPHI())) {
            back = it;
            live_id[I]->end = inst_id[*it];
          }
        }
      }

      it++;
    }
  }
}

void expire_old_interval(LiveInterval *i) {
  auto remove_count = 0;
  for (auto &j : active_list) {
    if (j->end > i->begin) {
      break;
    }

    remove_count += 1;
    pool_add(j->reg);
  }

  // Do not manipulate list when iterating over it
  for (int i = 0; i < remove_count; i++)
    active_list.pop_front();

  // Maintain active list in increasing end point order
  active_list.sort(cmp_end);
}

int new_stack_location() {
  stack_count += 1;
  return stack_count;
}

void spill_at_interval(LiveInterval *i) {
  auto last = active_list.end();
  if ((*last)->end > i->end) {
    i->reg = (*last)->reg;
    (*last)->loc = new_stack_location();

    active_list.pop_back();
    active_list.push_back(i);
  } else {
    i->loc = new_stack_location();
  }
}

void allocate_register(Function &F) {
  for (auto &i : live_id) {
    expire_old_interval(i.second);
    if (active_list.size() == 6) {
      spill_at_interval(i.second);
    } else {
      i.second->reg = pool_get();
      active_list.push_back(i.second);
      active_list.sort(cmp_end);
    }
  }
}

void assign_arg_register(Function &F) {
  // Assign Function parameters to r0 - r4
  int i = 0;
  for (auto &arg : F.args()) {
    if (i < 4) {
      Value *v = &arg;
      live_id[v] = new LiveInterval();
      live_id[v]->reg = i;
    } else {
      // The rest parameters on stack
    }

    i++;
  }
}

void EmitAsm::EmitGlobals(Module &M) {

  EmitBanner("start of .data section");
  EmitDirective(".align 4");
  EmitDirective(".data");

  auto &CTX = M.getContext();

  for (auto &g : M.getGlobalList()) {
    assert(g.getNumOperands() == 1);
    auto op0 = g.getOperand(0);

    // If A global variable is of array type,
    // then it could be a string or int array
    if (g.getOperand(0)->getType()->isArrayTy()) {
      auto arr = cast<ConstantDataArray>(op0);
      auto elementType = arr->getElementType();
      if (elementType == Type::getInt8Ty(CTX)) {
        EmitLabel(g.getName());
        errs() << "\t"
               << ".asciz"
               << "\n";
        errs() << "\t" << arr->getAsCString() << "\n";
      } else if (elementType == Type::getInt32Ty(CTX)) {
        EmitLabel(g.getName());
        for (int i = 0; i < arr->getNumElements(); i++) {
          errs() << "\t"
                 << ".word"
                 << "\t" << arr->getElementAsInteger(i) << "\n";
        }
      }
    } else {
      EmitLabel(g.getName());
      auto gint = cast<ConstantInt>(op0);
      errs() << "\t"
             << ".word"
             << "\t" << gint->getSExtValue() << "\n";
    }
    errs() << "\n";
  }

  EmitBanner("end of .data section");
}

void EmitAsm::EmitCode(Module &M) {
  EmitBanner("start of .text section");
  EmitDirective(".align 4");
  EmitDirective(".text");
  EmitDirective(".global main");

  for (auto &F : M) {
    if (!F.isDeclaration())
      EmitFunction(F);
  }

  EmitBanner("end of .text section");
}

void reset() {
  var_id.clear();
  var_count = 0;
  stack_id.clear();
  stack_count = 1;
  bb_id.clear();
  bb_count = 0;
  inst_vec.clear();
  inst_id.clear();
  inst_count = 0;

  live_id.clear();
  active_list.clear();

  reg_used = 0;
  pool_clear();
}

std::string reglist2str(std::vector<int> v) {
  assert(!v.empty());
  std::string result = "{";

  for (auto &i : v) {
    result += as::reg2str(i) + ", ";
  }

  result.pop_back();
  result.pop_back();
  result += "}";

  return result;
}

void emit_prolog(Function &F) {
  as::push(reglist2str({4, 5, 6, 7, 8, 9, as::fp, as::lr}));
  as::mov(as::reg2str(as::fp), as::reg2str(as::sp));
}

void emit_epilog(Function &F) {
  as::mov(as::reg2str(as::sp), as::reg2str(as::fp));
  as::pop(reglist2str({4, 5, 6, 7, 8, 9, as::fp, as::pc}));
}

void dump_register_mapping(Function &F) {
  for (auto &i : live_id) {
    errs() << i.second->reg << ", "
           << inst_id[dyn_cast<Instruction>(i.second->vreg)] << "\n";
  }
}

void EmitAsm::EmitFunction(Function &F) {
  errs() << "\n";

  reset();
  flatten(F);
  live_interval_analysis(F);
  allocate_register(F);
  assign_arg_register(F);

  funcName = F.getName();
  // Print Function name
  errs() << F.getName() << ":"
         << "\n";

  emit_prolog(F);
  for (auto &BB : F) {
    EmitBasicBlock(BB);
  }
  emit_epilog(F);

  errs() << "\n";
}

int get_var(Value *v) { return var_id[v]; }

int get_bb(Value *v) { return bb_id[v]; }

// Get corresponding physical register of a variable
int get_reg(Value *v) { return live_id[v]->reg; }

// Convert an operand to immediate number if it is a constant,
// a register otherwise
std::string op2str(Value *op) {
  auto opConst = dyn_cast<ConstantInt>(op);
  if (opConst) {
    return as::const2str(opConst->getSExtValue());
  } else {
    return as::reg2str(get_reg(op));
  }
}

std::string op2regstr(Value *op) {
  auto opConst = dyn_cast<ConstantInt>(op);
  if (opConst) {
    as::mov(as::reg2str(as::t0), as::const2str(opConst->getSExtValue()));
    return as::reg2str(as::t0);
  } else {
    return as::reg2str(get_reg(op));
  }
}

std::string get_label(Value *v) {
  std::string tmp = funcName; // Cast to std::string
  return tmp + "_" + std::to_string(get_bb(v));
}

void emit_alloca(Instruction &I) {
  // stack_id[&I] = stack_count;
  // stack_count += 1;

  as::sub(as::reg2str(as::sp), as::reg2str(as::sp), as::const2str(4));
}

void EmitAsm::EmitBasicBlock(BasicBlock &BB) {
  EmitLabel(get_label(&BB));
  for (auto &I : BB) {
    switch (I.getOpcode()) {
    case Instruction::Alloca:
      emit_alloca(I);
      break;
    // Branch instruction;
    case Instruction::ICmp:
      emit_icmp(I);
      break;
    case Instruction::Br:
      emit_br(I);
      break;
    // Load/Store instruction
    case Instruction::Load:
      emit_load(I);
      break;
    case Instruction::Store:
      emit_store(I);
      break;
    case Instruction::Call:
      emit_call(I);
      break;
    case Instruction::Ret:
      emit_ret(I);
      break;
    // Binary operators
    case Instruction::Mul:
      emit_mul(I);
      break;
    case Instruction::Add:
      emit_add(I);
      break;
    case Instruction::Sub:
      emit_sub(I);
      break;
    case Instruction::SDiv:
      emit_sdiv(I);
      break;
    case Instruction::SRem:
      emit_srem(I);
      break;
    // case Instruction::PHI:
    //   emit_phi(I);
    default:
      errs() << "\t@ ";
      I.print(errs());
      errs() << "\n";
    }
  }
}

void emit_arithmetic(
    std::function<void(std::string, std::string, std::string)> f,
    Instruction &I) {
  auto op0 = I.getOperand(0);
  auto op1 = I.getOperand(1);
  auto dst = &I;
  f(op2str(dst), op2str(op0), op2str(op1));
}

std::map<ICmpInst::Predicate, std::string> cond = {
    {ICmpInst::ICMP_EQ, "eq"},  {ICmpInst::ICMP_NE, "ne"},
    {ICmpInst::ICMP_SGE, "ge"}, {ICmpInst::ICMP_SGT, "gt"},
    {ICmpInst::ICMP_SLE, "le"}, {ICmpInst::ICMP_SLT, "lt"},
};

void EmitAsm::emit_icmp(Instruction &I) {
  // Negate Predicate, branch if condition does not hold
  lastPred = dyn_cast<ICmpInst>(&I)->getInversePredicate();
  auto op0 = I.getOperand(0);
  auto op1 = I.getOperand(1);
  as::cmp(op2str(op0), op2str(op1));
}

void EmitAsm::emit_br(Instruction &I) {
  auto tmp = dyn_cast<BranchInst>(&I);
  if (tmp->isConditional()) {
    as::bcond(cond[lastPred], get_label(tmp->getOperand(1)));
  } else {
    as::b(get_label(tmp->getOperand(0)));
  }
}

std::string get_global_label(Value *v) {
  std::string label;
  auto tmp = dyn_cast<GEPOperator>(v);
  if (tmp) {
    // Reference a global array
    std::string name = tmp->getOperand(0)->getName();
    int index = dyn_cast<ConstantInt>(tmp->getOperand(2))->getSExtValue();
    // An int is always of size 4
    label = name + "+" + std::to_string(index * 4);

  } else {
    // Reference a global variable
    label = v->getName();
  }
  return label;
}

void EmitAsm::emit_load(Instruction &I) {
  auto addr = I.getOperand(0);
  auto dst = op2str(&I);
  if (stack_id.find(addr) != stack_id.end()) {
    // Local variable on stack
    int offset = stack_id[addr] * (-4);
    as::ldr(dst, as::reg2str(as::fp), as::const2str(offset));
  } else {
    // Global variable or array
    std::string label = get_global_label(addr);
    as::ldr_label(as::reg2str(as::t0), label);
    as::ldr(dst, as::reg2str(as::t0), as::const2str(0));
  }
}

void EmitAsm::emit_store(Instruction &I) {
  auto src = I.getOperand(0);
  auto addr = I.getOperand(1);
  if (stack_id.find(addr) != stack_id.end()) {
    // Local variable on stack
    int offset = stack_id[addr] * (-4);
    as::str(op2regstr(src), as::reg2str(as::fp), as::const2str(offset));
  } else {
    // Global variable or array
    std::string label = get_global_label(addr);
    as::ldr_label(as::reg2str(as::t0), label);
    as::str(op2regstr(src), as::reg2str(as::t0), as::const2str(0));
  }
}

void EmitAsm::emit_call(Instruction &I) {
  assert(I.getNumOperands() <= 4);
  auto tmp = dyn_cast<CallInst>(&I);
  int i = 0;

  // Iterate over arguments of function
  for (auto it = tmp->arg_begin(); it != tmp->arg_end(); it++, i++) {
    as::mov(as::reg2str(i), op2str(*it));
  }

  as::bl(tmp->getCalledFunction()->getName());

  // Save return value in destination
  as::mov(op2str(&I), as::reg2str(0));
}

void EmitAsm::emit_ret(Instruction &I) {
  as::mov(as::reg2str(0), op2str(I.getOperand(0)));
}

void EmitAsm::emit_add(Instruction &I) { emit_arithmetic(as::add, I); }

void EmitAsm::emit_sub(Instruction &I) {
  auto op0 = I.getOperand(0);
  auto op1 = I.getOperand(1);
  auto dst = &I;

  as::sub(op2str(dst), op2regstr(op0), op2str(op1));
}

// Both operands of mul must be register
void EmitAsm::emit_mul(Instruction &I) {
  auto op0 = I.getOperand(0);
  auto op1 = I.getOperand(1);
  auto dst = &I;

  as::mul(op2str(dst), op2str(op0), op2regstr(op1));
}

void EmitAsm::emit_sdiv(Instruction &I) {
  errs() << "\t"
         << "@ division operation"
         << "\n";

  as::mov(as::reg2str(0), op2str(I.getOperand(0)));
  as::mov(as::reg2str(1), op2str(I.getOperand(1)));
  as::bl("__divsi3");
  as::mov(op2str(&I), as::reg2str(0));
}

void EmitAsm::emit_srem(Instruction &I) {
  errs() << "\t"
         << "@ remainder operation"
         << "\n";

  as::mov(as::reg2str(0), op2str(I.getOperand(0)));
  as::mov(as::reg2str(1), op2str(I.getOperand(1)));
  as::bl("__modsi3");
  as::mov(op2str(&I), as::reg2str(0));
}

void EmitAsm::EmitDirective(std::string s) { errs() << s << "\n"; }

void EmitAsm::EmitLabel(std::string s) { errs() << s << ":\n"; }

void EmitAsm::EmitBanner(std::string s) {
  errs() << "@ ---- " << s << " ---- @\n";
}

PassPluginLibraryInfo llvmGetPassPluginInfo() {
  return {LLVM_PLUGIN_API_VERSION, "MyPass", "v0.1", [](PassBuilder &PB) {
            PB.registerPipelineParsingCallback(
                [](StringRef, ModulePassManager &MPM,
                   ArrayRef<PassBuilder::PipelineElement>) {
                  MPM.addPass(EmitAsm());
                  return true;
                });
          }};
}
int main(){
return 0;
}
