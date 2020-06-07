
/**
 * @author ZoneLikeWonderland
 * @email zhanglw2@shanghaitech.edu.cn
 * @create date 2020-05-20 17:45:00
 * @modify date 2020-05-21 10:28:08
 * @desc yacc for sysy
 */

%{
#include <stdio.h>
#include <stdarg.h>
#include <getopt.h>
#include "sysy_parse.hpp"
int yyerror(const char *, ...);
extern int yylex();
extern int yyparse();
CompUnit* ROOT;
%}

%union {
  char* raw_str;
  int raw_int;
  char *raw_symbol;
  const char *error_msg;
CompUnit* PtrCompUnit;
Decl* PtrDecl;
ConstDecl* PtrConstDecl;
ConstDefList* PtrConstDefList;
ConstDef* PtrConstDef;
Array* PtrArray;
ConstInitVal* PtrConstInitVal;
ConstInitValList* PtrConstInitValList;
VarDecl* PtrVarDecl;
VarDefList* PtrVarDefList;
VarDef* PtrVarDef;
InitVal* PtrInitVal;;
InitValList* PtrInitValList;
FuncDef* PtrFuncDef;
FuncFParams* PtrFuncFParams;
FuncFParam* PtrFuncFParam;
DynArray* PtrDynArray;
Block* PtrBlock;
BlockItem* PtrBlockItem;
BlockItemList* PtrBlockItemList;
Stmt* PtrStmt;
Exp* PtrExp;
FuncRParams* PtrFuncRParams;
ExpList* PtrExpList;
LVal* PtrLVal;
Cond* PtrCond;
ConstExp* PtrConstExp;
Number* PtrNumber;
}

/* declare tokens */
%token <raw_symbol> TOKEN_identifier
%token <raw_int> TOKEN_numeric_constant
%token <raw_str> TOKEN_string_constant
%token TOKEN_const
%token TOKEN_int
%token TOKEN_void
%token TOKEN_if
%token TOKEN_else
%token TOKEN_while
%token TOKEN_break
%token TOKEN_continue
%token TOKEN_return
%token TOKEN_comma
%token TOKEN_semi
%token TOKEN_l_brace
%token TOKEN_l_paren
%token TOKEN_l_square
%token TOKEN_r_brace
%token TOKEN_r_paren
%token TOKEN_r_square
%token TOKEN_equal
%token TOKEN_exclaim
%token TOKEN_ampamp
%token TOKEN_pipepipe
%token TOKEN_equalequal
%token TOKEN_exclaimequal
%token TOKEN_less
%token TOKEN_greater
%token TOKEN_lessequal
%token TOKEN_greaterequal
%token TOKEN_plus
%token TOKEN_minus
%token TOKEN_star
%token TOKEN_slash
%token TOKEN_percent
%token TOKEN_eof
%token TOKEN_error


%type <PtrArray> Array
%type <PtrBlock> Block
%type <PtrBlockItem> BlockItem
%type <PtrBlockItemList> BlockItemList
%type <PtrCompUnit> CompUnit
%type <PtrCond> Cond
%type <PtrConstDecl> ConstDecl
%type <PtrConstDef> ConstDef
%type <PtrConstDefList> ConstDefList
%type <PtrConstExp> ConstExp
%type <PtrConstInitVal> ConstInitVal
%type <PtrConstInitValList> ConstInitValList
%type <PtrDecl> Decl
%type <PtrDynArray> DynArray
%type <PtrExp> Exp
%type <PtrExpList> ExpList
%type <PtrFuncDef> FuncDef
%type <PtrFuncFParam> FuncFParam
%type <PtrFuncFParams> FuncFParams
%type <PtrFuncRParams> FuncRParams
%type <PtrInitVal> InitVal
%type <PtrInitValList> InitValList
%type <PtrLVal> LVal
%type <PtrStmt> MatchedStmt
%type <PtrNumber> Number
%type <PtrStmt> OpenStmt
%type <PtrStmt> Stmt
%type <PtrVarDecl> VarDecl
%type <PtrVarDef> VarDef
%type <PtrVarDefList> VarDefList



