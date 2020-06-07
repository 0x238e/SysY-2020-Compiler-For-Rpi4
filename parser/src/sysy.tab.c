/* A Bison parser, made by GNU Bison 3.6.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.6.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 9 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"

#include <stdio.h>
#include <stdarg.h>
#include <getopt.h>
#include "sysy_parse.hpp"
int yyerror(const char *, ...);
extern int yylex();
extern int yyparse();
CompUnit* ROOT;

#line 82 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 247 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYSY_2020_COMPILER_FOR_RPI4_PARSER_SRC_SYSY_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOKEN_identifier = 3,           /* TOKEN_identifier  */
  YYSYMBOL_TOKEN_numeric_constant = 4,     /* TOKEN_numeric_constant  */
  YYSYMBOL_TOKEN_string_constant = 5,      /* TOKEN_string_constant  */
  YYSYMBOL_TOKEN_const = 6,                /* TOKEN_const  */
  YYSYMBOL_TOKEN_int = 7,                  /* TOKEN_int  */
  YYSYMBOL_TOKEN_void = 8,                 /* TOKEN_void  */
  YYSYMBOL_TOKEN_if = 9,                   /* TOKEN_if  */
  YYSYMBOL_TOKEN_else = 10,                /* TOKEN_else  */
  YYSYMBOL_TOKEN_while = 11,               /* TOKEN_while  */
  YYSYMBOL_TOKEN_break = 12,               /* TOKEN_break  */
  YYSYMBOL_TOKEN_continue = 13,            /* TOKEN_continue  */
  YYSYMBOL_TOKEN_return = 14,              /* TOKEN_return  */
  YYSYMBOL_TOKEN_comma = 15,               /* TOKEN_comma  */
  YYSYMBOL_TOKEN_semi = 16,                /* TOKEN_semi  */
  YYSYMBOL_TOKEN_l_brace = 17,             /* TOKEN_l_brace  */
  YYSYMBOL_TOKEN_l_paren = 18,             /* TOKEN_l_paren  */
  YYSYMBOL_TOKEN_l_square = 19,            /* TOKEN_l_square  */
  YYSYMBOL_TOKEN_r_brace = 20,             /* TOKEN_r_brace  */
  YYSYMBOL_TOKEN_r_paren = 21,             /* TOKEN_r_paren  */
  YYSYMBOL_TOKEN_r_square = 22,            /* TOKEN_r_square  */
  YYSYMBOL_TOKEN_equal = 23,               /* TOKEN_equal  */
  YYSYMBOL_TOKEN_exclaim = 24,             /* TOKEN_exclaim  */
  YYSYMBOL_TOKEN_ampamp = 25,              /* TOKEN_ampamp  */
  YYSYMBOL_TOKEN_pipepipe = 26,            /* TOKEN_pipepipe  */
  YYSYMBOL_TOKEN_equalequal = 27,          /* TOKEN_equalequal  */
  YYSYMBOL_TOKEN_exclaimequal = 28,        /* TOKEN_exclaimequal  */
  YYSYMBOL_TOKEN_less = 29,                /* TOKEN_less  */
  YYSYMBOL_TOKEN_greater = 30,             /* TOKEN_greater  */
  YYSYMBOL_TOKEN_lessequal = 31,           /* TOKEN_lessequal  */
  YYSYMBOL_TOKEN_greaterequal = 32,        /* TOKEN_greaterequal  */
  YYSYMBOL_TOKEN_plus = 33,                /* TOKEN_plus  */
  YYSYMBOL_TOKEN_minus = 34,               /* TOKEN_minus  */
  YYSYMBOL_TOKEN_star = 35,                /* TOKEN_star  */
  YYSYMBOL_TOKEN_slash = 36,               /* TOKEN_slash  */
  YYSYMBOL_TOKEN_percent = 37,             /* TOKEN_percent  */
  YYSYMBOL_TOKEN_eof = 38,                 /* TOKEN_eof  */
  YYSYMBOL_TOKEN_error = 39,               /* TOKEN_error  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_Program = 41,                   /* Program  */
  YYSYMBOL_CompUnit = 42,                  /* CompUnit  */
  YYSYMBOL_Decl = 43,                      /* Decl  */
  YYSYMBOL_ConstDecl = 44,                 /* ConstDecl  */
  YYSYMBOL_ConstDefList = 45,              /* ConstDefList  */
  YYSYMBOL_ConstDef = 46,                  /* ConstDef  */
  YYSYMBOL_Array = 47,                     /* Array  */
  YYSYMBOL_ConstInitVal = 48,              /* ConstInitVal  */
  YYSYMBOL_ConstInitValList = 49,          /* ConstInitValList  */
  YYSYMBOL_VarDecl = 50,                   /* VarDecl  */
  YYSYMBOL_VarDefList = 51,                /* VarDefList  */
  YYSYMBOL_VarDef = 52,                    /* VarDef  */
  YYSYMBOL_InitVal = 53,                   /* InitVal  */
  YYSYMBOL_InitValList = 54,               /* InitValList  */
  YYSYMBOL_FuncDef = 55,                   /* FuncDef  */
  YYSYMBOL_FuncFParams = 56,               /* FuncFParams  */
  YYSYMBOL_FuncFParam = 57,                /* FuncFParam  */
  YYSYMBOL_DynArray = 58,                  /* DynArray  */
  YYSYMBOL_Block = 59,                     /* Block  */
  YYSYMBOL_BlockItemList = 60,             /* BlockItemList  */
  YYSYMBOL_BlockItem = 61,                 /* BlockItem  */
  YYSYMBOL_Stmt = 62,                      /* Stmt  */
  YYSYMBOL_MatchedStmt = 63,               /* MatchedStmt  */
  YYSYMBOL_OpenStmt = 64,                  /* OpenStmt  */
  YYSYMBOL_Exp = 65,                       /* Exp  */
  YYSYMBOL_FuncRParams = 66,               /* FuncRParams  */
  YYSYMBOL_ExpList = 67,                   /* ExpList  */
  YYSYMBOL_LVal = 68,                      /* LVal  */
  YYSYMBOL_Cond = 69,                      /* Cond  */
  YYSYMBOL_ConstExp = 70,                  /* ConstExp  */
  YYSYMBOL_Number = 71                     /* Number  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   271

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  180

#define YYMAXUTOK   294


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINEYYN -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   136,   136,   140,   142,   144,   146,   149,   151,   154,
     157,   159,   162,   165,   168,   170,   172,   175,   177,   180,
     182,   185,   187,   190,   192,   195,   197,   200,   202,   205,
     207,   209,   212,   214,   217,   219,   221,   224,   227,   229,
     232,   235,   237,   239,   242,   243,   245,   247,   249,   251,
     253,   255,   257,   259,   261,   263,   266,   268,   270,   273,
     275,   277,   279,   281,   283,   285,   287,   289,   291,   293,
     296,   299,   301,   304,   306,   309,   311,   313,   315,   317,
     319,   321,   323,   325,   327,   330,   332,   334,   336,   338,
     340,   342,   344,   346,   349
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_identifier",
  "TOKEN_numeric_constant", "TOKEN_string_constant", "TOKEN_const",
  "TOKEN_int", "TOKEN_void", "TOKEN_if", "TOKEN_else", "TOKEN_while",
  "TOKEN_break", "TOKEN_continue", "TOKEN_return", "TOKEN_comma",
  "TOKEN_semi", "TOKEN_l_brace", "TOKEN_l_paren", "TOKEN_l_square",
  "TOKEN_r_brace", "TOKEN_r_paren", "TOKEN_r_square", "TOKEN_equal",
  "TOKEN_exclaim", "TOKEN_ampamp", "TOKEN_pipepipe", "TOKEN_equalequal",
  "TOKEN_exclaimequal", "TOKEN_less", "TOKEN_greater", "TOKEN_lessequal",
  "TOKEN_greaterequal", "TOKEN_plus", "TOKEN_minus", "TOKEN_star",
  "TOKEN_slash", "TOKEN_percent", "TOKEN_eof", "TOKEN_error", "$accept",
  "Program", "CompUnit", "Decl", "ConstDecl", "ConstDefList", "ConstDef",
  "Array", "ConstInitVal", "ConstInitValList", "VarDecl", "VarDefList",
  "VarDef", "InitVal", "InitValList", "FuncDef", "FuncFParams",
  "FuncFParam", "DynArray", "Block", "BlockItemList", "BlockItem", "Stmt",
  "MatchedStmt", "OpenStmt", "Exp", "FuncRParams", "ExpList", "LVal",
  "Cond", "ConstExp", "Number", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
#endif

#define YYPACT_NINF (-132)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACTSTATE-NUM -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     153,    30,    37,    66,   109,   153,  -132,  -132,  -132,  -132,
     105,    96,    -5,  -132,   110,  -132,  -132,  -132,  -132,    62,
    -132,   130,   108,   151,  -132,   130,   111,   105,  -132,   163,
      -9,  -132,   152,    68,  -132,  -132,    -8,   135,  -132,   136,
     130,   150,  -132,   152,   152,   152,   204,  -132,   146,    68,
      71,    71,    71,  -132,   199,  -132,  -132,   150,   135,  -132,
     225,   154,  -132,  -132,  -132,    82,   170,   170,  -132,   152,
     152,   152,   152,   152,    71,   159,  -132,    15,   188,   192,
     192,    71,    71,    71,    71,    71,  -132,  -132,    91,  -132,
     129,  -132,   170,   170,  -132,  -132,  -132,   199,   158,   168,
      71,    68,  -132,  -132,   192,   192,  -132,  -132,  -132,   135,
    -132,   159,   151,   155,   169,   172,   214,    79,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,   156,   185,  -132,    71,
     209,  -132,  -132,   147,   147,  -132,  -132,  -132,   161,  -132,
      71,   199,  -132,   147,   147,   220,   -17,    17,  -132,   166,
     183,    55,  -132,    71,    71,    71,    71,    71,    71,    11,
     147,   147,    11,  -132,  -132,   199,   199,   199,   199,   199,
     199,  -132,   174,    74,    74,  -132,  -132,    11,  -132,  -132
};

  /* YYDEFACTSTATE-NUM -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     5,     7,     8,     6,
       0,    14,     0,    21,     0,     1,     3,     4,    14,     0,
      10,    34,    23,     0,    20,    34,     0,     0,     9,     0,
       0,    32,     0,     0,    14,    22,     0,     0,    11,    35,
       0,     0,    94,     0,     0,     0,     0,    93,    38,    29,
       0,     0,     0,    24,    25,    67,    69,     0,    19,    12,
      15,     0,    33,    41,    31,     0,    90,    91,    13,     0,
       0,     0,     0,     0,    73,    74,    27,     0,     0,    64,
      65,     0,     0,     0,     0,     0,    30,    17,     0,    38,
       0,    92,    85,    86,    87,    88,    89,    71,     0,    70,
       0,     0,    26,    66,    59,    60,    61,    62,    63,     0,
      16,    36,     0,     0,     0,     0,     0,     0,    49,    39,
      42,    50,    40,    43,    44,    45,     0,    67,    68,     0,
       0,    28,    18,     0,     0,    52,    53,    55,     0,    48,
       0,    72,    37,     0,     0,     0,     0,     0,    54,     0,
       0,     0,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    47,    81,    75,    76,    77,    78,    79,
      80,    56,    44,    83,    84,    51,    58,     0,    46,    57
};

  /* YYPGOTONTERM-NUM.  */
