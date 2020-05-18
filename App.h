#pragma once

// rendering functions not associated with any particular object

#include "Ray.h"
#include "Scene.h"

class App {
public:
    static Vector3 L_i(const Ray& ray, const Scene& scene);
};
