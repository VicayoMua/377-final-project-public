#include "simplestack.h"

// Constructor
template<typename T>
SimpleStack<T>::SimpleStack() {
    this->stack_top = nullptr;
}

// Destructor
template<typename T>
SimpleStack<T>::~SimpleStack() {
    while (!this->isEmpty()) {
        this->pop();
    }
}

// Check if the stack is empty
template<typename T>
bool SimpleStack<T>::isEmpty() {
    return this->stack_top == nullptr;
}

// Push a value onto the stack
template<typename T>
void SimpleStack<T>::push(T &&value) {
    auto *newNode = new SimpleStackNode;
    newNode->value = value;
    newNode->next = this->stack_top;
    this->stack_top = newNode;
}

template<typename T>
void SimpleStack<T>::push(T &value) {
    auto *newNode = new SimpleStackNode;
    newNode->value = value;
    newNode->next = this->stack_top;
    this->stack_top = newNode;
}

// Pop the top value from the stack
template<typename T>
T SimpleStack<T>::pop() {
    if (this->isEmpty()) {
        throw std::runtime_error("SimpleStack.pop: The stack is already empty, nothing to pop!");
    }
    T topValue = this->stack_top->value;
    SimpleStackNode *temp = this->stack_top;
    this->stack_top = this->stack_top->next;
    delete temp;
    return topValue;
}