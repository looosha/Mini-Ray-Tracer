#include "tuple3f.h"

class Color : public Tuple3f {
    static char to_discrete(double);
    static double to_continuous(char);
public:
    ///constructors
    Color();
    Color(double r, double g, double b);
    Color(int r, int g, int b);

    ///accessors
    char getR() const;
    char getG() const;
    char getB() const;

    Color operator + (const Color &rhs) const; ///addition
    Color operator / (double c) const; ///division by a scalar

    ///setters
    void setR(int);
    void setG(int);
    void setB(int);
};

Color operator * (double c, const Color &col); ///left multiplication by a scalar
Color operator * (const Color &col, double c); ///right multiplication by a scalar