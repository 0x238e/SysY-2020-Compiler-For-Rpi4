/**
 * @author ZoneLikeWonderland
 * @email zhanglw2@shanghaitech.edu.cn
 * @create date 2020-05-20 18:26:00
 * @modify date 2020-05-21 10:29:20
 * @desc sysy ast
 */
#include <vector>
using std::vector;

#pragma once

enum ExpType {
    PLUS,
    MINUS,
    MUL,
    DIV,
    MOD,
    POS,
    NEG,
    SUBEXP,
    LVAL,
    CALL,
    INTEGER
};
enum InitValType { INITEXP, INITLIST };
enum ReturnType { VOID, INT };
enum StmtType { IF, ASSIGN, EXP, EMPTY, BLOCK, WHILE, BREAK, CONTINUE, RET };
enum CondType { EQ, NE, LT, GT, LE, GE, SUBCOND, NOT, AND, OR };
enum BlockType { DECL, STMT };

class CompUnit;
class Decl;
class ConstDecl;
class ConstDefList;
class ConstDef;
class Array;
class ConstInitVal;
class ConstInitValList;
class VarDecl;
class VarDefList;
class VarDef;
class InitVal;
class InitValList;
class FuncDef;
class FuncFParams;
class FuncFParam;
class DynArray;
class Block;
class BlockItem;
class BlockItemList;
class Stmt;
class Exp;
class FuncRParams;
class ExpList;
class LVal;
class Cond;
class ConstExp;
class Number;

class SubCompUnit;
class InitValDad;
class InitValListDad;
class Name;
class Def;
class DefList;

class CompUnit {
  public:
    vector<SubCompUnit *> *ListSubCompUnit;
    CompUnit();
    CompUnit(SubCompUnit *item);
    CompUnit(CompUnit *old, SubCompUnit *item);
    void Dump();
};

class SubCompUnit {
  public:
    virtual void Dump() = 0;
};

class Decl : public SubCompUnit {
  public:
    DefList *SonDefList;
    Decl(DefList *a);
    void Dump();
};

class DefList {
  public:
    vector<Def *> *ListDef;
    DefList();
    DefList(Def *item);
    DefList(DefList *old, Def *item);
    void Dump();
};

class Def {
  public:
    Name *SonName;
    Array *SonArray;
    InitValDad *SonInitValDad;
    Def(Name *a, Array *b, InitValDad *c);
    void Dump();
};

class ExpDad {
  public:
    ExpType Type;
    ExpDad *Exp1;
    ExpDad *Exp2;
    LVal *SonLVal;
    Name *Callee;
    FuncRParams *Params;
    Number *SonNumber;
    ExpDad(ExpType a, ExpDad *b, ExpDad *c, LVal *d, Name *e, FuncRParams *f,
           Number *g);
    void Dump();
    virtual int Eval() = 0;
};

class Name {
  public:
    const char *SonChar;
    Name(const char *a);
    void Dump();
};

class InitValDad {
  public:
    InitValType Type;
    ExpDad *SonExp;
    InitValListDad *SonInitValListDad;
    InitValDad(InitValType a, ExpDad *b, InitValListDad *c);
    void Dump();
};

class InitValListDad {
  public:
    vector<InitValDad *> *ListInitValDad;
    InitValListDad();
    InitValListDad(InitValDad *item);
    InitValListDad(InitValListDad *old, InitValDad *item);
    void Dump();
};

class ConstDecl : public Decl {
  public:
    using Decl::Decl;
};
class ConstDefList : public DefList {
  public:
    using DefList::DefList;
};
class ConstDef : public Def {
  public:
    using Def::Def;
};

class ArrayDad {
  public:
    vector<ExpDad *> *Dims;
    ArrayDad();
    ArrayDad(ArrayDad *old, ExpDad *item);
    void Dump();
};

class Array : public ArrayDad {
  public:
    using ArrayDad::ArrayDad;
};
class ConstInitVal : public InitValDad {
  public:
    using InitValDad::InitValDad;
};
class ConstInitValList : public InitValListDad {
  public:
    using InitValListDad::InitValListDad;
};
class VarDecl : public Decl {
  public:
    using Decl::Decl;
};
class VarDefList : public DefList {
  public:
    using DefList::DefList;
};
class VarDef : public Def {
  public:
    using Def::Def;
};
class InitVal : public InitValDad {
  public:
    using InitValDad::InitValDad;
};
class InitValList : public InitValListDad {
  public:
    using InitValListDad::InitValListDad;
};
class FuncDef : public SubCompUnit {
  public:
    ReturnType RType;
    Name *FuncName;
    FuncFParams *SonFuncFParams;
    Block *SonBlock;
    FuncDef(ReturnType a, Name *b, FuncFParams *c, Block *d);
    void Dump();
};
class FuncFParams {
  public:
    vector<FuncFParam *> *ListFuncFParam;
    FuncFParams();
    FuncFParams(FuncFParam *item);
    FuncFParams(FuncFParams *old, FuncFParam *item);
    void Dump();
};
class FuncFParam {
  public:
    Name *ParaName;
    DynArray *SonArray;
    FuncFParam(Name *a, DynArray *b);
    void Dump();
};
class DynArray : public ArrayDad {
  public:
    using ArrayDad::ArrayDad;
};
class Block {
  public:
    BlockItemList *SonBlockItemList;
    Block(BlockItemList *a);
    void Dump();
};
class BlockItem {
  public:
    BlockType Type;
    Decl *SonDecl;
    Stmt *SonStmt;
    BlockItem(BlockType a, Decl *b, Stmt *c);
    void Dump();
};
class BlockItemList {
  public:
    vector<BlockItem *> *ListBlockItem;
    BlockItemList();
    BlockItemList(BlockItemList *old, BlockItem *item);
    void Dump();
};
class Stmt {
  public:
    StmtType Type;
    Stmt *Stmt1;
    Stmt *Stmt2;
    LVal *SonLVal;
    Exp *SonExp;
    Cond *SonCond;
    Block *SonBlock;
    Stmt(StmtType a, Stmt *b, Stmt *c, LVal *d, Exp *e, Cond *f, Block *g);
    void Dump();
};
class Exp : public ExpDad {
  public:
    using ExpDad::ExpDad;
    int Eval();
};
class FuncRParams {
  public:
    ExpList *SonExpList;
    FuncRParams(ExpList *a);
    void Dump();
};
class ExpList {
  public:
    vector<Exp *> *ListExp;
    ExpList();
    ExpList(Exp *item);
    ExpList(ExpList *old, Exp *item);
    void Dump();
};
class LVal {
  public:
    Name *VarName;
    DynArray *SonArray;
    LVal(Name *a, DynArray *b);
    void Dump();
};
class Cond {
  public:
    CondType Type;
    Exp *Exp1;
    Exp *Exp2;
    Cond *Cond1;
    Cond *Cond2;
    Cond(CondType a, Exp *b, Exp *c, Cond *d, Cond *e);
    void Dump();
};
class ConstExp : public ExpDad {
  public:
    using ExpDad::ExpDad;
    int Eval();
};
class Number {
  public:
    int RawNumber;
    Number(int a);
    void Dump();
};
