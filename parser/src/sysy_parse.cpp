/**
 * @author ZoneLikeWonderland
 * @email zhanglw2@shanghaitech.edu.cn
 * @create date 2020-05-20 18:26:00
 * @modify date 2020-05-21 10:29:20
 * @desc sysy ast
 */
#include "sysy_parse.hpp"
#include <cstdio>

#define I32 "i32"
#define VOID "void"

CompUnit::CompUnit() {
    ListSubCompUnit = new vector<SubCompUnit *>;
}
CompUnit::CompUnit(SubCompUnit *item) {
    ListSubCompUnit = new vector<SubCompUnit *>({item});
}
CompUnit::CompUnit(CompUnit *old, SubCompUnit *item) {
    ListSubCompUnit = old->ListSubCompUnit;
    ListSubCompUnit->push_back(item);
}
void CompUnit::Dump() {
    printf("Compile Unit Dump:\n");
    for (auto &x : *ListSubCompUnit)
        x->Dump();
}

Decl::Decl(DefList *a) : SonDefList(a){};
void Decl::Dump() {
    SonDefList->Dump();
}

DefList::DefList() {
    ListDef = new vector<Def *>;
}
DefList::DefList(Def *item) {
    ListDef = new vector<Def *>({item});
}
DefList::DefList(DefList *old, Def *item) {
    ListDef = old->ListDef;
    ListDef->push_back(item);
}
void DefList::Dump() {
    for (auto &x : *ListDef)
        x->Dump();
}

Def::Def(Name *a, Array *b, InitValDad *c)
    : SonName(a), SonArray(b), SonInitValDad(c) {
}
void Def::Dump() {
    printf("%%%s = alloc ", SonName->SonChar);
    if (SonArray->Dims->size()) {
        size_t depth = 0;
        for (auto &x : *SonArray->Dims) {
            depth++;
            printf("[%d x ", x->Eval());
        }
        printf("%s", I32);
        while (depth--)
            printf("]");
    } else {
        printf("%s", I32);
    }
    printf("\n");
}

ExpDad::ExpDad(ExpType a, ExpDad *b, ExpDad *c, LVal *d, Name *e,
               FuncRParams *f, Number *g)
    : Type(a), Exp1(b), Exp2(c), SonLVal(d), Callee(e), Params(f),
      SonNumber(g) {
}
void ExpDad::Dump() {
}

Name::Name(const char *a) : SonChar(a) {
}
void Name::Dump() {
}

InitValDad::InitValDad(InitValType a, ExpDad *b, InitValListDad *c)
    : Type(a), SonExp(b), SonInitValListDad(c) {
}
void InitValDad::Dump() {
}

InitValListDad::InitValListDad() {
    ListInitValDad = new vector<InitValDad *>;
}
InitValListDad::InitValListDad(InitValDad *item) {
    ListInitValDad = new vector<InitValDad *>({item});
}
InitValListDad::InitValListDad(InitValListDad *old, InitValDad *item) {
    ListInitValDad = old->ListInitValDad;
    ListInitValDad->push_back(item);
}
void InitValListDad::Dump() {
}

ArrayDad::ArrayDad() {
    Dims = new vector<ExpDad *>;
}
ArrayDad::ArrayDad(ArrayDad *old, ExpDad *item) {
    Dims = old->Dims;
    Dims->push_back(item);
}
void ArrayDad::Dump() {
}

FuncDef::FuncDef(ReturnType a, Name *b, FuncFParams *c, Block *d)
    : RType(a), FuncName(b), SonFuncFParams(c), SonBlock(d) {
}
void FuncDef::Dump() {
    printf("define %s @%s(", RType == INT ? I32 : VOID, FuncName->SonChar);
    SonFuncFParams->Dump();
    printf(") {\n");
    SonBlock->Dump();
    printf("}\n");
}

