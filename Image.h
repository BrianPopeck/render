// Only supports PPM image format

#pragma once

#include "Color3.h"
#include <memory>
#include <string>

class Image {
public:
    static std::shared_ptr<Image> create();
    void saveToDisk(std::string&) const;
    void setPixel(int x, int y, const Color3& color);

    static const int height = 600;
    static const int width = 800;

protected:
    Image();

private:
    Color3 buffer [width][height];
};
