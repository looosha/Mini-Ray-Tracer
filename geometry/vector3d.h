#ifndef MINI_RAY_TRACER_VECTOR3D_H
#define MINI_RAY_TRACER_VECTOR3D_H

#include "tuple3f.h"
#include <iostream>

/** Generic 3d-vector class
 * Supports all the according geometric and algebraic operations
 */
class Vector3d : public Tuple3f {
public:
    ///constructors
    Vector3d();
    Vector3d(double x, double y, double z);

    ///accessors
    double norm() const; ///vector norm
    const double& operator [] (int index) const; ///return the value of the member #index
    double& operator [] (int index); ///return a reference to member #index

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

    ///external
    explicit operator class Color(); ///conversion to the Color class

    friend Vector3d operator * (double c, const Vector3d &vec); ///left multiplication by a scalar
    friend Vector3d operator * (const Vector3d &vec, double c); ///right multiplication by a scalar
    friend std::ostream & operator << (std::ostream &, const Vector3d &); ///Outputs the vector to a stream

    friend double getAngle(const Vector3d &v1, const Vector3d &v2); ///angle between two vectors in radians
};

#endif // MINI_RAY_TRACER_VECTOR3D_H