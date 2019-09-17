#pragma once
#ifndef STACK_H_17_09_2019
#define STACK_H_17_09_2019
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
    struct node {
        T value;
        node *next_;
    };
    node *top_ = nullptr;
};


template<typename T>
Stack<T>::Stack() {};

template<typename T>
bool Stack<T>::IsEmpty() const{
    return (top_ == nullptr);
};

template<typename T>
Stack<T>::~Stack() {
    while(!IsEmpty())
        Pop();
};

template<typename T>
Stack<T>::Stack(const Stack<T> &other) {
    Stack<T> temp;
    while(!IsEmpty())
        Pop();
    node *other_top = other.top_;
    while(other_top != nullptr) {
        temp.Push(other_top->value);
        other_top = other_top->next_;
    }
    while(!temp.IsEmpty()) {
        Push(temp.Top());
        temp.Pop();
    }
}

template<typename T>
Stack<T> Stack<T>::operator=(const Stack<T> &other) {
    Stack<T> temp;
    while(!IsEmpty())
        Pop();
    node *other_top = other.top_;
    while(other_top != nullptr) {
        temp.Push(other_top->value);
        other_top = other_top->next_;
    }
    while(!temp.IsEmpty()) {
        Push(temp.Top());
        temp.Pop();
    }
    return *this;
}

template <typename T>
void Stack<T>::Pop() {
    if (IsEmpty())
        return;
    node *old_node = top_;
    top_ = top_->next_;
    delete old_node;
}

template <typename T>
void Stack<T>::Push(const T &element) {
    node *new_node = new node();
    new_node->value = element;
    new_node->next_ = top_;
    top_ = new_node;
}

template <typename T>
T Stack<T>::Top() const {
    if (IsEmpty())
        throw std::runtime_error("Stack is empty!\n");
    return top_->value;
}
#endif STACK_H_17_09_2019
