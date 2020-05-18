#pragma once
#include "Image.h"
#include "Vector3.h"
#include "Scene.h"

#include <memory>

class Camera {
public:
    virtual void render(Scene&, Image&) const {};   // renders Scene to Image
protected:
    Camera();
    Vector3 position;
};
