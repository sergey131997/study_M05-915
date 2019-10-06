#pragma once
#ifndef STACK_VECTOR_H_17_09_2019
#define STACK_VECTOR_H_17_09_2019
#include <iostream>

template<typename T> class Stack {
public:
    Stack();

    Stack(const Stack &other);

    Stack operator=(const Stack &other);

    void Pop();

    void Push(const T &element);

    bool IsEmpty() const;

    T Top() const;

    ~Stack();
private:
    size_t count_ = 0;
    size_t capasity_ = 0;
    T *values_;
};


template<typename T>
Stack<T>::Stack() {
    capasity_ = 10;
    count_ = 0;
    values_ = new T[10];
};

template<typename T>
bool Stack<T>::IsEmpty() const{
    return (count_ == 0);
};

template<typename T>
Stack<T>::~Stack() {
    delete[] values_;
};

template<typename T>
Stack<T>::Stack(const Stack<T> &other) {
    while(!IsEmpty())
        Pop();
    capasity_ = 10;
    count_ = 0;
    values_ = new T[10];
    for (size_t i =0; i < other.count_; ++i)
        Push(other.values_[i]);
}

template<typename T>
Stack<T> Stack<T>::operator=(const Stack<T> &other) {
    while(!IsEmpty())
        Pop();
    capasity_ = 10;
    count_ = 0;
    values_ = new T[10];
    for (size_t i =0; i < other.count_; ++i)
        Push(other.values_[i]);
    return *this;
}

template <typename T>
void Stack<T>::Pop() {
    if (IsEmpty())
        return;
    --count_;
}

template <typename T>
void Stack<T>::Push(const T &element) {
    if (capasity_ == count_ + 1) {
        capasity_ *= 2;
        T *tmp = new T[capasity_];
        for (size_t i = 0; i <= count_; ++i)
            tmp[i] = values_[i];
        delete[] values_;
        values_ = std::move(tmp);
    }
    ++count_;
    values_[count_] = element;
}

template <typename T>
T Stack<T>::Top() const {
    if (IsEmpty())
        throw std::runtime_error("Stack is empty!\n");
    return values_[count_];
}
#endif STACK_VECTOR_H_17_09_2019
