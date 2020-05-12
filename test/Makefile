
INPUT_PATH=./in
INPUT=$(wildcard $(INPUT_PATH)/*.c)

LEXER_OUTPUT=$(INPUT:.c=.lxo)
LEXER_OUTPUT_PATH=out

%.lxo: %.c
	clang -fsyntax-only -Xclang -dump-tokens $< 2>&1 | cut -f1 > $@

reference: $(LEXER_OUTPUT)
	mv $(LEXER_OUTPUT) $(LEXER_OUTPUT_PATH)
