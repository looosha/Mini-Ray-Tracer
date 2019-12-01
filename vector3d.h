#ifndef MINI_RAY_TRACER_VECTOR3D_H
#define MINI_RAY_TRACER_VECTOR3D_H

#include "tuple3f.h"

class Vector3d : public Tuple3f {
public:
    ///constructors
    Vector3d();
    Vector3d(double x, double y, double z);

    ///accessors
    inline double norm() const; ///vector norm
    Vector3d operator - () const; ///negation

    Vector3d operator + (const Vector3d &rhs) const; ///summation
    Vector3d operator - (const Vector3d &rhs) const; ///difference
    Vector3d operator / (double c) const; ///division by a scalar
    double operator * (const Vector3d &rhs) const; ///dot product
    Vector3d operator ^ (const Vector3d &rhs) const; ///cross product

    ///mutators
    Vector3d operator += (const Vector3d &rhs); ///summation assignment
    Vector3d operator -= (const Vector3d &rhs); ///difference assignment
    Vector3d operator *= (double c); ///multiplication by a scalar assignment
    Vector3d operator /= (double c); ///division by a scalar assignment
    Vector3d operator ^= (const Vector3d &rhs); ///cross product assignment

    explicit operator class Color(); ///conversion to the Color class
};

Vector3d operator * (double c, const Vector3d &vec); ///left multiplication by a scalar
Vector3d operator * (const Vector3d &vec, double c); ///right multiplication by a scalar

double getAngle(const Vector3d &v1, const Vector3d &v2); ///angle between two vectors in radians

#endif // MINI_RAY_TRACER_VECTOR3D_H