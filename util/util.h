#ifndef MINI_RAY_TRACER_UTIL_H
#define MINI_RAY_TRACER_UTIL_H

///Compilation of useful tools
#include <limits>
#include <random>
#include "../geometry/vector3d.h"

/**
 * Small general purporse utilities
 */
namespace utils {
    /**
     * @brief Avoiding precision-related comparison errors
     */
     namespace floatcmp {
        const double EPS = 1e-10;

        bool isLess(double lhs, double rhs);

        bool isGreater(double lhs, double rhs);

        bool isEqual(double lhs, double rhs);

        struct fraction {
            double numerator, denominator;

            bool operator < (const fraction &rhs) const;
        };
    };

    /**
     * @param lb The lower bound of the range
     * @param rb The upper bound of the range
     * @returns A random real number in the given range with uniform probability
     */
    double genRandom(double lb = 0, double rb = std::numeric_limits <double>::max());

    /**
     * @param lb The lower bound of the range
     * @param rb The upper bound of the range
     * @returns A random integer in the given range with uniform probability
     */
    int genIntRandom(int lb = 0, int rb = std::numeric_limits <int>::max());

    Vector3d random_inside_unit_disk();

    Vector3d random_inside_unit_sphere();
}

#endif // MINI_RAY_TRACER_UTIL_H