#include "Image.h"

#include <iostream>
#include <fstream>

Image::Image() {
    // initialize the RGB buffer for PPM file format
    this->buffer = std::vector<Pixel> (this->height*this->width);
}

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

    for (auto it = this->buffer.begin(); it != this->buffer.end(); ++it) {
        // file << it->r << " " << it->g << " " << it->b << "\n";
        file << 255 << " " << 255 << " " << 255 << "\n";
    }

}