%nonassoc TOKEN_ampamp TOKEN_pipepipe
%nonassoc TOKEN_equalequal TOKEN_exclaimequal TOKEN_less TOKEN_greater TOKEN_lessequal TOKEN_greaterequal 
%left TOKEN_plus TOKEN_minus 
%left TOKEN_star TOKEN_slash TOKEN_percent 
%right TOKEN_exclaim 


%%
Program         : CompUnit
                {ROOT=$1;}


CompUnit        : CompUnit    Decl
                {$$=new CompUnit($1,$2);}
                | CompUnit FuncDef 
                {$$=new CompUnit($1,$2);}
                | Decl
                {$$=new CompUnit($1);}
                | FuncDef
                {$$=new CompUnit($1);}

Decl            : ConstDecl 
                {$$=$1;}
                | VarDecl 
                {$$=$1;}

ConstDecl       : TOKEN_const TOKEN_int ConstDefList TOKEN_semi
                {$$=new ConstDecl($3);}

ConstDefList    : ConstDef
                {$$=new ConstDefList($1);}
                | ConstDefList TOKEN_comma ConstDef 
                {$$=new ConstDefList($1,$3);}

ConstDef        : TOKEN_identifier Array TOKEN_equal ConstInitVal
                {$$=new ConstDef(new Name($1),$2,$4);}

Array           : Array TOKEN_l_square ConstExp TOKEN_r_square
                {$$=new Array($1,$3);}
                |
                {$$=new Array();}

ConstInitVal    : ConstExp  
                {$$=new ConstInitVal(INITEXP,$1,nullptr);}
                | TOKEN_l_brace ConstInitValList TOKEN_r_brace
                {$$=new ConstInitVal(INITLIST,nullptr,$2);}

ConstInitValList: ConstInitVal 
                {$$=new ConstInitValList($1);}
                | ConstInitValList TOKEN_comma ConstInitVal 
                {$$=new ConstInitValList($1,$3);}
                |
                {$$=new ConstInitValList();}

VarDecl         : TOKEN_int VarDefList TOKEN_semi
                {$$=new VarDecl($2);}

VarDefList      : VarDef 
                {$$=new VarDefList($1);}
                | VarDefList TOKEN_comma VarDef 
                {$$=new VarDefList($1,$3);}

VarDef          : TOKEN_identifier Array 
                {$$=new VarDef(new Name($1),$2,nullptr);}
                | TOKEN_identifier Array TOKEN_equal InitVal
                {$$=new VarDef(new Name($1),$2,$4);}

InitVal         : Exp
                {$$=new InitVal(INITEXP,$1,nullptr);}
                | TOKEN_l_brace InitValList TOKEN_r_brace
                {$$=new InitVal(INITLIST,nullptr,$2);}

InitValList     : InitVal 
                {$$=new InitValList($1);}
                | InitValList TOKEN_comma InitVal 
                {$$=new InitValList($1,$3);}
                |
                {$$=new InitValList();}

FuncDef         : TOKEN_void TOKEN_identifier TOKEN_l_paren FuncFParams TOKEN_r_paren  Block
                {$$=new FuncDef(VOID,new Name($2),$4,$6);}
                | TOKEN_int TOKEN_identifier TOKEN_l_paren FuncFParams TOKEN_r_paren  Block
                {$$=new FuncDef(INT,new Name($2),$4,$6);}

FuncFParams     : FuncFParam 
                {$$=new FuncFParams($1);}
                | FuncFParams  TOKEN_comma  FuncFParam 
                {$$=new FuncFParams($1,$3);}
                |
                {$$=new FuncFParams();}

