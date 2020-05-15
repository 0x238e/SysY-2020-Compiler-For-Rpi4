%option noyywrap
%option yylineno

%{
  #include<stdio.h>

  #define DEBUG_LEXER

  #ifdef DEBUG_LEXER
    #define DEBUG(type) printf(#type " '%s'\n", yytext)
    #define LITERAL(type) { DEBUG(type); }
  #else
    #include "yy.tab.h"
    #define DEBUG(type)
    #define LITERAL(type) { return TOKEN_##type; }
  #endif

%}

%x COMMENT

identifier [a-zA-Z][a-zA-Z0-9]*

digit [0-9]
nonzero-digit [1-9]
oct-prefix 0
oct-digit [0-8]
hex-prefix 0x|0X
hex-digit [0-9a-fA-F]

decimal {nonzero-digit}{digit}*
octal {oct-prefix}{oct-digit}*
hexadecimal {hex-prefix}{hex-digit}+

%%

const LITERAL(const)

int LITERAL(int)

void LITERAL(void)

if LITERAL(if)

else LITERAL(else)

while LITERAL(while)

break LITERAL(break)

continue LITERAL(continue)

return LITERAL(return)

"," LITERAL(comma)

";" LITERAL(semi)

"{" LITERAL(l_brace)

"(" LITERAL(l_paren)

"[" LITERAL(l_square)

"}" LITERAL(r_brace)

")" LITERAL(r_paren)

"]" LITERAL(r_square)

"!" LITERAL(exclaim)

"&&" LITERAL(ampamp)

"||" LITERAL(pipepipe)

"==" LITERAL(equalequal)

"=" LITERAL(equal)

"!=" LITERAL(exclaimequal)

"<=" LITERAL(lessequal)

"<" LITERAL(less)

">=" LITERAL(greaterequal)

">" LITERAL(greater)

"+" LITERAL(plus)

"-" LITERAL(minus)

"*" LITERAL(star)

"/" LITERAL(slash)

"%" LITERAL(percent)

{identifier} {
  DEBUG(identifier);
#ifndef DEBUG_LEXER
  yylval.raw_symbol = yytext;
  return TOKEN_identifier;
#endif
}

{decimal} {
  DEBUG(numeric_constant);
#ifndef DEBUG_LEXER
  yylval.raw_int = (int)strtol(yytext, NULL, 10);
  return TOKEN_numeric_constant;
#endif
}

{octal} {
  DEBUG(numeric_constant);
#ifndef DEBUG_LEXER
  yylval.raw_int = (int)strtol(yytext, NULL, 8);
  return TOKEN_numeric_constant;
#endif
}

{hexadecimal} {
  DEBUG(numeric_constant);
#ifndef DEBUG_LEXER
  yylval.raw_int = (int)strtol(yytext, NULL, 16);
  return TOKEN_numeric_constant;
#endif
}

"//".* { }

<INITIAL>"/*" {
  BEGIN(COMMENT);
}

<INITIAL>"*/" {
#ifdef DEBUG_LEXER
  fprintf(stderr, "[ERROR] Lexer error at line %d: Unmatched close comment '%s'\n", yylineno, yytext);
#endif
}

<COMMENT>"*/" {
  BEGIN(INITIAL);
}

<COMMENT>"*"/[^/] { }

<COMMENT>[^*]+ { }

<COMMENT><<EOF>> {
#ifdef DEBUG_LEXER
  fprintf(stderr, "[ERROR] Lexer error at line %d: Unmatched begin comment '%s'\n", yylineno, yytext);
#endif
  yyterminate();
}

[ \f\r\t\v\n]+ { }

<<EOF>> {
#ifdef DEBUG_LEXER
  printf("eof ''\n");
#endif
  yyterminate();
}

[^\n] {
#ifdef DEBUG_LEXER
  fprintf(stderr, "[ERROR] Lexer error at line %d: Unrecognized token '%s'\n", yylineno, yytext);
#endif
}

%%

#ifdef DEBUG_LEXER
int main(void) {
  yylex();
  return 0;
}
#endif