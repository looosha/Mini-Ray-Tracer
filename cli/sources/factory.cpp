#include "../factory.h"

Shape* ShapeFactory::produce(const std::string &type, const std::vector <double> &args) {
    Shape *result = nullptr;
    if (type == "Sphere") {
        result = new Sphere(Vector3d(args[0], args[1], args[2]), args[3]);
    }
    return result;
}

Material* MaterialFactory::produce(const std::string &type, const std::vector <double> &args) {
    Material* result = nullptr;
    if (type == "Lambertian") {
        result = new Lambertian(Color(args[0], args[1], args[2]));
    }
    if (type == "Metal") {
        result = new Metal(Color(args[0], args[1], args[2]), args[3]);
    }
    if (type == "Dielectric") {
        result = new Dielectric(args[0]);
    }
    return result;
}