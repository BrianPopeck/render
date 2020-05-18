#include "App.h"

Vector3 App::L_i(const Ray& ray, const Scene& scene) {
    int num_triangles = scene.geometry.size();

    float b[3];
    float t;

    for (int i = 0; i < num_triangles; i++) {
        // if intersection, white pixel
        if (ray.triangleIntersect(scene.geometry.getTriangle(i), b, t)) {
            return Vector3(1.0f, 1.0f, 1.0f);
        }
    }
    
    // if no intersection, black pixel
    return Vector3(0.0f, 0.0f, 0.0f);
}
