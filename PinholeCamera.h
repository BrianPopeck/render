#pragma once
#include "Camera.h"
#include "Ray.h"

class PinholeCamera : public Camera {
public:
    virtual void render(Image&) const;
    static std::shared_ptr<PinholeCamera> create();
protected:
    PinholeCamera();
    float z_near = -1e-3;   // location of image plane, small negative value
    void getPrimaryRay(float x, float y, int img_width, int img_height, Ray& ray);
};
