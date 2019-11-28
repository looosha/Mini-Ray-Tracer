#include <cassert>
#include "color.h"

char Color::to_discrete(double d) {
    return char(d * 255.99);
}

double Color::to_continuous(char c) {
    return double(c / 256.0);
}

Color::Color() : Tuple3f() {}

Color::Color(double r, double g, double b) : Tuple3f(r, g, b) {}

Color::Color(int r, int g, int b)  {
    assert(r < 256 && g < 256 && g < 256);
    x = to_continuous(r);
    y = to_continuous(g);
    z = to_continuous(b);
}

char Color::getR() const {return to_discrete(x);}

char Color::getG() const {return to_discrete(y);}

char Color::getB() const {return to_discrete(z);}

Color Color::operator + (const Color &rhs) const {
    return Color(x + rhs.getX(), y + rhs.getY(), z + rhs.getZ());
}

Color Color::operator / (double c) const {
    return Color(x / c,  y / c, z / c);
}


void Color::setR(int r) {this->x = to_continuous(r);}

void Color::setG(int g) {this->y = to_continuous(g);}

void Color::setB(int b) {this->z = to_continuous(b);}

Color operator * (const Color &col, double c) {
    return Color(c * col.getX(), c * col.getY(), c * col.getZ());
}

Color operator * (double c, const Color &col) {
    return Color(c * col.getX(), c * col.getY(), c * col.getZ());
}