CC = g++

re:
	make clean
	make parser

lex.yy.c: ../../lexer/src/sysy.flex
	cp ../../lexer/src/sysy.flex ./
	flex sysy.flex

sysy.tab.c: sysy.y
	bison -v -t -d -y -b sysy sysy.y

parser: lex.yy.c sysy.tab.c sysy_parse.cpp
	$(CC) lex.yy.c sysy.tab.c sysy_parse.cpp -lfl -o parser

clean:
	rm *.yy.* -f
	rm *.tab.* -f
	rm *.flex -f
	rm *.output -f
	rm parser -f