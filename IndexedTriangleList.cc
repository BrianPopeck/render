#include "IndexedTriangleList.h"

Triangle IndexedTriangleList::getTriangle(int i) const {
    return Triangle( vertexList[indexList[3*i]],
        vertexList[indexList[3*i + 1]],
        vertexList[indexList[3*i + 2]]
    );
}

int IndexedTriangleList::size() const {
    return indexList.size() / 3;
}
