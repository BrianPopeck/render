#include "Triangle.h"

Triangle::Triangle(const Vector3& p0, const Vector3& p1, const Vector3& p2): vertices{p0, p1, p2} {}

const Vector3& Triangle::getVertex(int i) const {
    return vertices[i];
}
