#include "1_1_factorial.h"

long long factorialRecursive(long long number) {
    return number == 0LL ? 1LL : number * factorialRecursive(number - 1LL);
}

long long factorialIterative(long long number) {
    long long result = 1LL;
    while (number--) result *= (number + 1);
    return result;
}