#include "Color3.h"

Color3::Color3() {}

// convert radiance to color
Color3::Color3(Vector3& radiance) {
    // simple conversion from [0,1] radiance scale for each frequency to [0,255] RGB scale
    r = radiance.x * 255;
    g = radiance.y * 255;
    b = radiance.z * 255;
}
