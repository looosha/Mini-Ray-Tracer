#ifndef MINI_RAY_TRACER_FACTORY_H
#define MINI_RAY_TRACER_FACTORY_H
#include <string>
#include <vector>
#include "../runtime/object3d.h"

#include "../shapes/sphere.h"

class ShapeFactory {
public:
    Shape* produce(const std::string &type, const std::vector <double> &args);
};

#include "../materials/lambertian.h"
#include "../materials/metal.h"
#include "../materials/dielectric.h"

class MaterialFactory {
public:
    Material* produce(const std::string &type, const std::vector <double> &args);
};

#endif //MINI_RAY_TRACER_FACTORY_H
