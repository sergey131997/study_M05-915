#include <iostream>
#include <vector>
#include <chrono>

#include "src/stack.h"
#include "src/stack_vector.h"
#include "src/stack_vector_smartpoint.h"

//------------------------------------------------------------------------------------------------------------------

void TestHeapStack(const size_t &count) {
    stack::Stack<int> test;
    auto tbegin = std::chrono::steady_clock::now();
    for (size_t i = 0; i < count; ++i)
        test.Push(1);
    auto tpush = std::chrono::steady_clock::now();
    for (size_t i = 0; i < count; ++i)
        test.Pop();
    auto tpop = std::chrono::steady_clock::now();
    ::fprintf(stdout, "%d\n",
              static_cast<int>(std::chrono::duration_cast<std::chrono::nanoseconds>(tpush - tbegin).count()));
    ::fprintf(stdout, "%d\n",
              static_cast<int>(std::chrono::duration_cast<std::chrono::nanoseconds>(tpop - tpush).count()));
}

void TestHeapStackVector(const size_t &count) {
    stack_vector::Stack<int> test;
    auto tbegin = std::chrono::steady_clock::now();
    for (size_t i = 0; i < count; ++i)
        test.Push(1);
    auto tpush = std::chrono::steady_clock::now();
    for (size_t i = 0; i < count; ++i)
        test.Pop();
    auto tpop = std::chrono::steady_clock::now();
    ::fprintf(stdout, "%d\n",
              static_cast<int>(std::chrono::duration_cast<std::chrono::nanoseconds>(tpush - tbegin).count()));
    ::fprintf(stdout, "%d\n",
              static_cast<int>(std::chrono::duration_cast<std::chrono::nanoseconds>(tpop - tpush).count()));
}

void TestHeapStackVectorSmartpointer(const size_t &count) {
    stack_vector::Stack<int> test;
    auto tbegin = std::chrono::steady_clock::now();
    for (size_t i = 0; i < count; ++i)
        test.Push(1);
    auto tpush = std::chrono::steady_clock::now();
    for (size_t i = 0; i < count; ++i)
        test.Pop();
    auto tpop = std::chrono::steady_clock::now();
    ::fprintf(stdout, "%d\n",
              static_cast<int>(std::chrono::duration_cast<std::chrono::nanoseconds>(tpush - tbegin).count()));
    ::fprintf(stdout, "%d\n",
              static_cast<int>(std::chrono::duration_cast<std::chrono::nanoseconds>(tpop - tpush).count()));
}

//------------------------------------------------------------------------------------------------------------------

void TestSnakeStack(const std::vector<int> &queue) {
    stack::Stack<int> test;
    auto tbegin = std::chrono::steady_clock::now();
    for(const int &i : queue)
        if (i > 0)
            test.Push(1);
        else
            test.Pop();
    auto tend = std::chrono::steady_clock::now();
    ::fprintf(stdout, "%d\n",
              static_cast<int>(std::chrono::duration_cast<std::chrono::nanoseconds>(tend - tbegin).count()));
}

void TestSnakeStackVector(const std::vector<int> &queue) {
    stack_vector::Stack<int> test;
    auto tbegin = std::chrono::steady_clock::now();
    for(const int &i : queue)
        if (i > 0)
            test.Push(1);
        else
            test.Pop();
    auto tend = std::chrono::steady_clock::now();
    ::fprintf(stdout, "%d\n",
              static_cast<int>(std::chrono::duration_cast<std::chrono::nanoseconds>(tend - tbegin).count()));
}

void TestSnakeStackVectorSmartpointer(const std::vector<int> &queue) {
    stack_vector_smartpointer::Stack<int> test;
    auto tbegin = std::chrono::steady_clock::now();
    for(const int &i : queue)
        if (i > 0)
            test.Push(1);
        else
            test.Pop();
    auto tend = std::chrono::steady_clock::now();
    ::fprintf(stdout, "%d\n",
              static_cast<int>(std::chrono::duration_cast<std::chrono::nanoseconds>(tend - tbegin).count()));
}

//------------------------------------------------------------------------------------------------------------------

void CopyStack(size_t count) {
    stack::Stack<int> test1;
    stack::Stack<int> test2;
    for (size_t i = 0; i < count; ++i) {
        test2.Push(1);
        test1.Push(2);
    }

    auto tbegin = std::chrono::steady_clock::now();
    test2 = test1;
    auto tend = std::chrono::steady_clock::now();
    ::fprintf(stdout, "%d\n",
              static_cast<int>(std::chrono::duration_cast<std::chrono::nanoseconds>(tend - tbegin).count()));
}

void CopyStackVector(size_t count) {
    stack_vector::Stack<int> test1;
    stack_vector::Stack<int> test2;
    for (size_t i = 0; i < count; ++i) {
        test2.Push(1);
        test1.Push(2);
    }

    auto tbegin = std::chrono::steady_clock::now();
    test2 = test1;
    auto tend = std::chrono::steady_clock::now();
    ::fprintf(stdout, "%d\n",
              static_cast<int>(std::chrono::duration_cast<std::chrono::nanoseconds>(tend - tbegin).count()));
}

void CopyStackVectorSmartpointer(size_t count) {
    stack_vector_smartpointer::Stack<int> test1;
    stack_vector_smartpointer::Stack<int> test2;
    for (size_t i = 0; i < count; ++i) {
        test2.Push(1);
        test1.Push(2);
    }

    auto tbegin = std::chrono::steady_clock::now();
    test2 = test1;
    auto tend = std::chrono::steady_clock::now();
    ::fprintf(stdout, "%d\n",
              static_cast<int>(std::chrono::duration_cast<std::chrono::nanoseconds>(tend - tbegin).count()));
}

//---------------------------------------------------------------------------------------------------------------------

int main() {
    for (size_t count = 10; count < 1000000; count *= 10) {
        for (size_t count_1 = 0; count_1 < 100; ++count_1) {
            TestHeapStack(count);
            TestHeapStackVector(count);
            TestHeapStackVectorSmartpointer(count);

            // Test snake
            std::vector<int> queue;
            for (size_t i = 0; i < count; ++i)
                queue.push_back(1);

            for (int i = 1; i < 100; ++i) {
                for (size_t j = 0; j < count; ++j)
                    queue.push_back(1);
                for (size_t j = 0; j < count; ++j)
                    queue.push_back(-1);
            }
            for (size_t i = 0; i < count; ++i)
                queue.push_back(-1);

            // Test snake
            TestSnakeStack(queue);
            TestSnakeStackVector(queue);
            TestSnakeStackVectorSmartpointer(queue);

            CopyStack(count);
            CopyStackVector(count);
            CopyStackVectorSmartpointer(count);
        }
    }
}
