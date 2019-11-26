#include <string>
#include <vector>

#include "color.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "external/stb_image_write.h"

class Image {
    const int width;
    const int height;
    std::vector <std::vector <Color>> pixels;
public:
    Image(int w, int h) : width(w), height(h), pixels(w, std::vector <Color> (h)) {}

    void set(int x, int y, Color col) {
        pixels[x][y] = col;
    }

    void write_to_file(std::string filename) const {
        std::vector <unsigned char> serialized(width * height * 3);

        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                int cell = j * width * 3 + i * 3;
                serialized[cell + 0] = pixels[i][j].getR();
                serialized[cell + 1] = pixels[i][j].getG();
                serialized[cell + 2] = pixels[i][j].getB();
            }
        }

        stbi_write_png("img.png", width, height, 3, serialized.data(), height * 3);
    }
};

void gen_gradient() {
    const int width = 500;
    const int height = 300;

    Image image(width, height);

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            double c = j / double(height - 1);
            Color col;
            col[0] = 10;
            image.set(i, j, Color(1.0, 1.0, 1.0) * c + Color(0.0, 0.4, 1.0) * (1 - c));
        }
    }

    image.write_to_file("img.png");
}

int main() {
    gen_gradient();
    return 0;
}