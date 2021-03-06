#include "Image.h"

#include <iostream>
#include <fstream>

Image::Image() {}

std::shared_ptr<Image> Image::create() {
    return std::shared_ptr<Image>(new Image());
}

void Image::saveToDisk(std::string& filename) const {
    std::ofstream file;
    file.open(filename);

    if (!file.is_open()) {
        std::cout << "Could not open file " << filename << " for writing\n";
        exit(1);
    }

    file << "P3\n" << this->width << " " << this->height << "\n255\n";  // header for PPM file with RGB values in [0,255]

    // PPM file format expects pixels to be listed row-wise (i.e. iterate through row, then move onto next row down)
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            file << int(buffer[x][y].r) << " " << int(buffer[x][y].g) << " " << int(buffer[x][y].b) << "\n";
        }
    }
}

void Image::setPixel(int x, int y, const Color3& color) {
    buffer[x][y] = color;
}
