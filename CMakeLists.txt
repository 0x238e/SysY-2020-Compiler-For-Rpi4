cmake_minimum_required(VERSION 3.7.1)

project(SysY-2020-Compiler)

find_package(LLVM REQUIRED CONFIG)

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})


# Add LLVM toolchain support
if(LINUX)
SET (CMAKE_C_COMPILER               "/usr/bin/clang")
SET (CMAKE_CXX_COMPILER             "/usr/bin/clang++")
SET (CMAKE_C_FLAGS                  "-Wall -std=c99")
SET (CMAKE_C_FLAGS_DEBUG            "-g")
SET (CMAKE_C_FLAGS_MINSIZEREL       "-Os -DNDEBUG")
SET (CMAKE_C_FLAGS_RELEASE          "-O4 -DNDEBUG")
SET (CMAKE_C_FLAGS_RELWITHDEBINFO   "-O2 -g")
SET (CMAKE_CXX_FLAGS                "-Wall -lfl")
SET (CMAKE_CXX_FLAGS_DEBUG          "-g")
SET (CMAKE_CXX_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELEASE        "-O4 -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")
endif ()

if (MSVC)
    set(CMAKE_C_COMPILER            ${LLVM_BUILD_ROOT}/bin/clang)
    set(CMAKE_CXX_COMPILER          ${LLVM_BUILD_ROOT}/bin/clang++)
    set(CMAKE_CXX_FLAGS
            "${CMAKE_CXX_FLAGS} /Zc:__cplusplus /std:c++17 /MP /Z7 /D \"_CRT_SECURE_NO_WARNINGS\" /D \"_ENABLE_EXTENDED_ALIGNED_STORAGE\"")
endif ()


SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/)


# Add block directories
add_subdirectory(lexer)
add_subdirectory(parser)
add_subdirectory(IR)
add_subdirectory(opt)