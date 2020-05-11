#include "Vector3.h"

#include <cmath>

Vector3::Vector3() {}

Vector3::Vector3(float xx, float yy, float zz) : x(xx), y(yy), z(zz) {}

void Vector3::unit() {
    float magnitude = sqrtf(x*x + y*y + z*z);

    x = x / magnitude;
    y = y / magnitude;
    z = z / magnitude;
}
