# Mini-Ray-Tracer

Mini Ray Tracer is a 3D-graphics renderer that synthesizes a photorealistic snapshot of a scene, individually tracing the path of each ray from the observer's perspective. It is a working console application where the input is a description of the 3-dimensional scene and the output is a PNG image.

This self-proposed project was created to fulfill one of the requirements of the course COMP 2012H Fall 2019 in HKUST. 

## Running the tests

To run the tests it is needed to set up the scene in raytracer.cpp by adding the spheres, AABB (axis-aligned bounding boxes) of different materials: lambertian, metal and dielectric. For example,

```
scene_cache.emplace_back(new Sphere(Vector3d(0, -1000, 0), 1000), new Lambertian(Color(0.5, 0.7, 0.5)));
```

Depending on the shape, material of the objects, position of a "camera" (source of the light beams) set by the user, there will be different output images. 

### Test images

![Picture1](https://user-images.githubusercontent.com/53835037/73949200-4bf1a780-4924-11ea-8682-389d1c87bd51.png)
```
Final resolution: 1200x800
Anti-aliasing level: 100
Reflection depth: 5
Finished in 2821.56s
```


## Acknowledgments

The project was inspired by the <em> Ray Tracing </em> series of books by Peter Shirley.
