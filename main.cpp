#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "external/stb_image_write.h"
#include <vector>

void gen_gradient() {
    const int width = 500;
    const int height = 300;
    const int comp = 3;

    std::vector <unsigned char> image(width * height * comp);

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            int cell = i * height * comp + j * comp;
            image[cell + 0] = (float(i) / width) * 256;
            image[cell + 1] = (float(j) / height) * 256;
            image[cell + 2] = image[cell + 0] + image[cell + 1];
        }
    }

    stbi_write_png("img.png", width, height, comp, image.data(), height * comp);
}

int main() {
    gen_gradient();
    return 0;
}