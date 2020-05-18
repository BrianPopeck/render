#include "Ray.h"
#include <cmath>

// Returns true if and only if the triangle tri intersects the current ray. If true, stores the barycentric coordinates of the intersection point in b and the distance to the intersection point along the ray in t
// See the "Ray Casting" chapter of the Graphics Codex
bool Ray::triangleIntersect(Triangle tri, float b[3], float& t) const {
    const float epsilon = 1e-6; // precision threshold

    // get the normal of the triangle (assumes the triangle has counter-clockwise winding order)
    const Vector3& e1 = tri.getVertex(1) - tri.getVertex(0);
    const Vector3& e2 = tri.getVertex(2) - tri.getVertex(0);
    const Vector3& n = e1.cross(e2).unit();

    const Vector3& q = w.cross(e2); // orthogonal to camera ray and edge on triangle
    const float a = e1.dot(q);  // project edge on q

    // check for 1) backfacing, or close to it 2) close to limit of precision
    if ((n.dot(w) >= 0) || (abs(a) <= epsilon)) return false;

    const Vector3& s = (P - tri.getVertex(0)) / a;
    const Vector3& r = s.cross(e1);

    // compute barycentric coordinates; note that since barycentric coordinates are a convex combination for points on the triangle, they sum to one
    b[0] = s.dot(q);
    b[1] = r.dot(w);
    b[2] = 1.0f - b[0] - b[1];

    // check if intersection occurred outside of triangle
    if ((b[0] < 0.0f) || (b[1] < 0.0f) || (b[2] < 0.0f)) return false;

    t = e2.dot(r);

    // check if positive distance to intersection
    return (t >= 0.0f);
}
