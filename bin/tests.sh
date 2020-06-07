#!/bin/bash

rename .ll .c ../parser/test/*
rename .lxo .c ../lexer/test/*
rename .out .c ../cgen/test/*
cd ../test/in
for file in ./*
do
    # lexer test
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
    #cgen test
    if  diff ../../cgen/test/$file <(../../bin/cgen ../../test/in/$file)
    then
        echo $file cgen pass
    else
        echo $file cgen failed
    fi
done

cd ../../cgen/test
./all.sh