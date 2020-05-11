#pragma once

class Vector3 {
public:
    Vector3();
    Vector3(float xx, float yy, float zz);
    void unit();
    
    float x;
    float y;
    float z;
};
