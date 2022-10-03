//
// Created by yawkar on 03.10.22.
//
#include <iostream>
#include "1_3_prime_numbers.h"

void printPrimeNumbers() {
    for (int i = 2; i < 100; ++i) {
        bool isPrime = true;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) std::cout << i << std::endl;
    }
}
