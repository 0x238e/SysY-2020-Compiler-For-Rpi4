# Identifiers

- TOKEN_identifiers **Ident** `char* yylval.raw_symbol`
- TOKEN_numeric_constant **IntConst** `int yylval.raw_int`
- TOKEN_string_constant **StrConst** `char* yylval.raw_str`

# Keywords

- TOKEN_const 'const'
- TOKEN_int 'int'
- TOKEN_void 'void'
- TOKEN_if 'if'
- TOKEN_else 'else'
- TOKEN_while '.*'
- TOKEN_break 'break'
- TOKEN_continue 'continue'
- TOKEN_return 'return'

# Seperators

- TOKEN_comma ','
- TOKEN_semi ';'
- TOKEN_l_brace '{'
- TOKEN_l_paren '('
- TOKEN_l_square '['
- TOKEN_r_brace '}'
- TOKEN_r_paren ')'
- TOKEN_r_square ']'

# Operators

# Assign

- TOKEN_equal '='

## Logic

- TOKEN_exclaim '!'
- TOKEN_ampamp '&&'
- TOKEN_pipepipe '||'

## Relation

- TOKEN_equalequal '=='
- TOKEN_exclaimequal '!='
- TOKEN_less '<'
- TOKEN_greater '>'
- TOKEN_lessequal '<='
- TOKEN_greaterequal '>='

## Arithmatic

- TOKEN_plus '+'
- TOKEN_minus '-'
- TOKEN_star '*'
- TOKEN_slash '/'
- TOKEN_percent '%'

# Misc

- TOKEN_eof **<EOF>**