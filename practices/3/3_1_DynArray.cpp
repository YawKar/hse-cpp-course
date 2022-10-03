//
// Created by yawkar on 03.10.22.
//

#include "3_1_DynArray.h"

DynArray::DynArray(unsigned int initialCapacity) {
    array = new double[initialCapacity];
    capacity = initialCapacity;
    realSize = 0;
}

DynArray::DynArray() {
    array = new double[1];
    capacity = 1;
    realSize = 0;
}

void DynArray::append(double value) {
    if (realSize == capacity) {
        auto* copy = new double[capacity * 2];
        for (unsigned int i = 0; i < realSize; ++i) {
            copy[i] = array[i];
        }
        capacity *= 2;
        delete[] array;
        array = copy;
    }
    array[realSize++] = value;
}

unsigned int DynArray::size() {
    return realSize;
}

double DynArray::get(int index) {
    return array[index];
}

DynArray::~DynArray() {
    delete[] array;
}
