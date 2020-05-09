#pragma once
#include "Camera.h"

class PinholeCamera : public Camera {
public:
    virtual void render(Image&) const;
};
