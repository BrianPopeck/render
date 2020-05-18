#include "Vector3.h"

#include <cmath>

Vector3::Vector3() {}

Vector3::Vector3(float xx, float yy, float zz) : x(xx), y(yy), z(zz) {}

Vector3 Vector3::operator+(const Vector3& rhs) const {
    return Vector3(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z);
}

Vector3 Vector3::operator-(const Vector3& rhs) const {
    return Vector3(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z);
}

Vector3 Vector3::operator*(float a) const {
    return Vector3(this->x * a, this->y * a, this->z * a);
}

Vector3 Vector3::operator/(float a) const {
    return Vector3(this->x / a, this->y / a, this->z / a);
}

Vector3 Vector3::unit() const {
    float magnitude = sqrtf(x*x + y*y + z*z);
    return Vector3(x / magnitude, y / magnitude, z / magnitude);
}

float Vector3::dot(const Vector3& rhs) const {
    return this->x * rhs.x + this->y * rhs.y + this->z * rhs.z;
}

Vector3 Vector3::cross(const Vector3& rhs) const {
    float new_x = this->y * rhs.z - this->z * rhs.y;
    float new_y = this->z * rhs.x - this->x * rhs.z;
    float new_z = this->x * rhs.y - this->y * rhs.x;

    return Vector3(new_x, new_y, new_z);
}
