cmake_minimum_required(VERSION 2.8)

project(stack)
add_executable(stack test_stack.cpp src/stack.h)
target_link_libraries(stack Catch2)

