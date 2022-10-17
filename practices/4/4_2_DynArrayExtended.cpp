//
// Created by yawkar on 11.10.22.
//

#include "4_2_DynArrayExtended.h"

unsigned int DynArrayExtended::_instancesAlive = 0;

DynArrayExtended::DynArrayExtended(unsigned int initialCapacity) {
    ++_instancesAlive;
    array = new double[initialCapacity];
    capacity = initialCapacity;
    realSize = 0;
}

DynArrayExtended::DynArrayExtended() {
    ++_instancesAlive;
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

unsigned int DynArrayExtended::size() const {
    return realSize;
}

double DynArrayExtended::get(int index) {
    return array[index];
}

DynArrayExtended::~DynArrayExtended() {
    --_instancesAlive;
    delete[] array;
}

DynArrayExtended::DynArrayExtended(const DynArrayExtended &other) {
    ++_instancesAlive;
    realSize = other.realSize;
    capacity = other.capacity;
    array = new double[capacity];
    for (int i = 0; i < other.realSize; ++i) {
        array[i] = other.array[i];
    }
}

DynArrayExtended &DynArrayExtended::operator=(const DynArrayExtended &other) {
    if (this == &other) {
        return *this;
    }
    delete[] array;
    realSize = other.realSize;
    capacity = other.capacity;
    array = new double[capacity];
    for (int i = 0; i < other.realSize; ++i) {
        array[i] = other.array[i];
    }
    return *this;
}

unsigned int DynArrayExtended::instancesAlive() {
    return _instancesAlive;
}

double &DynArrayExtended::operator[](int index) {
    return array[index];
}

DynArrayExtended DynArrayExtended::operator+(const DynArrayExtended &other) {
    DynArrayExtended concat(realSize + other.realSize);
    for (int i = 0; i < realSize; ++i) {
        concat.append(array[i]);
    }
    for (int i = 0; i < other.realSize; ++i) {
        concat.append(other.array[i]);
    }
    return concat;
}

DynArrayExtended &DynArrayExtended::operator>>(unsigned int shift) {
    shift %= realSize;
    if (shift == 0) {
        return *this;
    }
    auto* head = new double[realSize - shift];
    for (int i = 0; i < realSize - shift; ++i) {
        head[i] = array[i];
    }
    for (int i = 0; i < shift; ++i) {
        array[i] = array[realSize - shift + i];
    }
    for (int i = 0; i < realSize - shift; ++i) {
        array[shift + i] = head[i];
    }
    return *this;
}

DynArrayExtended &DynArrayExtended::operator<<(unsigned int shift) {
    shift %= realSize;
    if (shift == 0) {
        return *this;
    }
    auto* head = new double[shift];
    for (int i = 0; i < shift; ++i) {
        head[i] = array[i];
    }
    for (int i = 0; i < realSize - shift; ++i) {
        array[i] = array[shift + i];
    }
    for (int i = realSize - shift; i < realSize; ++i) {
        array[i] = head[i - (realSize - shift)];
    }
    return *this;
}
