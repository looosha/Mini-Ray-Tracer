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
    static std::mt19937 random_engine;
    std::uniform_real_distribution <double> distribution(lb, rb);
    return distribution(random_engine);
}

int utils::genIntRandom(int lb, int rb) {
    static std::mt19937 random_engine;
    std::uniform_int_distribution <int> distribution(lb, rb);
    return distribution(random_engine);
}

bool utils::floatcmp::fraction::operator < (const fraction &rhs) const {
    return isLess(numerator * rhs.denominator, rhs.numerator * denominator);
}

Vector3d utils::random_inside_unit_disk() {
    Vector3d point;
    do {
        /**
         * Get a random point inside the square [-1, 1] x [-1, 1] x [0, 0].
         */
        point = Vector3d(utils::genRandom(-1, 1), utils::genRandom(-1, 1), 0);
    }
    /**
     * Check whether this random point is inside the unit disk on the x-y plane centered at the origin and has sufficient length.
     */
    while (!utils::floatcmp::isLess(point.norm(), 1.0) || !utils::floatcmp::isGreater(point.norm(), 0.1));

    return point;
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