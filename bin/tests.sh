#!/bin/bash

rename .ll .c ../parser/test/*
rename .lxo .c ../lexer/test/*
cd ../test/in
for file in ./*
do
    # parser test
    if diff ../../lexer/test/$file <(../../bin/lexer < ../../test/in/$file)
    then
        echo $file lexer pass
    else
        echo $file lexer failed
    fi
    # parser test
    if  diff ../../parser/test/$file <(../../bin/parser ../../test/in/$file)
    then
        echo $file parser pass
    else
        echo $file parser failed
    fi
done
