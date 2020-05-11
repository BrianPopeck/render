#pragma once
#include "Image.h"

#include <memory>

class Camera {
public:
    virtual void render(Image&) const {};
};
