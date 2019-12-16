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

/**
 * A c++11 random based on Mersenne-Twister random engine
 */
double utils::genRandom(double lb, double rb) {
    static std::mt19937 random_engine;
    std::uniform_real_distribution <double> distribution(lb, rb);
    return distribution(random_engine);
}

/**
 * A c++11 random based on Mersenne-Twister random engine
 */
int utils::genIntRandom(int lb, int rb) {
    static std::mt19937 random_engine;
    std::uniform_int_distribution <int> distribution(lb, rb);
    return distribution(random_engine);
}

bool utils::floatcmp::fraction::operator < (const fraction &rhs) const {
    return isLess(numerator * rhs.denominator, rhs.numerator * denominator);
}

/**
 * Produces a random point inside thesquare [-1, 1] x [-1, 1] x [0, 0]
 * Then checks whether this random point is inside the x-y unit disk centered at the origin and has sufficient length.
 */
Vector3d utils::random_inside_unit_disk() {
    Vector3d point;
    do {
        point = Vector3d(utils::genRandom(-1, 1), utils::genRandom(-1, 1), 0);
    }
    while (!utils::floatcmp::isLess(point.norm(), 1.0) || !utils::floatcmp::isGreater(point.norm(), 0.1));

    return point;
}

/**
 * Produces a random point inside the cube [-1, 1] x [-1, 1] x [-1, 1]
 * Then checks whether this random point is inside the unit sphere centered at the origin and has sufficient length.
 */
Vector3d utils::random_inside_unit_sphere() {
    Vector3d point;
    do {
        point = Vector3d(utils::genRandom(-1, 1), utils::genRandom(-1, 1), utils::genRandom(-1, 1));
    }
    while (!utils::floatcmp::isLess(point.norm(), 1.0) || !utils::floatcmp::isGreater(point.norm(), 0.1));

    return point;
}