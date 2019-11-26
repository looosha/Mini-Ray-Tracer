#include <cmath>
#include <stdexcept>
#include "vector3d.h"
#include "helper.h"

Vector3d::Vector3d() : Tuple3f() {}

Vector3d::Vector3d(double x, double y, double z) : Tuple3f(x, y, z) {}

inline double Vector3d::norm() const {
    return std::sqrt(x * x + y * y + z * z);
}

Vector3d Vector3d::operator -() const {
    return Vector3d(-x, -y, -z);
}

Vector3d Vector3d::operator + (const Vector3d &rhs) const {
    return Vector3d(x + rhs.getX(), y + rhs.getY(), z + rhs.getZ());
}

Vector3d Vector3d::operator - (const Vector3d &rhs) const {
    return Vector3d(x - rhs.getX(), y - rhs.getY(), z - rhs.getZ());
}

Vector3d Vector3d::operator * (double c) const {
    return Vector3d(c * x, c * y, c * z);
}

Vector3d Vector3d::operator / (double c) const {
    return Vector3d(x / c,  y / c, z / c);
}

double Vector3d::operator * (const Vector3d &rhs) const {
    return x * rhs.getX() + y * rhs.getY() + z * rhs.getZ();
}

Vector3d Vector3d::operator ^ (const Vector3d &rhs) const {
    Vector3d v;
    v.setX(y * rhs.getZ() - z * rhs.getY());
    v.setY(z * rhs.getX() - x * rhs.getZ());
    v.setZ(x * rhs.getY() - y * rhs.getX());
    return v;
}


Vector3d Vector3d::operator += (const Vector3d &rhs) {
    return *this = *this + rhs;
}

Vector3d Vector3d::operator -= (const Vector3d &rhs) {
    return *this = *this - rhs;
}

Vector3d Vector3d::operator *= (double c) {
    return *this = *this * c;
}

Vector3d Vector3d::operator /= (double c) {
    return *this = *this / c;
}

Vector3d Vector3d::operator ^= (const Vector3d &rhs) {
    return *this = *this ^ rhs;
}

double getAngle(const Vector3d &v1, const Vector3d &v2) {
    if (FloatComparison::is_equal(v1.norm(), 0.0) || FloatComparison::is_equal(v2.norm(), 0.0))
        throw std::logic_error("Angle is defined only for vectors of non-zero length");
    return acos ((v1 * v2) / (v1.norm() * v2.norm()));
}
