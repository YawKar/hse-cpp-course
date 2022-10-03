//
// Created by yawkar on 03.10.22.
//
#include <iostream>
#include "1_4_binary_representation.h"

void printBinaryRepresentation(unsigned long long number) {
    bool was = false;
    for (int bitPos = 63; bitPos > -1; --bitPos) {
        unsigned int bit = ((number >> bitPos) & 1UL);
        if (bit) was = true;
        if (was) std::cout << bit;
    }
    if (!was) std::cout << 0;
    std::cout << std::endl;
}
