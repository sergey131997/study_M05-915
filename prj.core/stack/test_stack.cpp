#define CATCH_CONFIG_MAIN
#include <iostream>
#include <string>
#include <vector>
#include <catch2/catch.hpp>
#include "src/stack.h"

TEST_CASE("Test Creat", "Stack") {
        Stack<int> a;
        REQUIRE_NOTHROW(a.Push(1));
        Stack<double> b;
        REQUIRE_NOTHROW(b.Push(1.0));
        Stack<char> c;
        REQUIRE_NOTHROW(c.Push('1'));
        Stack<std::string> d;
        REQUIRE_NOTHROW(d.Push("1"));
        Stack<std::vector<int>> e;
        REQUIRE_NOTHROW(e.Push({1}));
}


TEST_CASE("Test Push Pop", "Stack") {
    Stack<int> st;
    for (size_t i(0); i < 100; ++i) {
        REQUIRE_NOTHROW(st.Push(random() % 100));
        REQUIRE_NOTHROW(st.Pop());
    }
    Stack<double> b;
    for (size_t i(0); i < 100; ++i)
        REQUIRE_NOTHROW(b.Push(1.0));
    for (size_t i(0); i < 100; ++i)
        REQUIRE_NOTHROW(b.Pop());
}

TEST_CASE("Test Top Empty Stack", "Stack") {
    Stack<int> st;
    REQUIRE_NOTHROW(st.Push(1));
    REQUIRE_NOTHROW(st.Pop());
    REQUIRE_THROWS(st.Top());
}

TEST_CASE("Test Container", "Stack") {
    Stack<int> st;
    std::vector<int> st_copy;
    st_copy.reserve(100);
    for (int i(0); i < 100; ++i) {
        st_copy.push_back(random() % 100);
        st.Push(st_copy.back());
    }
    for (int i(99); i >= 0; --i) {
        REQUIRE(st_copy[i] == st.Top());
        st.Pop();
    }
}

TEST_CASE("Test Copy", "Stack") {
    Stack<int> st;
    for (size_t i(0); i < 100; ++i)
        st.Push(random() % 100);

    Stack<int> st_copy_1(st);
    Stack<int> st_copy_2;

    for (size_t i(0); i < 10; ++i)
        st_copy_2.Push(2);

    st_copy_2 = st;
    int st_top = st.Top();
    for (size_t i(0); i < 100; ++i) {
        int st_copy_1_top = st_copy_1.Top();
        st_copy_1.Pop();
        REQUIRE(st_copy_1_top == st_copy_2.Top());
        st_copy_2.Pop();
        REQUIRE(st_top == st.Top());
    }
}

//int main(int arc, char** argv) {
//    Catch::RunTests();
//    return 0;
//}
