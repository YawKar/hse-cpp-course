//
// Created by yawkar on 03.10.22.
//
#include <iostream>
#include <cmath>
#include "1_2_quadratic_equation.h"

void solveQuadraticEquation(long long int a, long long int b, long long int c) {
    long long discriminant = b * b - 4LL * a * c;
    if (discriminant < 0) {
        std::cout << "Discriminant's less than zero: no roots" << std::endl;
    } else {
        long double firstRoot = (-b - sqrtl(discriminant)) / 2.0 / a;
        long double secondRoot = (-b + sqrtl(discriminant)) / 2.0 / a;
        std::cout << "Roots are: " << firstRoot << " and " << secondRoot << std::endl;
    }
}
