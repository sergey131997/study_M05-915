#include "src/stack.h"
#include <iostream>
#include <string>
#include <vector>

bool TestCreate() {
    try {
        Stack<int> a;
        a.Push(1);
        Stack<double> b;
        b.Push(1.0);
        Stack<char> c;
        c.Push('1');
        Stack<std::string> d;
        d.Push("1");
        Stack<std::vector<int>> e;
        e.Push({1});
    } catch (const std::exception &ex) {
        ::fprintf(stderr, "%s\n", ex.what());
        ::fprintf(stdout, "TestCreate - Fail\n");
        return false;
    }
    ::fprintf(stdout, "TestCreate - Complete\n");
    return true;
}

bool TestPushPop() {
    try {
        Stack<int> a;
        for (size_t i(0); i < 100; ++i) {
            a.Push(i);
            a.Pop();
        }

        Stack<double> b;
        for (size_t i(0); i < 100; ++i)
            b.Push(1.0);
        for (size_t i(0); i < 100; ++i)
            b.Pop();

    } catch (const std::exception &ex) {
        ::fprintf(stderr, "%s\n", ex.what());
        ::fprintf(stdout, "TestPushPop - Fail\n");
        return false;
    }
    ::fprintf(stdout, "TestPushPop - Complete\n");
    return true;
}

bool TestCopy() {
    try {
        Stack<int> a;
        for (size_t i(0); i < 100; ++i) {
            a.Push(1);
        }
        Stack<int> b(a);
        Stack<int> c;
        for (size_t i(0); i < 10; ++i)
            c.Push(2);
        c = a;
        a.Pop();
        a.Push(2);
        for (size_t i(0); i < 100; ++i) {
            const int &c_top = c.Top();
            const int &b_top = b.Top();
            if (c_top != 1 || b_top != 1)
                throw std::runtime_error("Error in Stack!\n");
            c.Pop();
            b.Pop();
        }
    } catch (const std::exception &ex) {
        ::fprintf(stderr, "%s\n", ex.what());
        ::fprintf(stdout, "TestCopy - Fail\n");
        return false;
    }
    ::fprintf(stdout, "TestCopy - Complete\n");
    return true;
}


int main(int arc, char** argv) {
    if (!TestCreate())
        return 1;
    if (!TestPushPop())
        return 1;
    if (!TestCopy())
        return 1;
    return 0;
}
