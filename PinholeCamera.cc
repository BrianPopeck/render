#include "PinholeCamera.h"

PinholeCamera::PinholeCamera() {}

std::shared_ptr<PinholeCamera> PinholeCamera::create() {
    return std::shared_ptr<PinholeCamera>(new PinholeCamera());
}

void PinholeCamera::render(Image& img) const {
    const int width = img.width;
    const int height = img.height;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // find ray from pinhole to center of pixel

            // if that ray hits an object, return white, else return black
        }
    }
    return;
}

void PinholeCamera::getPrimaryRay(float x, float y, int img_width, int img_height, Ray& ray) {
    // start ray from camera position
    ray.P = this->position;

    // 
}
