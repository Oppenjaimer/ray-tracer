#ifndef VEC3_H
#define VEC3_H

#include <stdio.h>

typedef struct {
    double e[3];
} Vec3;

typedef Vec3 Point3;

Vec3 vec3_zero();
Vec3 vec3_new(double e0, double e1, double e2);

double vec3_x(Vec3 v);
double vec3_y(Vec3 v);
double vec3_z(Vec3 v);
double vec3_get(Vec3 v, int i);
double vec3_length(Vec3 v);

Vec3 vec3_negate(Vec3 v);
Vec3 vec3_add(Vec3 v1, Vec3 v2);
Vec3 vec3_subtract(Vec3 v1, Vec3 v2);
Vec3 vec3_multiply(Vec3 v1, Vec3 v2);
Vec3 vec3_scale(Vec3 v, double t);
Vec3 vec3_divide(Vec3 v, double t);

double vec3_dot(Vec3 v1, Vec3 v2);
Vec3 vec3_cross(Vec3 v1, Vec3 v2);
Vec3 vec3_normalize(Vec3 v);

void vec3_print(FILE *stream, Vec3 v);

#endif