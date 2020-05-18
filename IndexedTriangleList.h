#pragma once

#include <vector>
#include "Vector3.h"
#include "Triangle.h"

class IndexedTriangleList {
public:
    std::vector<Vector3> vertexList;
    std::vector<int> indexList;

    Triangle getTriangle(int i) const;
    int size() const;
};
