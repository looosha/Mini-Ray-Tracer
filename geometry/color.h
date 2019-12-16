#ifndef MINI_RAY_TRACER_COLOR_H
#define MINI_RAY_TRACER_COLOR_H

#include "tuple3f.h"

/**
 * Store a color under an 8-bit RGB scheme
 * Each value might be regarded as an 0-255 integer or a 0-1 real number
 * Supports simple arithmetic
 */
class Color : public Tuple3f {
    static unsigned char to_discrete(double);
    static double to_continuous(unsigned char);
public:
    ///constructors
    Color();
    Color(double x, double y, double z);
    Color(int r, int g, int b);

    ///accessors
    inline unsigned char getR() const {return to_discrete(x);}
    inline unsigned char getG() const {return to_discrete(y);}
    inline unsigned char getB() const {return to_discrete(z);}

    Color operator + (const Color &rhs) const; ///addition
    Color operator / (double c) const; ///division by a scalar

    ///setters
    void setR(int);
    void setG(int);
    void setB(int);

    explicit operator class Vector3d();///conversion to the Vector3d class

    friend Color operator * (double c, const Color &col); ///left multiplication by a scalar
    friend Color operator * (const Color &col, double c); ///right multiplication by a scalar
};

#endif // MINI_RAY_TRACER_COLOR_H