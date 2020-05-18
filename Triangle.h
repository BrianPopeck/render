#pragma once

#include "Vector3.h"

class Triangle {
public:
    Triangle(const Vector3& p0, const Vector3& p1, const Vector3& p2);
    const Vector3& getVertex(int i) const;

private:
    Vector3 vertices[3];
};
