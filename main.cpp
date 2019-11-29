#include <string>
#include <vector>

#include <iostream>

#include "color.h"
#include "sphere.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "external/stb_image_write.h"

class Image {
    const int width;
    const int height;
    std::vector <std::vector <Color>> pixels;
public:
    Image(int w, int h) : width(w), height(h), pixels(h, std::vector <Color> (w)) {}

    void set(int x, int y, Color col) {
        pixels[y][x] = col;
    }

    void write_to_file(std::string filename) const {
        std::vector <unsigned char> serialized(width * height * 3);

        for (int y = height - 1; y >= 0; --y) {
            for (int x = 0; x < width; ++x) {
                int cell = y * width * 3 + x * 3;
                serialized[cell + 0] = pixels[y][x].getR();
                serialized[cell + 1] = pixels[y][x].getG();
                serialized[cell + 2] = pixels[y][x].getB();
            }
        }

        stbi_write_png("img.png", width, height, 3, serialized.data(), width * 3);
    }
};

std::ostream & operator << (std::ostream &out, const Color &c) {
    out << "(" << int(c.getR()) << " " << int(c.getG()) << " " << int(c.getB()) << ")";
    return out;
}

void gen_gradient() {
    const int width = 500;
    const int height = 300;
    Image image(width, height);

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            double a = j / double(height - 1);
            double b = i / double(width - 1);
            Color col = Color(0.0, 0.0, 1.0) + a * Color(1.0, 0.0, 0.0) + (1 - b) * Color(0.0, 1.0, 0.0);
            image.set(i, j, col);
        }
    }

    image.write_to_file("img.png");
}


#include <iostream>
Color color (Sphere s, Ray r, HitRecord record) {
    if (s.hit(r, 0, 100000, record)) {
        return Color(1.0, 0.0, 0.0);
    }
    return Color(0.0, 1.0, 0.0);
}

int main() {
    //gen_gradient();

    const int width = 500;
    const int height = 300;

    Image image(width, height);

    Sphere s(Vector3d(0.0, 0.0, -100), 30);
    HitRecord record;

    for (int i = -250; i <= 249; ++i) {
        for (int j = -150; j <= 149; ++j) {
            Ray r(Vector3d(0.0, 0.0, 0.0), Vector3d((i + 0.5) / 100, (j + 0.5) / 100, -1));
            image.set(i + 250, j + 150, color(s, r, record));
        }
    }

    image.write_to_file("img.png");
}