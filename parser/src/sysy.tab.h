/* A Bison parser, made by GNU Bison 3.6.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SYSY_2020_COMPILER_FOR_RPI4_PARSER_SRC_SYSY_TAB_H_INCLUDED
# define YY_YY_SYSY_2020_COMPILER_FOR_RPI4_PARSER_SRC_SYSY_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOKEN_identifier = 258,        /* TOKEN_identifier  */
    TOKEN_numeric_constant = 259,  /* TOKEN_numeric_constant  */
    TOKEN_string_constant = 260,   /* TOKEN_string_constant  */
    TOKEN_const = 261,             /* TOKEN_const  */
    TOKEN_int = 262,               /* TOKEN_int  */
    TOKEN_void = 263,              /* TOKEN_void  */
    TOKEN_if = 264,                /* TOKEN_if  */
    TOKEN_else = 265,              /* TOKEN_else  */
    TOKEN_while = 266,             /* TOKEN_while  */
    TOKEN_break = 267,             /* TOKEN_break  */
    TOKEN_continue = 268,          /* TOKEN_continue  */
    TOKEN_return = 269,            /* TOKEN_return  */
    TOKEN_comma = 270,             /* TOKEN_comma  */
    TOKEN_semi = 271,              /* TOKEN_semi  */
    TOKEN_l_brace = 272,           /* TOKEN_l_brace  */
    TOKEN_l_paren = 273,           /* TOKEN_l_paren  */
    TOKEN_l_square = 274,          /* TOKEN_l_square  */
    TOKEN_r_brace = 275,           /* TOKEN_r_brace  */
    TOKEN_r_paren = 276,           /* TOKEN_r_paren  */
    TOKEN_r_square = 277,          /* TOKEN_r_square  */
    TOKEN_equal = 278,             /* TOKEN_equal  */
    TOKEN_exclaim = 279,           /* TOKEN_exclaim  */
    TOKEN_ampamp = 280,            /* TOKEN_ampamp  */
    TOKEN_pipepipe = 281,          /* TOKEN_pipepipe  */
    TOKEN_equalequal = 282,        /* TOKEN_equalequal  */
    TOKEN_exclaimequal = 283,      /* TOKEN_exclaimequal  */
    TOKEN_less = 284,              /* TOKEN_less  */
    TOKEN_greater = 285,           /* TOKEN_greater  */
    TOKEN_lessequal = 286,         /* TOKEN_lessequal  */
    TOKEN_greaterequal = 287,      /* TOKEN_greaterequal  */
    TOKEN_plus = 288,              /* TOKEN_plus  */
    TOKEN_minus = 289,             /* TOKEN_minus  */
    TOKEN_star = 290,              /* TOKEN_star  */
    TOKEN_slash = 291,             /* TOKEN_slash  */
    TOKEN_percent = 292,           /* TOKEN_percent  */
    TOKEN_eof = 293,               /* TOKEN_eof  */
    TOKEN_error = 294              /* TOKEN_error  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define TOKEN_identifier 258
#define TOKEN_numeric_constant 259
#define TOKEN_string_constant 260
#define TOKEN_const 261
#define TOKEN_int 262
#define TOKEN_void 263
#define TOKEN_if 264
#define TOKEN_else 265
#define TOKEN_while 266
#define TOKEN_break 267
#define TOKEN_continue 268
#define TOKEN_return 269
#define TOKEN_comma 270
#define TOKEN_semi 271
#define TOKEN_l_brace 272
#define TOKEN_l_paren 273
#define TOKEN_l_square 274
#define TOKEN_r_brace 275
#define TOKEN_r_paren 276
#define TOKEN_r_square 277
#define TOKEN_equal 278
#define TOKEN_exclaim 279
#define TOKEN_ampamp 280
#define TOKEN_pipepipe 281
#define TOKEN_equalequal 282
#define TOKEN_exclaimequal 283
#define TOKEN_less 284
#define TOKEN_greater 285
#define TOKEN_lessequal 286
#define TOKEN_greaterequal 287
#define TOKEN_plus 288
#define TOKEN_minus 289
#define TOKEN_star 290
#define TOKEN_slash 291
#define TOKEN_percent 292
#define TOKEN_eof 293
#define TOKEN_error 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"

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

#line 179 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYSY_2020_COMPILER_FOR_RPI4_PARSER_SRC_SYSY_TAB_H_INCLUDED  */
