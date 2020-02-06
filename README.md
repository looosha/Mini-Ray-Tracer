# Mini-Ray-Tracer

Mini Ray Tracer is a 3D-graphics renderer that synthesizes a photorealistic snapshot of a scene, individually tracing the path of each ray from the observer's perspective. It is a working console application where the input is a description of the 3-dimensional scene and the output is a PNG image.

This self-proposed project was created to fulfill one of the requirements of the course COMP 2012H Fall 2019 in HKUST. Implementation and algorithm behind the project were explained in the following pdf file: https://drive.google.com/file/d/1gIxRG7IrHpc7Z-HVAODMjoI7Siqgfa7-/view?usp=sharing.

## Running the tests

To run the tests it is needed to set up the 3D scene in the console by adding the spheres, AABB (axis-aligned bounding boxes) of different materials: lambertian, metal and dielectric. 

Depending on the shape, material of the objects, position of a "camera" (source of the light beams) which are default or set by the user, there will be different output images. 

## Test images

![Picture1](https://user-images.githubusercontent.com/53835037/73949200-4bf1a780-4924-11ea-8682-389d1c87bd51.png)
```
Final resolution: 1200x800
Anti-aliasing level: 100
Reflection depth: 5
Finished in 2821.56s
```

![Picture2](https://user-images.githubusercontent.com/53835037/73950408-15b52780-4926-11ea-9ff2-6376f975679f.png)
```
Final resolution: 800x600
Anti-aliasing level: 50
Reflection depth: 5
Finished in 879.54s
```

![Picture3](https://user-images.githubusercontent.com/53835037/73950745-a429a900-4926-11ea-8b5d-be7f99c675d9.png)
```
Final resolution: 800x400
Anti-aliasing level: 100
Reflection depth: 5
Finished in 125.77s
```

## Acknowledgments

The project was inspired by the <em> Ray Tracing </em> book series by Peter Shirley.
