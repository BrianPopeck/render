#include "Image.h"
#include "Camera.h"
#include "PinholeCamera.h"

int main()
{
    std::shared_ptr<Image> img = Image::create();
    std::shared_ptr<Camera> camera = PinholeCamera::create();

    std::string filename = std::string("myimage.ppm");

    camera->render(*img);

    img->saveToDisk(filename);

    return 0;
}