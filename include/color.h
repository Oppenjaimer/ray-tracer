#ifndef COLOR_H
#define COLOR_H

#include <stdio.h>

#include "vec3.h"

typedef Vec3 Color;

void color_write(FILE *stream, Color color);

#endif