FuncFParam      : TOKEN_int TOKEN_identifier 
                {$$=new FuncFParam(new Name($2),nullptr);}
                | TOKEN_int TOKEN_identifier TOKEN_l_square TOKEN_r_square DynArray
                {$$=new FuncFParam(new Name($2),$5);}

DynArray        : DynArray TOKEN_l_square Exp TOKEN_r_square 
                {$$=new DynArray($1,$3);}
                |
                {$$=new DynArray();}

Block           : TOKEN_l_brace  BlockItemList TOKEN_r_brace
                {$$=new Block($2);}

BlockItemList   : BlockItemList BlockItem
                {$$=new BlockItemList($1,$2);}
                |
                {$$=new BlockItemList();}

BlockItem       : Decl 
                {$$=new BlockItem(DECL,$1,nullptr);}
                | Stmt
                {$$=new BlockItem(STMT,nullptr,$1);}

Stmt            : MatchedStmt
				| OpenStmt

MatchedStmt     : TOKEN_if  TOKEN_l_paren Cond TOKEN_r_paren  MatchedStmt  TOKEN_else MatchedStmt 
				{$$=new Stmt(IF,$5,$7,nullptr,nullptr,$3,nullptr);}
                | LVal TOKEN_equal Exp TOKEN_semi 
				{$$=new Stmt(ASSIGN,nullptr,nullptr,$1,$3,nullptr,nullptr);}
				| Exp TOKEN_semi 
				{$$=new Stmt(EXP,nullptr,nullptr,nullptr,$1,nullptr,nullptr);}
                | TOKEN_semi
				{$$=new Stmt(EMPTY,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr);}
                | Block
				{$$=new Stmt(BLOCK,nullptr,nullptr,nullptr,nullptr,nullptr,$1);}
				| TOKEN_while TOKEN_l_paren  Cond TOKEN_r_paren  MatchedStmt
				{$$=new Stmt(WHILE,$5,nullptr,nullptr,nullptr,$3,nullptr);}
				| TOKEN_break TOKEN_semi 
				{$$=new Stmt(BREAK,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr);}
                | TOKEN_continue TOKEN_semi
				{$$=new Stmt(CONTINUE,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr);}
				| TOKEN_return Exp TOKEN_semi
				{$$=new Stmt(RET,nullptr,nullptr,nullptr,$2,nullptr,nullptr);}
                | TOKEN_return TOKEN_semi
				{$$=new Stmt(RET,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr);}

OpenStmt        : TOKEN_if  TOKEN_l_paren Cond TOKEN_r_paren  Stmt 
				{$$=new Stmt(IF,$5,nullptr,nullptr,nullptr,$3,nullptr);}
				| TOKEN_if  TOKEN_l_paren Cond TOKEN_r_paren  MatchedStmt  TOKEN_else OpenStmt
				{$$=new Stmt(IF,$5,$7,nullptr,nullptr,$3,nullptr);}
				| TOKEN_while TOKEN_l_paren  Cond TOKEN_r_paren  OpenStmt 
				{$$=new Stmt(WHILE,$5,nullptr,nullptr,nullptr,$3,nullptr);}

