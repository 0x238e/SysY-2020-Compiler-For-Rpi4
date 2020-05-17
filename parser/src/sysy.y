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
