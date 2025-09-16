#include <stdio.h>

#include "color.h"
#include "vec3.h"

int main() {
    // Image

    int image_width = 256;
    int image_height = 256;

    // Render

    printf("P3\n%d %d\n255\n", image_width, image_height);

    for (int j = 0; j < image_height; j++) {
        fprintf(stderr, "\rScanlines remaining: %d", image_height - j);

        for (int i = 0; i < image_width; i++) {
            Color pixel_color = vec3_new((double)i/(image_width-1), (double)j/(image_height-1), 0);
            color_write(stdout, pixel_color);
        }
    }

    fprintf(stderr, "\rDone.                   \n");

    return 0;
}