Exp             : Exp TOKEN_plus  Exp
                {$$=new Exp(PLUS,$1,$3,nullptr,nullptr,nullptr,nullptr);}
                | Exp TOKEN_minus  Exp
                {$$=new Exp(MINUS,$1,$3,nullptr,nullptr,nullptr,nullptr);}
                | Exp TOKEN_star  Exp
                {$$=new Exp(MUL,$1,$3,nullptr,nullptr,nullptr,nullptr);}
                | Exp TOKEN_slash  Exp
                {$$=new Exp(DIV,$1,$3,nullptr,nullptr,nullptr,nullptr);}
                | Exp TOKEN_percent Exp
                {$$=new Exp(MOD,$1,$3,nullptr,nullptr,nullptr,nullptr);}
				| TOKEN_plus Exp 
                {$$=new Exp(POS,$2,nullptr,nullptr,nullptr,nullptr,nullptr);}
				| TOKEN_minus Exp 
                {$$=new Exp(NEG,$2,nullptr,nullptr,nullptr,nullptr,nullptr);}
                | TOKEN_l_paren  Exp TOKEN_r_paren 
                {$$=new Exp(SUBEXP,$2,nullptr,nullptr,nullptr,nullptr,nullptr);}
				| LVal 
                {$$=new Exp(LVAL,nullptr,nullptr,$1,nullptr,nullptr,nullptr);}
                | TOKEN_identifier TOKEN_l_paren  FuncRParams TOKEN_r_paren  
                {$$=new Exp(CALL,nullptr,nullptr,nullptr,new Name($1),$3,nullptr);}
                | Number
                {$$=new Exp(INTEGER,nullptr,nullptr,nullptr,nullptr,nullptr,$1);}

FuncRParams     : ExpList
                {$$=new FuncRParams($1);}

ExpList         : Exp
                {$$=new ExpList($1);}
                | ExpList TOKEN_comma Exp 
                {$$=new ExpList($1,$3);}
                |
                {$$=new ExpList();}

LVal            : TOKEN_identifier DynArray
                {$$=new LVal(new Name($1),$2);}

Cond            : Exp TOKEN_equalequal  Exp
                {$$=new Cond(EQ,$1,$3,nullptr,nullptr);}
                | Exp TOKEN_exclaimequal  Exp
                {$$=new Cond(NE,$1,$3,nullptr,nullptr);}
                | Exp TOKEN_less  Exp
                {$$=new Cond(LT,$1,$3,nullptr,nullptr);}
                | Exp TOKEN_greater  Exp
                {$$=new Cond(GT,$1,$3,nullptr,nullptr);}
                | Exp TOKEN_lessequal  Exp
                {$$=new Cond(LE,$1,$3,nullptr,nullptr);}
                | Exp TOKEN_greaterequal Exp
                {$$=new Cond(GE,$1,$3,nullptr,nullptr);}
				| TOKEN_l_paren  Cond TOKEN_r_paren  
                {$$=new Cond(SUBCOND,nullptr,nullptr,$2,nullptr);}
                | TOKEN_exclaim  Cond
                {$$=new Cond(NOT,nullptr,nullptr,$2,nullptr);}
				| Cond TOKEN_ampamp  Cond 
                {$$=new Cond(AND,nullptr,nullptr,$1,$3);}
                | Cond TOKEN_pipepipe  Cond
                {$$=new Cond(OR,nullptr,nullptr,$1,$3);}

ConstExp        : ConstExp TOKEN_plus  ConstExp
                {$$=new ConstExp(PLUS,$1,$3,nullptr,nullptr,nullptr,nullptr);}
                | ConstExp TOKEN_minus  ConstExp
                {$$=new ConstExp(MINUS,$1,$3,nullptr,nullptr,nullptr,nullptr);}
                | ConstExp TOKEN_star  ConstExp
                {$$=new ConstExp(MUL,$1,$3,nullptr,nullptr,nullptr,nullptr);}
                | ConstExp TOKEN_slash  ConstExp
                {$$=new ConstExp(DIV,$1,$3,nullptr,nullptr,nullptr,nullptr);}
                | ConstExp TOKEN_percent ConstExp
                {$$=new ConstExp(MOD,$1,$3,nullptr,nullptr,nullptr,nullptr);}
				| TOKEN_plus ConstExp 
                {$$=new ConstExp(POS,$2,nullptr,nullptr,nullptr,nullptr,nullptr);}
				| TOKEN_minus ConstExp 
                {$$=new ConstExp(NEG,$2,nullptr,nullptr,nullptr,nullptr,nullptr);}
                | TOKEN_l_paren  ConstExp TOKEN_r_paren 
                {$$=new ConstExp(SUBEXP,$2,nullptr,nullptr,nullptr,nullptr,nullptr);}
				| Number
                {$$=new ConstExp(INTEGER,nullptr,nullptr,nullptr,nullptr,nullptr,$1);}

