#!/bin/bash
mkdir -p in
mkdir -p ../parser/test
mkdir -p ../lexer/test
cp ./sysyruntimelibrary/functional_test/*.sy ./in
cd ./in
rename 's/\.sy/\.c/' *
rename 's/^/func_/' *
cd ..
cp ./sysyruntimelibrary/performance_test/*.sy ./in
cd ./in
rename 's/^/perf_/' *.sy
rename 's/\.sy/\.c/' *.sy
cd ..

make
