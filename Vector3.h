#pragma once

class Vector3 {
public:
    Vector3();
    Vector3(float xx, float yy, float zz);

    Vector3 operator+(const Vector3& rhs) const;
    Vector3 operator-(const Vector3& rhs) const;
    Vector3 operator*(float a) const;
    Vector3 operator/(float a) const;

    Vector3 unit() const;
    float dot(const Vector3& rhs) const;
    Vector3 cross(const Vector3& rhs) const;
    
    float x;
    float y;
    float z;
};
