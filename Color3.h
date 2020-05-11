#pragma once

#include "Vector3.h"

class Color3 {
public:
    Color3();
    Color3(Vector3& radiance);
    
    unsigned char r;
    unsigned char g;
    unsigned char b;
};
