%option noyywrap
%option yylineno

%{
  #include<stdio.h>

  #ifdef DEBUG_LEXER
    #define DEBUG(type) printf(#type " '%s'\n", yytext)
    #define LITERAL(type) { DEBUG(type); }
  #else
    #include "sysy.tab.h"
    #define DEBUG(type)
    #define LITERAL(type) { return TOKEN_##type; }
  #endif

%}

%x COMMENT

identifier [a-zA-Z][a-zA-Z0-9]*

digit [0-9]
nonzero-digit [1-9]
oct-prefix 0
oct-digit [0-7]
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

{decimal}[a-fA-F][a-fA-F0-9]* {
#ifdef DEBUG_LEXER
  fprintf(stderr, "[ERROR] Lexer error at line %d: Bad hexadecimal number '%s' (no prefix)\n", yylineno, yytext);
#else
  yylval.raw_int = (int)strtol(yytext, NULL, 10);
  return TOKEN_numeric_constant;
#endif
}

{decimal}[a-zA-Z][a-zA-Z0-9]* {
#ifdef DEBUG_LEXER
  fprintf(stderr, "[ERROR] Lexer error at line %d: Bad number '%s'\n", yylineno, yytext);
#else
  yylval.raw_int = (int)strtol(yytext, NULL, 10);
  return TOKEN_numeric_constant;
#endif
}

{decimal} {
  DEBUG(numeric_constant);
#ifndef DEBUG_LEXER
  yylval.raw_int = (int)strtol(yytext, NULL, 10);
  return TOKEN_numeric_constant;
#endif
}

{octal}[89a-fA-F][a-zA-Z0-9]* {
#ifdef DEBUG_LEXER
  fprintf(stderr, "[ERROR] Lexer error at line %d: Bad octal number '%s' (bad octal digit)\n", yylineno, yytext);
#else
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

{hexadecimal}[g-zG-Z][a-zA-Z0-9]* {
#ifdef DEBUG_LEXER
  fprintf(stderr, "[ERROR] Lexer error at line %d: Bad hexadecimal number '%s' (bad hexadecimal digit)\n", yylineno, yytext);
#else
  yylval.raw_int = (int)strtol(yytext, NULL, 10);
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
#else
  yylval.error_msg = "Unmatched close comment";
  return TOKEN_error;
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
#else
  yylval.error_msg = "Unmatched begin comment";
#endif
  yyterminate();
#ifndef DEBUG_LEXER
  return TOKEN_error;
#endif
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
#else
  yylval.error_msg = "Unrecognized token";
  return TOKEN_error;
#endif
}

%%

#ifdef DEBUG_LEXER
int main(void) {
  yylex();
  return 0;
}
#endif