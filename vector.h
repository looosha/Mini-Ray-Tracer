
class vector3d {
    double x, y, z;

    vector3d operator + (const vector3d &rhs);
    double operator * (const vector3d &rhs);
    vector3d operator ^ (const vector3d &rhs);
};