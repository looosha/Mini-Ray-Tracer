#include <cassert>
#include "../color.h"
#include "../vector3d.h"

unsigned char Color::to_discrete(double d) {
    return static_cast <unsigned char> (d * 255.99);
}

double Color::to_continuous(unsigned char c) {
    return static_cast <double> (c / 256.0);
}

Color::Color() : Tuple3f() {}

Color::Color(double r, double g, double b) : Tuple3f(r, g, b) {}

Color::Color(int r, int g, int b)  {
    assert(r < 256 && g < 256 && g < 256);
    x = to_continuous(r);
    y = to_continuous(g);
    z = to_continuous(b);
}

Color Color::operator + (const Color &rhs) const {
    return Color(x + rhs.x, y + rhs.y, z + rhs.z);
}

Color Color::operator / (double c) const {
    return Color(x / c,  y / c, z / c);
}


void Color::setR(int r) {this->x = to_continuous(r);}

void Color::setG(int g) {this->y = to_continuous(g);}

void Color::setB(int b) {this->z = to_continuous(b);}

Color::operator class Vector3d() {
    return {x, y, z};
}

Color operator * (const Color &col, double c) {
    return Color(c * col.x, c * col.y, c * col.z);
}

Color operator * (double c, const Color &col) {
    return Color(c * col.x, c * col.y, c * col.z);
}