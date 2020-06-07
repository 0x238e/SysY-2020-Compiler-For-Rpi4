INPUT_PATH=./in
INPUT=$(wildcard $(INPUT_PATH)/*.c)

LEXER_OUTPUT=$(INPUT:.c=.lxo)
LEXER_OUTPUT_PATH=../lexer/test
PARSER_OUTPUT=$(INPUT:.c=.ll)
PARSER_OUTPUT_PATH=../parser/test
CGEN_OUTPUT=$(INPUT:.c=.out)
CGEN_OUTPUT_PATH=../cgen/test

%.lxo %.ll: %.c
	clang -fsyntax-only -Xclang -dump-tokens $< 2>&1 | cut -f1 > $@
	clang -fsyntax -Xclang -dump-ast $< 2>&1 | cut -f1 > $@

reference: $(LEXER_OUTPUT)
	mv $(LEXER_OUTPUT) $(LEXER_OUTPUT_PATH)
	mv $(PARSER_OUTPUT) $(PARSER_OUTPUT_PATH)
	mv $(CGEN_OUTPUT) $(CGEN_OUTPUT_PATH)

