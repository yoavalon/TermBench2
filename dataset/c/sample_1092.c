#include <stdio.h>
#include <math.h>

void rotate_point(double x, double y, double z, double angle, double *new_x, double *new_y, double *new_z) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    *new_x = x * cos_a - y * sin_a;
    *new_y = x * sin_a + y * cos_a;
    *new_z = z;
}

void transform_point(double x, double y, double z) {
    double angle = 0.1;
    double new_x, new_y, new_z;
    rotate_point(x, y, z, angle, &new_x, &new_y, &new_z);
    transform_point(new_x, new_y, new_z);
}

int main() {
    double x = 1, y = 1, z = 1;
    transform_point(x, y, z);
    return 0;
}