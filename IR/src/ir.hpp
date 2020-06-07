#include <initializer_list>
#include <vector>
#include <string>
#include <list>

using std::initializer_list;
using std::list;
using std::string;
using std::vector;

enum OPCODE
{
    ADD
};

enum OPERAND_TYPE
{
    I32,
    I32_PTR,
    LABEL,
    FUNC
};

class Global
{
  public:
    string spelling;
    int id;

    Global(string a, int b) : spelling(a), id(b) {}
};

class Function : public Global
{
  public:
    list<BasicBlock> basicBlock;
    vector<OPERAND_TYPE> argType;
    enum OPERAND_TYPE returnType;
    bool variadic;

    Function(string sp, int i, initializer_list<BasicBlock> a,
             initializer_list<OPERAND_TYPE> b, enum OPERAND_TYPE c)
        : Global(sp, i), basicBlock(a), argType(b), returnType(c)
    {
    }
};

class GlobalInt : public Global
{
  public:
    int value;

    GlobalInt(string a, int b, int c) : Global(a, b), value(c) {}
};

class GlobalArray : public Global
{
  public:
    vector<int> data;

    GlobalArray(string a, int b, initializer_list<int> c)
        : Global(a, b), data(c)
    {
    }
};

class Module
{
  public:
    vector<Function> func;
    vector<Global> globalVar;

    Module(initializer_list<Function> a, initializer_list<Global> b)
        : func(a), globalVar(b)
    {
    }
};

class BasicBlock
{
  public:
    list<Instruction> instr;
    int label;

    BasicBlock(initializer_list<Instruction> a, int b) : instr(a), label(b) {}
};

class Instruction
{
  public:
    OPCODE Opcode;
    vector<Operand> Operands;
    Instruction(OPCODE a, const initializer_list<Operand> t)
        : Opcode(a), Operands(t)
    {
    }
};

class Operand
{
  public:
    OPERAND_TYPE Optype;
    int value;
    bool isGlobal;
    Operand(OPERAND_TYPE a, int b, bool c) : Optype(a), value(b), isGlobal(c) {}
};

class NameOperand : public Operand
{
  public:
    using Operand::Operand;
};

class ConstantOperand : public Operand
{
  public:
    using Operand::Operand;
};