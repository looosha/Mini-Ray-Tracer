#ifndef MINI_RAY_TRACER_UTIL_H
#define MINI_RAY_TRACER_UTIL_H

///Compilation of useful tools
#include <limits>
#include <random>
#include "../geometry/vector3d.h"

namespace utils {
    namespace floatcmp {
        const double EPS = 1e-7;

        bool isLess(double lhs, double rhs);

        bool isGreater(double lhs, double rhs);

        bool isEqual(double lhs, double rhs);
    };

    double genRandom(double = 0, double = std::numeric_limits <double>::max());

    Vector3d random_inside_unit_sphere();
}

#endif // MINI_RAY_TRACER_UTIL_H