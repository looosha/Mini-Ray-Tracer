#include "raytracer.h"

Image::Image(int w, int h) : width(w), height(h), pixels(h, std::vector <Color> (w)) {}

void Image::setPixel(int x, int y, Color col) {
    pixels[y][x] = col;
}

void Image::writeToFile(std::string filename) const {
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
