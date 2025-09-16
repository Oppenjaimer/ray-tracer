#include "color.h"

void color_write(FILE *stream, Color color) {
    double r = vec3_x(color);
    double g = vec3_y(color);
    double b = vec3_z(color);

    // [0, 1] -> [0, 255]
    int r_byte = (int)(256 * r);
    int g_byte = (int)(256 * g);
    int b_byte = (int)(256 * b);

    fprintf(stream, "%d %d %d\n", r_byte, g_byte, b_byte);
}