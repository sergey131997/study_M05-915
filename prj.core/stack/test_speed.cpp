#include <iostream>
#include <vector>
#include <chrono>

#include "src/stack.h"
#include "src/stack_vector.h"
#include "src/stack_vector_smartpoint.h"

//------------------------------------------------------------------------------------------------------------------

void test_heap_stack() {
    stack::Stack<int> test;
    auto tbegin = std::chrono::steady_clock::now();
    for (int i = 0; i < 100000; ++i)
        test.Push(i);
    auto tpush = std::chrono::steady_clock::now();
    for (int i = 0; i < 100000; ++i)
        test.Pop();
    auto tpop = std::chrono::steady_clock::now();
    ::fprintf(stdout, "list Push: %d\n",
              static_cast<int>(std::chrono::duration_cast<std::chrono::nanoseconds>(tpush - tbegin).count()));
    ::fprintf(stdout, "list Pop:  %d\n\n",
              static_cast<int>(std::chrono::duration_cast<std::chrono::nanoseconds>(tpop - tpush).count()));
}

void test_heap_stack_vector() {
    stack_vector::Stack<int> test;
    auto tbegin = std::chrono::steady_clock::now();
    for (int i = 0; i < 100000; ++i)
        test.Push(i);
    auto tpush = std::chrono::steady_clock::now();
    for (int i = 0; i < 100000; ++i)
        test.Pop();
    auto tpop = std::chrono::steady_clock::now();
    ::fprintf(stdout, "list Push: %d\n",
              static_cast<int>(std::chrono::duration_cast<std::chrono::nanoseconds>(tpush - tbegin).count()));
    ::fprintf(stdout, "list Pop:  %d\n\n",
              static_cast<int>(std::chrono::duration_cast<std::chrono::nanoseconds>(tpop - tpush).count()));
}

void test_heap_stack_vector_smartpointer() {
    stack_vector_smartpointer::Stack<int> test;
    auto tbegin = std::chrono::steady_clock::now();
    for (int i = 0; i < 100000; ++i)
        test.Push(i);
    auto tpush = std::chrono::steady_clock::now();
    for (int i = 0; i < 100000; ++i)
        test.Pop();
    auto tpop = std::chrono::steady_clock::now();
    ::fprintf(stdout, "list Push: %d\n",
              static_cast<int>(std::chrono::duration_cast<std::chrono::nanoseconds>(tpush - tbegin).count()));
    ::fprintf(stdout, "list Pop:  %d\n\n",
              static_cast<int>(std::chrono::duration_cast<std::chrono::nanoseconds>(tpop - tpush).count()));
}

//------------------------------------------------------------------------------------------------------------------

void test_snake_stack(const std::vector<int> &queue) {
    stack::Stack<int> test;
    auto tbegin = std::chrono::steady_clock::now();
    for(const int &i : queue)
        if (i > 0)
            test.Push(1);
        else
            test.Pop();
    auto tend = std::chrono::steady_clock::now();
    ::fprintf(stdout, "list:         %d\n\n",
              static_cast<int>(std::chrono::duration_cast<std::chrono::nanoseconds>(tend - tbegin).count()));
}

void test_snake_stack_vector(const std::vector<int> &queue) {
    stack_vector::Stack<int> test;
    auto tbegin = std::chrono::steady_clock::now();
    for(const int &i : queue)
        if (i > 0)
            test.Push(1);
        else
            test.Pop();
    auto tend = std::chrono::steady_clock::now();
    ::fprintf(stdout, "vector:       %d\n\n",
              static_cast<int>(std::chrono::duration_cast<std::chrono::nanoseconds>(tend - tbegin).count()));
}

void test_snake_stack_vector_smartpointer(const std::vector<int> &queue) {
    stack_vector_smartpointer::Stack<int> test;
    auto tbegin = std::chrono::steady_clock::now();
    for(const int &i : queue)
        if (i > 0)
            test.Push(1);
        else
            test.Pop();
    auto tend = std::chrono::steady_clock::now();
    ::fprintf(stdout, "smartpointer: %d\n\n",
              static_cast<int>(std::chrono::duration_cast<std::chrono::nanoseconds>(tend - tbegin).count()));
}

int main() {
    // Test heap
    ::fprintf(stdout, "Test heap\n");
    test_heap_stack();
    test_heap_stack_vector();
    test_heap_stack_vector_smartpointer();

    // Test snake
    std::vector<int> queue;
    for (int i = 0; i < 10000; ++i)
        queue.push_back(i);
    for (int i = 100; i < 10000; ++i) {
        for (int j = 0; j < 100; ++j)
            queue.push_back(1);
        for (int j = 0; j < 100; ++j)
            queue.push_back(-1);
    }
    for (int i = 0; i < 10000; ++i)
        queue.push_back(-1);
    // Test snake
    ::fprintf(stdout, "Test snake\n");
    test_snake_stack(queue);
    test_snake_stack_vector(queue);
    test_snake_stack_vector_smartpointer(queue);

}
