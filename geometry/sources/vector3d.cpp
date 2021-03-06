#include <cmath>
#include <stdexcept>
#include "../vector3d.h"
#include "../../util/util.h"
#include "../color.h"

Vector3d::Vector3d() : Tuple3f() {}

Vector3d::Vector3d(double x, double y, double z) : Tuple3f(x, y, z) {}

double Vector3d::norm() const {
    return std::sqrt(x * x + y * y + z * z);
}

const double& Vector3d::operator [] (int index) const {
    switch(index) {
        case 0: return x;
        case 1: return y;
        case 2: return z;
        default: throw std::range_error("received value out of range");
    }
}

double& Vector3d::operator [] (int index) {
    return const_cast <double &> (static_cast <const Vector3d *> (this) -> operator[](index));
}

Vector3d Vector3d::operator -() const {
    return Vector3d(-x, -y, -z);
}

Vector3d Vector3d::operator + (const Vector3d &rhs) const {
    return Vector3d(x + rhs.x, y + rhs.y, z + rhs.z);
}

Vector3d Vector3d::operator - (const Vector3d &rhs) const {
    return Vector3d(x - rhs.x, y - rhs.y, z - rhs.z);
}

Vector3d Vector3d::operator / (double c) const {
    return Vector3d(x / c,  y / c, z / c);
}

double Vector3d::operator * (const Vector3d &rhs) const {
    return x * rhs.x + y * rhs.y + z * rhs.z;
}

Vector3d Vector3d::operator ^ (const Vector3d &rhs) const {
    Vector3d v;
    v.setX(y * rhs.z - z * rhs.y);
    v.setY(z * rhs.x - x * rhs.z);
    v.setZ(x * rhs.y - y * rhs.x);
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

Vector3d operator * (const Vector3d &vec, double c) {
    return Vector3d(c * vec.x, c * vec.y, c * vec.z);
}

Vector3d operator * (double c, const Vector3d &vec) {
    return Vector3d(c * vec.x, c * vec.y, c * vec.z);
}

std::ostream & operator << (std::ostream &out, const Vector3d &vec) {
    out << "(" << vec.x << " " << vec.y << " " << vec.z << ")";
    return out;
}

double getAngle(const Vector3d &v1, const Vector3d &v2) {
    if (utils::floatcmp::isEqual(v1.norm(), 0.0) || utils::floatcmp::isEqual(v2.norm(), 0.0))
        throw std::logic_error("Angle is defined only for vectors of non-zero length");
    return acos ((v1 * v2) / (v1.norm() * v2.norm()));
}

Vector3d::operator class Color() {
    return {x, y, z};
}