#include "../util.h"

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

Vector3d utils::random_inside_unit_sphere() {
    Vector3d point;
    do {
        /**
         * Get a random point inside the cube [-1, 1] x [-1, 1] x [-1, 1].
         */
        point = Vector3d(utils::genRandom(-1, 1), utils::genRandom(-1, 1), utils::genRandom(-1, 1));
    }
    /**
     * Check whether this random point is inside the unit sphere centered at the origin and has sufficient length.
     */
    while (!utils::floatcmp::isLess(point.norm(), 1.0) || !utils::floatcmp::isGreater(point.norm(), 0.1));

    return point;
}