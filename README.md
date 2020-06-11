# SysY-2020-Compiler-For-Rpi4
[![CircleCI Build Status](https://circleci.com/gh/0x238e/SysY-2020-Compiler-For-Rpi4.svg?style=shield&circle-token=8ab332397c88e71f6861449ac75522ef56f172f9)](https://circleci.com/gh/0x238e/SysY-2020-Compiler-For-Rpi4) [![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](https://raw.githubusercontent.com/0x238e/SysY-2020-Compiler-For-Rpi4/master/LICENSE) 

The SysY language is the programming language to be implemented in this contest and is a subset of the C language. The source code for each SysY program is stored in a file with the extension sy. The file has and only has one main function definition named main. it can also contain several global variable declarations, function declarations and other function definitions. the SysY language supports multidimensional array types with int type and elements of int type and stored row first. the const modifier is used to declare constants.

## lexer
lexer is a software component that takes a string and breaks it down into smaller units that are understandable by a language. We apply the function of `yacc`.
## parser
We apply the integration of the `bison` and `yacc` for parser generation with verification to the updates of SysY spec.
## cgen
Without the IR, we first follow the idea of LLVM to generate assembly code from it and test in the arm `qemu` environment.
