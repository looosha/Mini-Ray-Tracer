#include "../tuple3f.h"
#include <stdexcept>

Tuple3f::Tuple3f(): x(0.0), y(0.0), z(0.0) {}

Tuple3f::Tuple3f(double x, double y, double z) : x(x), y(y), z(z) {}


double Tuple3f::getX() const {return x;}

double Tuple3f::getY() const {return y;}

double Tuple3f::getZ() const {return z;}

void Tuple3f::setX(double x) {this->x = x;}

void Tuple3f::setY(double y) {this->y = y;}

void Tuple3f::setZ(double z) {this->z = z;}


double& Tuple3f::operator [] (int index) {
    switch(index) {
        case 0: return x;
        case 1: return y;
        case 2: return z;
        default: throw std::range_error("received value out of range");
    }
}
