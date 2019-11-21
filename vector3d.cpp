#include <cmath>
#include "vector3d.h"

Vector3d::Vector3d() {
    x = y = z = 0.0;
}

Vector3d::Vector3d(double x, double y, double z): x(x), y(y), z(z) {}

double Vector3d::getX() const {return x;}

double Vector3d::getY() const {return y;}

double Vector3d::getZ() const {return z;}

double Vector3d::norm() const {
    return sqrt(x * x + y * y + z * z);
}

double Vector3d::operator[](int dim_id) const{
    switch(dim_id) {
        case 0: return x; break;
        case 1: return y; break;
        default: return z;
    }
}

void Vector3d::setX(double x) {this->x = x;}

void Vector3d::setY(double y) {this->y = y;}

void Vector3d::setZ(double z) {this->z = z;}

Vector3d Vector3d::operator -() const {
    Vector3d v(-x, -y, -z);
    return v;
}

Vector3d Vector3d::operator + (const Vector3d &rhs) const {
    Vector3d v(x + rhs.getX(), y + rhs.getY(), z + rhs.getZ());
    return v;
}

Vector3d Vector3d::operator - (const Vector3d &rhs) const {
    Vector3d v(x - rhs.getX(), y - rhs.getY(), z - rhs.getZ());
    return v;
}

Vector3d Vector3d::operator * (double c) const {
    Vector3d v(c * x, c * y, c * z);
    return v;
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

double getAngle(const Vector3d &v1, const Vector3d &v2) {
    return acos ((v1 * v2) / (v1.norm() * v2.norm()));
}
