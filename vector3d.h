class Vector3d {
private:
    double x, y, z;
public:
    ///constructors
    Vector3d();

    Vector3d(double x, double y, double z);

    ///accessors
    double getX() const;

    double getY() const;

    double getZ() const;

    double norm() const;

    double operator[](int dim_id) const;

    ///mutators
    void setX(double x);

    void setY(double y);

    void setZ(double z);

    ///operators
    Vector3d operator -() const; ///negation

    Vector3d operator + (const Vector3d &rhs) const; ///summation

    Vector3d operator - (const Vector3d &rhs) const; ///difference

    Vector3d operator * (double c) const; ///multiplication by a scalar

    double operator * (const Vector3d &rhs) const; ///dot product

    Vector3d operator ^ (const Vector3d &rhs) const; ///cross product
};

double getAngle(const Vector3d &v1, const Vector3d &v2); ///angle between two vectors in radians