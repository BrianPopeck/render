// Only supports PPM image format

#pragma once

#include "Pixel.h"
#include <memory>
#include <vector>
#include <string>

class Image {
public:
    static std::shared_ptr<Image> create();
    void saveToDisk(std::string&) const;

protected:
    Image();

private:
    std::vector<Pixel> buffer;  // store RGB values
    static const int height = 800;
    static const int width = 600;
};
