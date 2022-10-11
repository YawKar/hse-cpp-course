//
// Created by yawkar on 11.10.22.
//

#include "4_2_DynArrayExtended.h"

DynArrayExtended::DynArrayExtended(unsigned int initialCapacity) {
    array = new double[initialCapacity];
    capacity = initialCapacity;
    realSize = 0;
}

DynArrayExtended::DynArrayExtended() {
    array = new double[1];
    capacity = 1;
    realSize = 0;
}

void DynArrayExtended::append(double value) {
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

unsigned int DynArrayExtended::size() {
    return realSize;
}

double DynArrayExtended::get(int index) {
    return array[index];
}

DynArrayExtended::~DynArrayExtended() {
    delete[] array;
}

DynArrayExtended::DynArrayExtended(const DynArrayExtended &other) {
    realSize = other.realSize;
    capacity = other.capacity;
    array = new double[capacity];
    for (int i = 0; i < other.realSize; ++i) {
        array[i] = other.array[i];
    }
}

DynArrayExtended &DynArrayExtended::operator=(const DynArrayExtended &other) {
    delete[] array;
    realSize = other.realSize;
    capacity = other.capacity;
    array = new double[capacity];
    for (int i = 0; i < other.realSize; ++i) {
        array[i] = other.array[i];
    }
    return *this;
}