Number          : TOKEN_numeric_constant
                {$$=new Number($1);}


%%

int main(int argc, char** argv)
{ 
    char opt;
    while ((opt = getopt(argc, argv, "d")) != -1)
    {
        if(opt=='d')
        yydebug=1;
    }
    yyparse();
    ROOT->Dump();
    return 0;
}
int yyerror(const char *s, ...)
{
    int ret;
    va_list va;
    va_start(va, s);
    ret = vfprintf(stderr, s, va);
    va_end(va);
    return ret;
}
=======
/* Zonelikewonderland */

%{
#include <stdio.h>
#include <stdarg.h>
int yyerror(const char *, ...);
extern int yylex();
extern int yyparse();
%}

%union {
    int raw_int;
  const char *raw_symbol;
  const char *error_msg;
}

/* declare tokens */
%token TOKEN_identifier
%token TOKEN_numeric_constant
%token TOKEN_const
%token TOKEN_int
%token TOKEN_void
%token TOKEN_if
%token TOKEN_else
%token TOKEN_while
%token TOKEN_break
%token TOKEN_continue
%token TOKEN_return
%token TOKEN_comma
%token TOKEN_semi
%token TOKEN_l_brace
%token TOKEN_l_paren
%token TOKEN_l_square
%token TOKEN_r_brace
%token TOKEN_r_paren
%token TOKEN_r_square
%token TOKEN_equal
%token TOKEN_exclaim
%token TOKEN_ampamp
%token TOKEN_pipepipe
%token TOKEN_equalequal
%token TOKEN_exclaimequal
%token TOKEN_less
%token TOKEN_greater
%token TOKEN_lessequal
%token TOKEN_greaterequal
%token TOKEN_plus
%token TOKEN_minus
%token TOKEN_star
%token TOKEN_slash
%token TOKEN_percent
%token TOKEN_eof
%token TOKEN_error
 
%nonassoc TOKEN_ampamp TOKEN_pipepipe
%nonassoc TOKEN_equalequal TOKEN_exclaimequal TOKEN_less TOKEN_greater TOKEN_lessequal TOKEN_greaterequal 
%left TOKEN_plus TOKEN_minus 
%left TOKEN_star TOKEN_slash TOKEN_percent 
%right TOKEN_exclaim 


%%

CompUnit        : CompUnit    Decl  
                | CompUnit FuncDef 
                | Decl
                | FuncDef
                ;

Decl            : ConstDecl 
                | VarDecl 
                ;

ConstDecl       : TOKEN_const TOKEN_int ConstDefList TOKEN_semi
                ;

ConstDefList    : ConstDef 
                | ConstDef TOKEN_comma ConstDefList 

ConstDef        : TOKEN_identifier Array TOKEN_equal ConstInitVal

Array           : TOKEN_l_square ConstExp TOKEN_r_square Array
                |
                ;

ConstInitVal    : ConstExp  
                | TOKEN_l_brace ConstInitValList TOKEN_r_brace

ConstInitValList: ConstInitVal 
                | ConstInitVal TOKEN_comma ConstInitValList 
                |
                ;

VarDecl         : TOKEN_int VarDef VarDefList TOKEN_semi

VarDefList      : VarDef 
                | VarDef TOKEN_comma VarDefList 
                |
                ;

VarDef          : TOKEN_identifier Array 
                | TOKEN_identifier Array TOKEN_equal InitVal
                ;

InitVal         : Exp
                | TOKEN_l_brace InitValList TOKEN_r_brace

InitValList  : InitVal 
                | InitVal TOKEN_comma InitValList 
                |
                ;