static const yytype_int16 yypgoto[] =
{
    -132,  -132,  -132,    -3,  -132,  -132,   236,   246,   -53,  -132,
    -132,  -132,   242,   -46,  -132,   261,   243,   227,   180,    22,
    -132,  -132,   112,  -123,  -131,   -33,  -132,  -132,   -89,    14,
      21,   -11
};

  /* YYDEFGOTONTERM-NUM.  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    19,    20,    22,    59,    88,
       8,    12,    13,    53,    77,     9,    30,    31,    75,   121,
      90,   122,   123,   124,   125,   145,    98,    99,    55,   146,
      60,    56
};

  /* YYTABLEYYPACT[STATE-NUM] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,   127,    16,    76,   159,    87,    40,    40,   160,   161,
      23,    24,    41,    57,    48,    42,    54,    78,    79,    80,
     113,    47,   114,   115,   116,   117,    47,   118,    63,    50,
     101,   176,    47,    47,    47,   102,   172,    10,   162,   175,
      11,    97,   160,   161,    51,    52,   179,    47,   104,   105,
     106,   107,   108,    46,   178,   131,   132,   126,    47,    47,
      47,    47,    47,    64,    65,    66,    67,   130,    54,    14,
     127,    48,    42,   127,    48,    42,   164,    27,    28,    86,
     160,   161,    48,    42,   138,    49,    50,   120,   127,    50,
      92,    93,    94,    95,    96,   137,   141,    50,    47,    -1,
      -1,    51,    52,    91,    51,    52,   109,   149,    18,    15,
     150,   110,    51,    52,    21,    69,    70,    71,    72,    73,
     165,   166,   167,   168,   169,   170,   126,    32,    25,   126,
      32,    33,    48,    42,    37,     1,   112,    29,   113,    42,
     114,   115,   116,   117,   126,   118,    63,    50,   147,   119,
      48,    42,    58,    43,    34,    61,    42,   151,   152,     1,
       2,     3,    51,    52,    74,   143,    39,    63,    44,    45,
      43,   144,   139,   133,   173,   174,    89,   148,   100,   128,
      51,    52,   163,   129,   177,    44,    45,   134,   135,    81,
      82,    83,    84,    85,    81,    82,    83,    84,    85,    81,
      82,    83,    84,    85,   103,    71,    72,    73,   140,   103,
     153,   154,   155,   156,   157,   158,    81,    82,    83,    84,
      85,    81,    82,    83,    84,    85,    68,    83,    84,    85,
     136,   142,    81,    82,    83,    84,    85,    69,    70,    71,
      72,    73,    81,    82,    83,    84,    85,   153,   154,   155,
     156,   157,   158,    81,    82,    83,    84,    85,    69,    70,
      71,    72,    73,    38,    26,    35,    17,    62,    36,   111,
       0,   171
};

static const yytype_int16 yycheck[] =
{
      33,    90,     5,    49,    21,    58,    15,    15,    25,    26,
      15,    16,    21,    21,     3,     4,    49,    50,    51,    52,
       9,    32,    11,    12,    13,    14,    37,    16,    17,    18,
      15,   162,    43,    44,    45,    20,   159,     7,    21,   162,
       3,    74,    25,    26,    33,    34,   177,    58,    81,    82,
      83,    84,    85,    32,   177,   101,   109,    90,    69,    70,
      71,    72,    73,    41,    43,    44,    45,   100,   101,     3,
     159,     3,     4,   162,     3,     4,    21,    15,    16,    57,
      25,    26,     3,     4,   117,    17,    18,    90,   177,    18,
      69,    70,    71,    72,    73,    16,   129,    18,   109,    25,
      26,    33,    34,    21,    33,    34,    15,   140,     3,     0,
     143,    20,    33,    34,    18,    33,    34,    35,    36,    37,
     153,   154,   155,   156,   157,   158,   159,    19,    18,   162,
      19,    23,     3,     4,    23,     6,     7,     7,     9,     4,
      11,    12,    13,    14,   177,    16,    17,    18,   134,    20,
       3,     4,    17,    18,     3,    19,     4,   143,   144,     6,
       7,     8,    33,    34,    18,    18,     3,    17,    33,    34,
      18,    24,    16,    18,   160,   161,    22,    16,    19,    21,
      33,    34,    16,    15,    10,    33,    34,    18,    16,    33,
      34,    35,    36,    37,    33,    34,    35,    36,    37,    33,
      34,    35,    36,    37,    21,    35,    36,    37,    23,    21,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    33,    34,    35,    36,    37,    22,    35,    36,    37,
      16,    22,    33,    34,    35,    36,    37,    33,    34,    35,
      36,    37,    33,    34,    35,    36,    37,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    33,    34,
      35,    36,    37,    27,    18,    23,     5,    40,    25,    89,
      -1,   159
};

  /* YYSTOSSTATE-NUM -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,     8,    41,    42,    43,    44,    50,    55,
       7,     3,    51,    52,     3,     0,    43,    55,     3,    45,
      46,    18,    47,    15,    16,    18,    47,    15,    16,     7,
      56,    57,    19,    23,     3,    52,    56,    23,    46,     3,
      15,    21,     4,    18,    33,    34,    70,    71,     3,    17,
      18,    33,    34,    53,    65,    68,    71,    21,    17,    48,
      70,    19,    57,    17,    59,    70,    70,    70,    22,    33,
      34,    35,    36,    37,    18,    58,    53,    54,    65,    65,
      65,    33,    34,    35,    36,    37,    59,    48,    49,    22,
      60,    21,    70,    70,    70,    70,    70,    65,    66,    67,
      19,    15,    20,    21,    65,    65,    65,    65,    65,    15,
      20,    58,     7,     9,    11,    12,    13,    14,    16,    20,
      43,    59,    61,    62,    63,    64,    65,    68,    21,    15,
      65,    53,    48,    18,    18,    16,    16,    16,    65,    16,
      23,    65,    22,    18,    24,    65,    69,    69,    16,    65,
      65,    69,    69,    27,    28,    29,    30,    31,    32,    21,
      25,    26,    21,    16,    21,    65,    65,    65,    65,    65,
      65,    62,    63,    69,    69,    63,    64,    10,    63,    64
};

  /* YYR1YYN -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    42,    42,    43,    43,    44,
      45,    45,    46,    47,    47,    48,    48,    49,    49,    49,
      50,    51,    51,    52,    52,    53,    53,    54,    54,    54,
      55,    55,    56,    56,    56,    57,    57,    58,    58,    59,
      60,    60,    61,    61,    62,    62,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    64,    64,    64,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      66,    67,    67,    67,    68,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    71
};

  /* YYR2YYN -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     1,     1,     4,
       1,     3,     4,     4,     0,     1,     3,     1,     3,     0,
       3,     1,     3,     2,     4,     1,     3,     1,     3,     0,
       6,     6,     1,     3,     0,     2,     5,     4,     0,     3,
       2,     0,     1,     1,     1,     1,     7,     4,     2,     1,
       1,     5,     2,     2,     3,     2,     5,     7,     5,     3,
       3,     3,     3,     3,     2,     2,     3,     1,     4,     1,
       1,     1,     3,     0,     2,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     3,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize;

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yynerrs = 0;
  yystate = 0;
  yyerrstatus = 0;

  yystacksize = YYINITDEPTH;
  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;


  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 137 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {ROOT=(yyvsp[0].PtrCompUnit);}
#line 1447 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 3:
#line 141 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrCompUnit)=new CompUnit((yyvsp[-1].PtrCompUnit),(yyvsp[0].PtrDecl));}
#line 1453 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 4:
#line 143 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrCompUnit)=new CompUnit((yyvsp[-1].PtrCompUnit),(yyvsp[0].PtrFuncDef));}
#line 1459 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 5:
#line 145 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrCompUnit)=new CompUnit((yyvsp[0].PtrDecl));}
#line 1465 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 6:
#line 147 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrCompUnit)=new CompUnit((yyvsp[0].PtrFuncDef));}
#line 1471 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 7:
#line 150 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrDecl)=(yyvsp[0].PtrConstDecl);}
#line 1477 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 8:
#line 152 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrDecl)=(yyvsp[0].PtrVarDecl);}
#line 1483 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 9:
#line 155 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrConstDecl)=new ConstDecl((yyvsp[-1].PtrConstDefList));}
#line 1489 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 10:
#line 158 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrConstDefList)=new ConstDefList((yyvsp[0].PtrConstDef));}
#line 1495 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 11:
#line 160 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrConstDefList)=new ConstDefList((yyvsp[-2].PtrConstDefList),(yyvsp[0].PtrConstDef));}
#line 1501 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 12:
#line 163 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrConstDef)=new ConstDef(new Name((yyvsp[-3].raw_symbol)),(yyvsp[-2].PtrArray),(yyvsp[0].PtrConstInitVal));}
#line 1507 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 13:
#line 166 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrArray)=new Array((yyvsp[-3].PtrArray),(yyvsp[-1].PtrConstExp));}
#line 1513 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 14:
#line 168 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrArray)=new Array();}
#line 1519 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 15:
#line 171 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrConstInitVal)=new ConstInitVal(INITEXP,(yyvsp[0].PtrConstExp),nullptr);}
#line 1525 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 16:
#line 173 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrConstInitVal)=new ConstInitVal(INITLIST,nullptr,(yyvsp[-1].PtrConstInitValList));}
#line 1531 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 17:
#line 176 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrConstInitValList)=new ConstInitValList((yyvsp[0].PtrConstInitVal));}
#line 1537 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 18:
#line 178 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrConstInitValList)=new ConstInitValList((yyvsp[-2].PtrConstInitValList),(yyvsp[0].PtrConstInitVal));}
#line 1543 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 19:
#line 180 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrConstInitValList)=new ConstInitValList();}
#line 1549 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 20:
#line 183 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrVarDecl)=new VarDecl((yyvsp[-1].PtrVarDefList));}
#line 1555 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 21:
#line 186 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrVarDefList)=new VarDefList((yyvsp[0].PtrVarDef));}
#line 1561 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 22:
#line 188 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrVarDefList)=new VarDefList((yyvsp[-2].PtrVarDefList),(yyvsp[0].PtrVarDef));}
#line 1567 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 23:
#line 191 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrVarDef)=new VarDef(new Name((yyvsp[-1].raw_symbol)),(yyvsp[0].PtrArray),nullptr);}
#line 1573 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 24:
#line 193 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrVarDef)=new VarDef(new Name((yyvsp[-3].raw_symbol)),(yyvsp[-2].PtrArray),(yyvsp[0].PtrInitVal));}
#line 1579 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 25:
#line 196 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrInitVal)=new InitVal(INITEXP,(yyvsp[0].PtrExp),nullptr);}
#line 1585 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 26:
#line 198 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrInitVal)=new InitVal(INITLIST,nullptr,(yyvsp[-1].PtrInitValList));}
#line 1591 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 27:
#line 201 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrInitValList)=new InitValList((yyvsp[0].PtrInitVal));}
#line 1597 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 28:
#line 203 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrInitValList)=new InitValList((yyvsp[-2].PtrInitValList),(yyvsp[0].PtrInitVal));}
#line 1603 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 29:
#line 205 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrInitValList)=new InitValList();}
#line 1609 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 30:
#line 208 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrFuncDef)=new FuncDef(VOID,new Name((yyvsp[-4].raw_symbol)),(yyvsp[-2].PtrFuncFParams),(yyvsp[0].PtrBlock));}
#line 1615 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 31:
#line 210 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrFuncDef)=new FuncDef(INT,new Name((yyvsp[-4].raw_symbol)),(yyvsp[-2].PtrFuncFParams),(yyvsp[0].PtrBlock));}
#line 1621 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 32:
#line 213 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrFuncFParams)=new FuncFParams((yyvsp[0].PtrFuncFParam));}
#line 1627 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 33:
#line 215 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrFuncFParams)=new FuncFParams((yyvsp[-2].PtrFuncFParams),(yyvsp[0].PtrFuncFParam));}
#line 1633 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 34:
#line 217 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrFuncFParams)=new FuncFParams();}
#line 1639 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 35:
#line 220 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrFuncFParam)=new FuncFParam(new Name((yyvsp[0].raw_symbol)),nullptr);}
#line 1645 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 36:
#line 222 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrFuncFParam)=new FuncFParam(new Name((yyvsp[-3].raw_symbol)),(yyvsp[0].PtrDynArray));}
#line 1651 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 37:
#line 225 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrDynArray)=new DynArray((yyvsp[-3].PtrDynArray),(yyvsp[-1].PtrExp));}
#line 1657 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 38:
#line 227 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrDynArray)=new DynArray();}
#line 1663 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 39:
#line 230 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrBlock)=new Block((yyvsp[-1].PtrBlockItemList));}
#line 1669 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 40:
#line 233 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrBlockItemList)=new BlockItemList((yyvsp[-1].PtrBlockItemList),(yyvsp[0].PtrBlockItem));}
#line 1675 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 41:
#line 235 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrBlockItemList)=new BlockItemList();}
#line 1681 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 42:
#line 238 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrBlockItem)=new BlockItem(DECL,(yyvsp[0].PtrDecl),nullptr);}
#line 1687 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 43:
#line 240 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrBlockItem)=new BlockItem(STMT,nullptr,(yyvsp[0].PtrStmt));}
#line 1693 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 46:
#line 246 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                                {(yyval.PtrStmt)=new Stmt(IF,(yyvsp[-2].PtrStmt),(yyvsp[0].PtrStmt),nullptr,nullptr,(yyvsp[-4].PtrCond),nullptr);}
#line 1699 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 47:
#line 248 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                                {(yyval.PtrStmt)=new Stmt(ASSIGN,nullptr,nullptr,(yyvsp[-3].PtrLVal),(yyvsp[-1].PtrExp),nullptr,nullptr);}
#line 1705 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 48:
#line 250 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                                {(yyval.PtrStmt)=new Stmt(EXP,nullptr,nullptr,nullptr,(yyvsp[-1].PtrExp),nullptr,nullptr);}
#line 1711 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 49:
#line 252 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                                {(yyval.PtrStmt)=new Stmt(EMPTY,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr);}
#line 1717 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 50:
#line 254 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                                {(yyval.PtrStmt)=new Stmt(BLOCK,nullptr,nullptr,nullptr,nullptr,nullptr,(yyvsp[0].PtrBlock));}
#line 1723 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 51:
#line 256 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                                {(yyval.PtrStmt)=new Stmt(WHILE,(yyvsp[0].PtrStmt),nullptr,nullptr,nullptr,(yyvsp[-2].PtrCond),nullptr);}
#line 1729 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 52:
#line 258 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                                {(yyval.PtrStmt)=new Stmt(BREAK,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr);}
#line 1735 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 53:
#line 260 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                                {(yyval.PtrStmt)=new Stmt(CONTINUE,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr);}
#line 1741 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 54:
#line 262 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                                {(yyval.PtrStmt)=new Stmt(RET,nullptr,nullptr,nullptr,(yyvsp[-1].PtrExp),nullptr,nullptr);}
#line 1747 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 55:
#line 264 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                                {(yyval.PtrStmt)=new Stmt(RET,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr);}
#line 1753 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 56:
#line 267 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                                {(yyval.PtrStmt)=new Stmt(IF,(yyvsp[0].PtrStmt),nullptr,nullptr,nullptr,(yyvsp[-2].PtrCond),nullptr);}
#line 1759 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 57:
#line 269 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                                {(yyval.PtrStmt)=new Stmt(IF,(yyvsp[-2].PtrStmt),(yyvsp[0].PtrStmt),nullptr,nullptr,(yyvsp[-4].PtrCond),nullptr);}
#line 1765 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 58:
#line 271 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                                {(yyval.PtrStmt)=new Stmt(WHILE,(yyvsp[0].PtrStmt),nullptr,nullptr,nullptr,(yyvsp[-2].PtrCond),nullptr);}
#line 1771 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 59:
#line 274 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrExp)=new Exp(PLUS,(yyvsp[-2].PtrExp),(yyvsp[0].PtrExp),nullptr,nullptr,nullptr,nullptr);}
#line 1777 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 60:
#line 276 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrExp)=new Exp(MINUS,(yyvsp[-2].PtrExp),(yyvsp[0].PtrExp),nullptr,nullptr,nullptr,nullptr);}
#line 1783 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 61:
#line 278 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrExp)=new Exp(MUL,(yyvsp[-2].PtrExp),(yyvsp[0].PtrExp),nullptr,nullptr,nullptr,nullptr);}
#line 1789 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 62:
#line 280 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrExp)=new Exp(DIV,(yyvsp[-2].PtrExp),(yyvsp[0].PtrExp),nullptr,nullptr,nullptr,nullptr);}
#line 1795 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 63:
#line 282 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrExp)=new Exp(MOD,(yyvsp[-2].PtrExp),(yyvsp[0].PtrExp),nullptr,nullptr,nullptr,nullptr);}
#line 1801 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 64:
#line 284 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrExp)=new Exp(POS,(yyvsp[0].PtrExp),nullptr,nullptr,nullptr,nullptr,nullptr);}
#line 1807 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 65:
#line 286 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrExp)=new Exp(NEG,(yyvsp[0].PtrExp),nullptr,nullptr,nullptr,nullptr,nullptr);}
#line 1813 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 66:
#line 288 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrExp)=new Exp(SUBEXP,(yyvsp[-1].PtrExp),nullptr,nullptr,nullptr,nullptr,nullptr);}
#line 1819 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 67:
#line 290 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrExp)=new Exp(LVAL,nullptr,nullptr,(yyvsp[0].PtrLVal),nullptr,nullptr,nullptr);}
#line 1825 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 68:
#line 292 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrExp)=new Exp(CALL,nullptr,nullptr,nullptr,new Name((yyvsp[-3].raw_symbol)),(yyvsp[-1].PtrFuncRParams),nullptr);}
#line 1831 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 69:
#line 294 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrExp)=new Exp(INTEGER,nullptr,nullptr,nullptr,nullptr,nullptr,(yyvsp[0].PtrNumber));}
#line 1837 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 70:
#line 297 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrFuncRParams)=new FuncRParams((yyvsp[0].PtrExpList));}
#line 1843 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 71:
#line 300 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrExpList)=new ExpList((yyvsp[0].PtrExp));}
#line 1849 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 72:
#line 302 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrExpList)=new ExpList((yyvsp[-2].PtrExpList),(yyvsp[0].PtrExp));}
#line 1855 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 73:
#line 304 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrExpList)=new ExpList();}
#line 1861 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 74:
#line 307 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrLVal)=new LVal(new Name((yyvsp[-1].raw_symbol)),(yyvsp[0].PtrDynArray));}
#line 1867 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 75:
#line 310 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrCond)=new Cond(EQ,(yyvsp[-2].PtrExp),(yyvsp[0].PtrExp),nullptr,nullptr);}
#line 1873 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 76:
#line 312 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrCond)=new Cond(NE,(yyvsp[-2].PtrExp),(yyvsp[0].PtrExp),nullptr,nullptr);}
#line 1879 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 77:
#line 314 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrCond)=new Cond(LT,(yyvsp[-2].PtrExp),(yyvsp[0].PtrExp),nullptr,nullptr);}
#line 1885 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 78:
#line 316 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrCond)=new Cond(GT,(yyvsp[-2].PtrExp),(yyvsp[0].PtrExp),nullptr,nullptr);}
#line 1891 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 79:
#line 318 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrCond)=new Cond(LE,(yyvsp[-2].PtrExp),(yyvsp[0].PtrExp),nullptr,nullptr);}
#line 1897 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 80:
#line 320 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrCond)=new Cond(GE,(yyvsp[-2].PtrExp),(yyvsp[0].PtrExp),nullptr,nullptr);}
#line 1903 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 81:
#line 322 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrCond)=new Cond(SUBCOND,nullptr,nullptr,(yyvsp[-1].PtrCond),nullptr);}
#line 1909 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 82:
#line 324 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrCond)=new Cond(NOT,nullptr,nullptr,(yyvsp[0].PtrCond),nullptr);}
#line 1915 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 83:
#line 326 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrCond)=new Cond(AND,nullptr,nullptr,(yyvsp[-2].PtrCond),(yyvsp[0].PtrCond));}
#line 1921 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 84:
#line 328 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrCond)=new Cond(OR,nullptr,nullptr,(yyvsp[-2].PtrCond),(yyvsp[0].PtrCond));}
#line 1927 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 85:
#line 331 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrConstExp)=new ConstExp(PLUS,(yyvsp[-2].PtrConstExp),(yyvsp[0].PtrConstExp),nullptr,nullptr,nullptr,nullptr);}
#line 1933 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 86:
#line 333 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrConstExp)=new ConstExp(MINUS,(yyvsp[-2].PtrConstExp),(yyvsp[0].PtrConstExp),nullptr,nullptr,nullptr,nullptr);}
#line 1939 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 87:
#line 335 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrConstExp)=new ConstExp(MUL,(yyvsp[-2].PtrConstExp),(yyvsp[0].PtrConstExp),nullptr,nullptr,nullptr,nullptr);}
#line 1945 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 88:
#line 337 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrConstExp)=new ConstExp(DIV,(yyvsp[-2].PtrConstExp),(yyvsp[0].PtrConstExp),nullptr,nullptr,nullptr,nullptr);}
#line 1951 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 89:
#line 339 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrConstExp)=new ConstExp(MOD,(yyvsp[-2].PtrConstExp),(yyvsp[0].PtrConstExp),nullptr,nullptr,nullptr,nullptr);}
#line 1957 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 90:
#line 341 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrConstExp)=new ConstExp(POS,(yyvsp[0].PtrConstExp),nullptr,nullptr,nullptr,nullptr,nullptr);}
#line 1963 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 91:
#line 343 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrConstExp)=new ConstExp(NEG,(yyvsp[0].PtrConstExp),nullptr,nullptr,nullptr,nullptr,nullptr);}
#line 1969 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 92:
#line 345 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrConstExp)=new ConstExp(SUBEXP,(yyvsp[-1].PtrConstExp),nullptr,nullptr,nullptr,nullptr,nullptr);}
#line 1975 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 93:
#line 347 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrConstExp)=new ConstExp(INTEGER,nullptr,nullptr,nullptr,nullptr,nullptr,(yyvsp[0].PtrNumber));}
#line 1981 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;

  case 94:
#line 350 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"
                {(yyval.PtrNumber)=new Number((yyvsp[0].raw_int));}
#line 1987 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"
    break;


#line 1991 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 353 "/SysY-2020-Compiler-For-Rpi4/parser/src/sysy.y"


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
