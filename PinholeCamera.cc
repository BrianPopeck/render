#include "PinholeCamera.h"
#include "App.h"

#include <cmath>

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
            Ray camera_ray;
            getPrimaryRay(float(x) + 0.5f, float(y) + 0.5f, width, height, camera_ray); // get ray to center of current pixel

            // if that ray hits an object, return white, else return black
            Vector3 radiance = App::L_i(camera_ray);
            img.setPixel(x, y, Color3(radiance));
        }
    }
    return;
}

void PinholeCamera::getPrimaryRay(float x, float y, int img_width, int img_height, Ray& ray) const {
    // start ray from camera position
    ray.P = this->position;

    const float side = -2.0f * tanf(vertical_fov / 2.0f);   // negative of side length of square at z = -1 where the angle from the top and bottom of the square to the origin is given by vertical_fov

    // center image plane at (0,0,-1), height of one unit and scale width accordingly by aspect ratio
    ray.w = Vector3(    z_near * (x / img_width - 0.5f) * side * img_width / img_height,
                        z_near * -(y / img_height - 0.5f) * side,   // flip y-coordinate because up is positive in 3D axis, down is positive in 2D axis
                        z_near);

    ray.w.unit();   // use unit rays for more interpretable times of intersection during tracing
}
