cmake_minimum_required(VERSION 3.10.2)

add_executable(tests tokenTests.cpp)

target_link_libraries(tests gtest_main EvalParser)
add_test(tests uniTests)