#pragma once

// Holds geometry and light source data for a scene to render
#include <memory>
#include "IndexedTriangleList.h"

class Scene {
public:
    static std::shared_ptr<Scene> create();
    
    IndexedTriangleList geometry;

protected:
    Scene();
};
