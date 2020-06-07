FIND_PACKAGE(BISON REQUIRED)
option(DEBUG_LEXER "select to use specified function" OFF)
SET(BisonOutput ${EXECUTABLE_OUTPUT_PATH}/parser)
SET(BisonTempOutput ${CMAKE_SOURCE_DIR}/parser/src/sysy.tab.c)
set(CMAKE_CXX_STANDARD 11)
remove_definitions(-DDEBUG_LEXER)

SET(FlexTempOutput ${CMAKE_SOURCE_DIR}/lexer/src/lex.yy.c)
flex_target(lexer ${PROJECT_SOURCE_DIR}/lexer/src/sysy.flex ${FlexTempOutput})
IF(BISON_FOUND)
    bison_target(parser ${PROJECT_SOURCE_DIR}/parser/src/sysy.y ${BisonTempOutput} COMPILE_FLAGS "-v -t -d -y" )
ENDIF()

ADD_FLEX_BISON_DEPENDENCY(lexer parser)
SET(SOURCE_FILES ${BisonTempOutput} ${PROJECT_SOURCE_DIR}/parser/src/sysy_parse.cpp ${FlexTempOutput})
SET_SOURCE_FILES_PROPERTIES( ${SOURCE_FILES} PROPERTIES LANGUAGE CXX )

ADD_EXECUTABLE(parser ${SOURCE_FILES} ${BisonOutput})
include_directories(${PROJECT_SOURCE_DIR}/parser/src)
