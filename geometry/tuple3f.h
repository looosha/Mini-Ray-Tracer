#ifndef MINI_RAY_TRACER_TUPLE3F_H
#define MINI_RAY_TRACER_TUPLE3F_H

/**
 * A tuple of 3 floating point values
 * Intended to be used as a base class
*/
class Tuple3f {
protected:
    double x, y, z;
public:
    Tuple3f();
    Tuple3f(double f1, double f2, double f3);

    ///accessors
    inline double getX() const {return x;}
    inline double getY() const {return y;}
    inline double getZ() const {return z;}

    ///mutators
    void setX(double);
    void setY(double);
    void setZ(double);
};

#endif // MINI_RAY_TRACER_TUPLE3F_H