//
// Created by yawkar on 03.10.22.
//
#include <iostream>
#include "2_1_simple_bubble_sort_with_new_operator.h"

void getSeriesSortItAndPrint() {
    int* arraySize = new int;
    std::cin >> *arraySize;
    auto* array = new long long[*arraySize];
    for (int i = 0; i < *arraySize; ++i) {
        std::cin >> array[i];
    }
    for (int i = 0; i < *arraySize; ++i) {
        for (int j = 0; j < *arraySize - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                long long temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < *arraySize; ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
    delete arraySize;
    delete[] array;
}
