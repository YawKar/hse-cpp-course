//
// Created by yawkar on 03.10.22.
//

#include "3_2_MyStack.h"

MyStack::MyStack() {
    array = new int[1];
    capacity = 1;
    realSize = 0;
}

MyStack::MyStack(unsigned int initialCapacity) {
    array = new int[initialCapacity];
    capacity = initialCapacity;
    realSize = 0;
}

MyStack::~MyStack() {
    delete[] array;
}

void MyStack::push(int value) {
    if (realSize == capacity) {
        int* copy = new int[capacity * 2];
        for (int i = 0; i < realSize; ++i) {
            copy[i] = array[i];
        }
        capacity *= 2;
        delete[] array;
        array = copy;
    }
    array[realSize++] = value;
}

int MyStack::pop() {
    return array[--realSize];
}

unsigned int MyStack::size() {
    return realSize;
}

int MyStack::peek() {
    return array[realSize - 1];
}
