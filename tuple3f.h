///A class supporting a tuple of 3 floating point values
///Intended to be used as a base class

class Tuple3f {
protected:
    double x, y, z;
public:
    Tuple3f();
    Tuple3f(double f1, double f2, double f3);

    ///accessors
    double getX() const;
    double getY() const;
    double getZ() const;

    ///mutators
    void setX(double);
    void setY(double);
    void setZ(double);

    Tuple3f operator & (int x);
    double& operator [] (int index); ///return a reference to member #index
};