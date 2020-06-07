#!/bin/sh

clang -emit-llvm -S test.c
opt -reg2mem test.ll -S > test_no_phi.ll
opt -load-pass-plugin ../build/libEmitAsm.so -passes=a test_no_phi.ll -S > /dev/null 2>my.s
./cc.sh my.s
# ./run.sh a.out