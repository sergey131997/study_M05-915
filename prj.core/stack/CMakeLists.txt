cmake_minimum_required(VERSION 2.8)

project(stack)
add_executable(stack test_stack.cpp src/stack.h src/stack_vector.h src/stack_vector_smartpoint.h)
target_link_libraries(stack Catch2)

