#include "util.h"

bool utils::floatcmp::isLess(double lhs, double rhs) {
    return rhs - lhs > utils::floatcmp::EPS;
}

bool utils::floatcmp::isGreater(double lhs, double rhs) {
    return rhs - lhs < utils::floatcmp::EPS;
}

bool utils::floatcmp::isEqual(double lhs, double rhs) {
    return !isLess(lhs, rhs) && !isGreater(lhs, rhs);
}

double utils::genRandom(double lb, double rb) {
    static std::mt19937 randomEngine;
    std::uniform_real_distribution <double> distribution(lb, rb);
    return distribution(randomEngine);
}
