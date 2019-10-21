#pragma once
#ifndef STACK_VECTOR_SMARTPINTER_H_17_09_2019
#define STACK_VECTOR_SMARTPINTER_H_17_09_2019
#include <iostream>
#include <memory>

namespace stack_vector_smartpointer {

template<typename T> class Stack {
public:
    Stack();

    Stack(const Stack &other);

    Stack operator=(const Stack &other);

    void Pop();

    void Push(const T &element);

    bool IsEmpty() const;

    T Top() const;

    ~Stack() = default;
private:
    size_t count_ = 0;
    size_t capasity_ = 0;
    std::unique_ptr<T[]> values_;
};


template<typename T>
Stack<T>::Stack() {
    capasity_ = 10;
    count_ = 0;
    values_.reset(new T[10]);
};

template<typename T>
bool Stack<T>::IsEmpty() const{
    return (count_ == 0);
};

template<typename T>
Stack<T>::Stack(const Stack<T> &other) {
    while(!IsEmpty())
        Pop();
    capasity_ = other.capasity_;
    count_ = 0;
    values_.reset(new T[other.capasity_]);
    for (size_t i =0; i < other.count_; ++i)
        Push(*(other.values_.get() + i));
}

template<typename T>
Stack<T> Stack<T>::operator=(const Stack<T> &other) {
    while(!IsEmpty())
        Pop();
    capasity_ = other.capasity_;
    count_ = 0;
    values_.reset(new T[other.capasity_]);
    for (size_t i =0; i < other.count_; ++i)
        Push(*(other.values_.get() + i));
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
            tmp[i] = *(values_.get() + i);
        values_.reset(std::move(tmp));
    }
    ++count_;
    *(values_.get() + count_) = element;
}

template <typename T>
T Stack<T>::Top() const {
    if (IsEmpty())
        throw std::runtime_error("Stack is empty!\n");
    return *(values_.get() + count_);
}

}

#endif STACK_VECTOR_SMARTPINTER_H_17_09_2019
