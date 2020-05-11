#pragma once
#include "Image.h"
#include "Vector3.h"

#include <memory>

class Camera {
public:
    virtual void render(Image&) const {};
protected:
    Camera();
    Vector3 position;
};
