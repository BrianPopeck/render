#pragma once

#include "Vector3.h"
#include "Triangle.h"

class Ray {
public:
    Vector3 P;
    Vector3 w;

    bool triangleIntersect(Triangle tri, float b[3], float& t) const;
};
