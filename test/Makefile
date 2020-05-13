INPUT_PATH=in
INPUT=$(wildcard $(INPUT_PATH)/*.c)

LEXER_REFERENCE_PATH=ref
LEXER_REFERENCE=$(INPUT:.c=.lxo)

%.lxo: %.c
	clang -fsyntax-only -Xclang -dump-tokens $< 2>&1 | cut -f1 > $@

reference: $(LEXER_REFERENCE)
	mv $(LEXER_REFERENCE) $(LEXER_REFERENCE_PATH)

clean:
	rm -rf ref/* pre/*
