cmake_minimum_required(VERSION 3.10.2)

set(this EvalParser)

project(${this} VERSION 1.0.1)

#test
set(BUILD_GMOCK OFF)
add_subdirectory(googletest)
enable_testing()



set(SRC 
    src/token.cpp
    src/parser.cpp
)
include_directories(include googletest/googletest/include googletest/googletest/src)
add_library(${this} STATIC ${SRC}) 
add_subdirectory(tests)
