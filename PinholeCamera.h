#pragma once
#include "Camera.h"
#include "Ray.h"

#include <cmath>

class PinholeCamera : public Camera {
public:
    virtual void render(Scene&, Image&) const;
    static std::shared_ptr<PinholeCamera> create();
protected:
    PinholeCamera();
    void getPrimaryRay(float x, float y, int img_width, int img_height, Ray& ray) const;

    float z_near = -1e-3;   // location of image plane, small negative value
    float vertical_fov = 1.0471975512f; // pi / 3 radians, results in horizontal fov of about pi / 2
};
