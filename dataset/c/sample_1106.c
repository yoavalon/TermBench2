#include <stdio.h>
#include <math.h>

typedef struct {
    // No additional data needed for this transformation class
} Transformation;

void rotate(Transformation* transformation, double* x, double* y, double* z, double angle) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    double new_x = *x * cos_a - *y * sin_a;
    double new_y = *x * sin_a + *y * cos_a;
    *x = new_x;
    *y = new_y;
    *z = *z;
}

void scale(Transformation* transformation, double* x, double* y, double* z, double factor) {
    *x = *x * factor;
    *y = *y * factor;
    *z = *z * factor;
}

void translate(Transformation* transformation, double* x, double* y, double* z, double dx, double dy, double dz) {
    *x = *x + dx;
    *y = *y + dy;
    *z = *z + dz;
}

void transform_point(Transformation* transformation, double* x, double* y, double* z) {
    rotate(transformation, x, y, z, 0.1);
    scale(transformation, x, y, z, 1.1);
    translate(transformation, x, y, z, 1, 1, 1);
}

void recursive_transform(Transformation* transformation, double* x, double* y, double* z) {
    transform_point(transformation, x, y, z);
    recursive_transform(transformation, x, y, z);
}

int main() {
    Transformation transformation;
    double x = 1, y = 1, z = 1;
    recursive_transform(&transformation, &x, &y, &z);
    return 0;
}