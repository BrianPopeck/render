#pragma once
#include "Camera.h"

class PinholeCamera : public Camera {
public:
    virtual void render(Image&) const;
    static std::shared_ptr<PinholeCamera> create();
protected:
    float z_near;
};
