//
// Created by yawkar on 03.10.22.
//
#include <iostream>
#include "2_3_templated_2_2.h"
#include "../1/1_6_is_latin_char.h"

template<class T>
void bubbleSortAndPrint(int arraySize, T* array) {
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

template<>
void bubbleSortAndPrint(int arraySize, char* array) {
    for (int i = 0; i < arraySize; ++i) {
        for (int j = 0; j < arraySize - i - 1; ++j) {
            if (isLatin(array[j]) && isLatin(array[j + 1]) && tolower(array[j]) > tolower(array[j + 1])
            ||  !isLatin(array[j])) {
                auto temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    for (int i = arraySize - 1; i >= 0; --i) {
        if (!isLatin(array[i])) {
            array[i] = ' ';
        } else {
            break;
        }
    }
    for (int i = 0; i < arraySize; ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

void getSeriesSortItAndPrintTemplated() {
    std::cout << "Please, choose the preferred type of elements: double (1) or char (2)" << std::endl;
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
        auto* charArray = new char[*arraySize];
        for (int i = 0; i < *arraySize; ++i) {
            std::cin >> charArray[i];
        }
        bubbleSortAndPrint(*arraySize, charArray);
        delete[] charArray;
    }
    delete arraySize;
}
