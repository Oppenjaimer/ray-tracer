#ifndef RAY_H
#define RAY_H

#include "vec3.h"

typedef struct {
    Point3 orig;
    Vec3 dir;
} Ray;

Ray ray_new(Point3 orig, Vec3 dir);

Point3 ray_origin(Ray *r);
Vec3 ray_direction(Ray *r);

Point3 ray_at(Ray *r, double t);

#endif