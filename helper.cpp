#include "helper.h"

bool FloatComparison::is_less(double lhs, double rhs) {
    return rhs - lhs > FloatComparison::EPS;
}

bool FloatComparison::is_greater(double lhs, double rhs) {
    return rhs - lhs < FloatComparison::EPS;
}

bool FloatComparison::is_equal(double lhs, double rhs) {
    return !is_less(lhs, rhs) && !is_greater(lhs, rhs);
}