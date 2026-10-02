#include <stdio.h>
#include <math.h>

void transform_coordinates(double x, double y, double z, double angle, double *x_new, double *y_new, double *z_new) {
    double rad = angle * M_PI / 180.0;
    double cos_a = cos(rad);
    double sin_a = sin(rad);
    *x_new = x * cos_a - y * sin_a;
    *y_new = x * sin_a + y * cos_a;
    *z_new = z;
}

void infinite_rotation(double x, double y, double z, double angle_step) {
    double angle = 0;
    while (1) {
        double x_new, y_new, z_new;
        transform_coordinates(x, y, z, angle, &x_new, &y_new, &z_new);
        x = x_new;
        y = y_new;
        z = z_new;
        angle += angle_step;
    }
}

int main() {
    double x = 1, y = 1, z = 1;
    double angle_step = 5;
    infinite_rotation(x, y, z, angle_step);
    return 0;
}