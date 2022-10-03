//
// Created by yawkar on 03.10.22.
//
#include <limits>
#include <cmath>
#include "1_5_sum_series_with_precision.h"

long double sumWithPrecision(long double scaleFactor, long double commonRatio, long double eps) {
    long double difference = std::numeric_limits<long double>::infinity();
    long double sum = 0;
    long long power = 0;
    while (difference > eps) {
        difference = scaleFactor * powl(commonRatio, power);
        sum += difference;
        ++power;
    }
    return sum;
}
