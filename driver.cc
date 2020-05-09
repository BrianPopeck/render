#include "Image.h"

int main()
{
    std::shared_ptr<Image> img = Image::create();

    std::string filename = std::string("myimage.ppm");

    img->saveToDisk(filename);

    return 0;
}