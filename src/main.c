#include <stdio.h>

#include "color.h"
#include "ray.h"
#include "vec3.h"

Color ray_color(Ray *r) {
    Vec3 unit_direction = vec3_normalize(r->dir);
    double a = 0.5 * (vec3_y(unit_direction) + 1.0);

    return vec3_add(
        vec3_scale(vec3_new(1, 1, 1), 1.0 - a),
        vec3_scale(vec3_new(0.5, 0.7, 1.0), a)
    );
}

int main() {
    // Image

    double aspect_ratio = 16.0 / 9.0;
    int image_width = 400;
    int image_height = (int)(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    // Camera

    double focal_length = 1.0;
    double viewport_height = 2.0;
    double viewport_width = viewport_height * (double)image_width / image_height;
    Point3 camera_center = vec3_zero();

    Vec3 viewport_u = vec3_new(viewport_width, 0, 0);
    Vec3 viewport_v = vec3_new(0, -viewport_height, 0);

    Vec3 pixel_du = vec3_divide(viewport_u, image_width);
    Vec3 pixel_dv = vec3_divide(viewport_v, image_height);

    Point3 viewport_upper_left = vec3_subtract(
        camera_center,
        vec3_add(vec3_new(0, 0, focal_length), vec3_add(vec3_divide(viewport_u, 2), vec3_divide(viewport_v, 2)))
    );

    Point3 pixel00_loc = vec3_add(viewport_upper_left, vec3_scale(vec3_add(pixel_du, pixel_dv), 0.5));

    // Render

    printf("P3\n%d %d\n255\n", image_width, image_height);

    for (int j = 0; j < image_height; j++) {
        fprintf(stderr, "\rScanlines remaining: %d", image_height - j);

        for (int i = 0; i < image_width; i++) {
            Point3 pixel_center = vec3_add(pixel00_loc, vec3_add(vec3_scale(pixel_du, i), vec3_scale(pixel_dv, j)));
            Vec3 ray_direction = vec3_subtract(pixel_center, camera_center);
            Ray r = ray_new(camera_center, ray_direction);

            Color pixel_color = ray_color(&r);
            color_write(stderr, pixel_color);
        }
    }

    fprintf(stderr, "\rDone.                   \n");

    return 0;
}