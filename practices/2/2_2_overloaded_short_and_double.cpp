//
// Created by yawkar on 03.10.22.
//
#include <iostream>
#include "2_2_overloaded_short_and_double.h"

void bubbleSortAndPrint(int arraySize, double* array) {
    for (int i = 0; i < arraySize; ++i) {
        for (int j = 0; j < arraySize - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                auto temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < arraySize; ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

void bubbleSortAndPrint(int arraySize, short* array) {
    for (int i = 0; i < arraySize; ++i) {
        for (int j = 0; j < arraySize - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                auto temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < arraySize; ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

void getSeriesSortItAndPrintOverloaded() {
    std::cout << "Please, choose the preferred type of elements: double (1) or short (2)" << std::endl;
    int choice = -1;
    std::cin >> choice;
    if (choice != 1 && choice != 2) {
        std::cout << "Unknown type: " << choice << ". Exiting..." << std::endl;
        return;
    }
    int* arraySize = new int;
    std::cin >> *arraySize;
    if (choice == 1) {
        auto* doubleArray = new double[*arraySize];
        for (int i = 0; i < *arraySize; ++i) {
            std::cin >> doubleArray[i];
        }
        bubbleSortAndPrint(*arraySize, doubleArray);
        delete[] doubleArray;
    } else {
        auto* shortArray = new short[*arraySize];
        for (int i = 0; i < *arraySize; ++i) {
            std::cin >> shortArray[i];
        }
        bubbleSortAndPrint(*arraySize, shortArray);
        delete[] shortArray;
    }
    delete arraySize;
}
