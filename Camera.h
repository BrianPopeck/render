#pragma once
#include "Image.h"

class Camera {
public:
    virtual void render(Image) const;
};
