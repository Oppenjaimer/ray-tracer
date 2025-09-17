#include "ray.h"

Ray ray_new(Point3 orig, Vec3 dir) {
    return (Ray){ .orig = orig, .dir = dir };
}

Point3 ray_origin(Ray *r) {
    return r->orig;
}

Vec3 ray_direction(Ray *r) {
    return r->dir;
}

Point3 ray_at(Ray *r, double t) {
    return vec3_add(r->orig, vec3_scale(r->dir, t));
}