FuncFParams::FuncFParams() {
    ListFuncFParam = new vector<FuncFParam *>;
}
FuncFParams::FuncFParams(FuncFParam *item) {
    ListFuncFParam = new vector<FuncFParam *>({item});
}
FuncFParams::FuncFParams(FuncFParams *old, FuncFParam *item) {
    ListFuncFParam = old->ListFuncFParam;
    ListFuncFParam->push_back(item);
}
void FuncFParams::Dump() {
    for (auto x = ListFuncFParam->begin(); x != ListFuncFParam->end(); x++) {
        if (x != ListFuncFParam->begin())
            printf(", ");
        (*x)->Dump();
    }
}

FuncFParam::FuncFParam(Name *a, DynArray *b) : ParaName(a), SonArray(b) {
}
void FuncFParam::Dump() {
    if (SonArray && SonArray->Dims->size())
        printf("%s*", I32);
    else
        printf("%s", I32);
}

Block::Block(BlockItemList *a) : SonBlockItemList(a) {
}
void Block::Dump() {
    SonBlockItemList->Dump();
}

BlockItem::BlockItem(BlockType a, Decl *b, Stmt *c)
    : Type(a), SonDecl(b), SonStmt(c) {
}
void BlockItem::Dump() {
    if (Type == DECL)
        SonDecl->Dump();
    else
        SonStmt->Dump();
}

BlockItemList::BlockItemList() {
    ListBlockItem = new vector<BlockItem *>;
}
BlockItemList::BlockItemList(BlockItemList *old, BlockItem *item) {
    ListBlockItem = old->ListBlockItem;
    ListBlockItem->push_back(item);
}
void BlockItemList::Dump() {
    for (auto &x : *ListBlockItem)
        x->Dump();
}

Stmt::Stmt(StmtType a, Stmt *b, Stmt *c, LVal *d, Exp *e, Cond *f, Block *g)
    : Type(a), Stmt1(b), Stmt2(c), SonLVal(d), SonExp(e), SonCond(f),
      SonBlock(g) {
}
void Stmt::Dump() {
    if (Type == IF) {

    } else if (Type == ASSIGN) {

    } else if (Type == EXP) {

    } else if (Type == EMPTY) {

    } else if (Type == BLOCK) {

    } else if (Type == WHILE) {

    } else if (Type == BREAK) {

    } else if (Type == CONTINUE) {

    } else if (Type == RET) {
    }
}

FuncRParams::FuncRParams(ExpList *a) : SonExpList(a) {
}
void FuncRParams::Dump() {
}

ExpList::ExpList() {
    ListExp = new vector<Exp *>;
}
ExpList::ExpList(Exp *item) {
    ListExp = new vector<Exp *>({item});
}
ExpList::ExpList(ExpList *old, Exp *item) {
    ListExp = old->ListExp;
    ListExp->push_back(item);
}
void ExpList::Dump() {
}

LVal::LVal(Name *a, DynArray *b) : VarName(a), SonArray(b) {
}
void LVal::Dump() {
}

Cond::Cond(CondType a, Exp *b, Exp *c, Cond *d, Cond *e)
    : Type(a), Exp1(b), Exp2(c), Cond1(d), Cond2(e) {
}
void Cond::Dump() {
}

Number::Number(int a) : RawNumber(a) {
}
void Number::Dump() {
}

int Exp::Eval() {
    return 0;
}

int ConstExp::Eval() {
    switch (Type) {
    case PLUS:
        return Exp1->Eval() + Exp2->Eval();
    case MINUS:
        return Exp1->Eval() - Exp2->Eval();
    case MUL:
        return Exp1->Eval() * Exp2->Eval();
    case DIV:
        return Exp1->Eval() / Exp2->Eval();
    case MOD:
        return Exp1->Eval() % Exp2->Eval();
    case POS:
        return Exp1->Eval();
    case NEG:
        return -Exp1->Eval();
    case SUBEXP:
        return Exp1->Eval();
    case INTEGER:
        return SonNumber->RawNumber;
    default:
        return 0;
    }
}
