include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

#add cxxflags
#execute_process(COMMAND llvm-config --cxxflags OUTPUT_VARIABLE CMD_OUTPUT)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMD_OUTPUT}")
#execute_process(COMMAND llvm-config --libs OUTPUT_VARIABLE CMD_OUTPUT)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMD_OUTPUT}")
#execute_process(COMMAND llvm-config --ldflags OUTPUT_VARIABLE CMD_OUTPUT)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lLLVM-10")
#add_llvm_library(${CMAKE_SOURCE_DIR}/cgen/src/EmitAsm.cc)


SET(CgenOutput ${EXECUTABLE_OUTPUT_PATH}/cgen)
add_executable(cgen ${CMAKE_SOURCE_DIR}/cgen/src/EmitAsm.cc ${EXECUTABLE_OUTPUT_PATH}/cgen)
