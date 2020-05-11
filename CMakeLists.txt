cmake_minimum_required(VERSION 3.7.1)

project(SysY-2020-Compiler)

find_package(LLVM REQUIRED CONFIG)

set(SOURCE_FILES main.c)

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# Add block directories
add_subdirectory(lexer)
add_subdirectory(parser)
add_subdirectory(IR)
add_subdirectory(opt)

