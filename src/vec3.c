#include <math.h>

#include "vec3.h"

Vec3 vec3_zero() {
    return (Vec3){ .e = {0.0, 0.0, 0.0} };
}

Vec3 vec3_new(double e0, double e1, double e2) {
    return (Vec3){ .e = {e0, e1, e2} };
}

double vec3_x(Vec3 v) {
    return v.e[0];
}

double vec3_y(Vec3 v) {
    return v.e[1];
}

double vec3_z(Vec3 v) {
    return v.e[2];
}

double vec3_get(Vec3 v, int i) {
    return v.e[i];
}

double vec3_length(Vec3 v) {
    return sqrt(v.e[0]*v.e[0] + v.e[1]*v.e[1] + v.e[2]*v.e[2]);
}

Vec3 vec3_negate(Vec3 v) {
    return (Vec3){ .e = {-v.e[0], -v.e[1], -v.e[2]} };
}

Vec3 vec3_add(Vec3 v1, Vec3 v2) {
    return (Vec3){ .e = {v1.e[0]+v2.e[0], v1.e[1]+v2.e[1], v1.e[2]+v2.e[2]} };
}

Vec3 vec3_subtract(Vec3 v1, Vec3 v2) {
    return (Vec3){ .e = {v1.e[0]-v2.e[0], v1.e[1]-v2.e[1], v1.e[2]-v2.e[2]} };
}

Vec3 vec3_multiply(Vec3 v1, Vec3 v2) {
    return (Vec3){ .e = {v1.e[0]*v2.e[0], v1.e[1]*v2.e[1], v1.e[2]*v2.e[2]} };
}

Vec3 vec3_scale(Vec3 v, double t) {
    return (Vec3){ .e = {t*v.e[0], t*v.e[1], t*v.e[2]} };
}

Vec3 vec3_divide(Vec3 v, double t) {
    return vec3_scale(v, 1/t);
}

double vec3_dot(Vec3 v1, Vec3 v2) {
    return (v1.e[0]*v2.e[0] + v1.e[1]*v2.e[1] + v1.e[2]*v2.e[2]);
}

Vec3 vec3_cross(Vec3 v1, Vec3 v2) {
    return (Vec3){ .e = {
        v1.e[1]*v2.e[2] - v1.e[2]*v2.e[1],
        v1.e[2]*v2.e[0] - v1.e[0]*v2.e[2],
        v1.e[0]*v2.e[1] - v1.e[1]*v2.e[0]
    } };
}

Vec3 vec3_normalize(Vec3 v) {
    return vec3_divide(v, vec3_length(v));
}

void vec3_print(FILE *stream, Vec3 v) {
    fprintf(stream, "(%lf, %lf, %lf)", v.e[0], v.e[1], v.e[2]);
}