FuncDef         : TOKEN_void TOKEN_identifier TOKEN_l_paren FuncFParams TOKEN_r_paren  Block
                | TOKEN_int TOKEN_identifier TOKEN_l_paren FuncFParams TOKEN_r_paren  Block
                ;

FuncFParams     : FuncFParam 
                | FuncFParam  TOKEN_comma  FuncFParam 
                |
                ;

FuncFParam      : TOKEN_int TOKEN_identifier 
                | TOKEN_int TOKEN_identifier TOKEN_l_square TOKEN_r_square DynArray
                ;

DynArray        : TOKEN_l_square Exp TOKEN_r_square DynArray
                |
                ;

Block           : TOKEN_l_brace  BlockItemList TOKEN_r_brace
                ;

BlockItemList   : BlockItem BlockItemList
                |
                ;

BlockItem       : Decl 
                | Stmt
                ;

Stmt            : MatchedStmt
				| OpenStmt
                ;

MatchedStmt     : TOKEN_if  TOKEN_l_paren Cond TOKEN_r_paren  MatchedStmt  TOKEN_else MatchedStmt 
				| LVal TOKEN_equal Exp TOKEN_semi 
				| Exp TOKEN_semi 
                | Block
				| TOKEN_while TOKEN_l_paren  Cond TOKEN_r_paren  MatchedStmt
				| TOKEN_break TOKEN_semi 
                | TOKEN_continue TOKEN_semi
				| TOKEN_return Exp TOKEN_semi
                | TOKEN_return TOKEN_semi
                ;

OpenStmt        : TOKEN_if  TOKEN_l_paren Cond TOKEN_r_paren  Stmt 
				| TOKEN_if  TOKEN_l_paren Cond TOKEN_r_paren  MatchedStmt  TOKEN_else OpenStmt
				| TOKEN_while TOKEN_l_paren  Cond TOKEN_r_paren  OpenStmt
                ; 
				

Exp             : Exp TOKEN_plus  Exp
                | Exp TOKEN_minus  Exp
                | Exp TOKEN_star  Exp
                | Exp TOKEN_slash  Exp
                | Exp TOKEN_percent Exp
				| TOKEN_plus Exp 
				| TOKEN_minus Exp 
                | TOKEN_l_paren  Exp TOKEN_r_paren 
				| LVal 
                | TOKEN_identifier TOKEN_l_paren  FuncRParams TOKEN_r_paren  
                | Number
                ;

FuncRParams     : ExpList
                ;

ExpList         : Exp
                | Exp TOKEN_comma ExpList 
                ;

LVal            : TOKEN_identifier DynArray
                ;

Cond            : Exp TOKEN_equalequal  Exp
                | Exp TOKEN_exclaimequal  Exp
                | Exp TOKEN_less  Exp
                | Exp TOKEN_greater  Exp
                | Exp TOKEN_lessequal  Exp
                | Exp TOKEN_greaterequal Exp
				| TOKEN_l_paren  Cond TOKEN_r_paren  
                | TOKEN_exclaim  Cond
				| Cond TOKEN_ampamp  Cond 
                | Cond TOKEN_pipepipe  Cond
                ;

ConstExp        : ConstExp TOKEN_plus  ConstExp
                | ConstExp TOKEN_minus  ConstExp
                | ConstExp TOKEN_star  ConstExp
                | ConstExp TOKEN_slash  ConstExp
                | ConstExp TOKEN_percent ConstExp
				| TOKEN_plus ConstExp 
				| TOKEN_minus ConstExp 
                | TOKEN_l_paren  ConstExp TOKEN_r_paren 
				| Number
                ;

Number          : TOKEN_numeric_constant
                ;


%%

int main()
{ 
    yyparse();
    return 0;
}
int yyerror(const char *s, ...)
{
    int ret;
    va_list va;
    va_start(va, s);
    ret = vfprintf(stderr, s, va);
    va_end(va);
    return ret;
}

