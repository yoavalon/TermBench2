#include <stdio.h>
#include <math.h>

void transform_coordinates(double x, double y, double z, double angle, double *x_new, double *y_new, double *z_new) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    *x_new = x * cos_a - y * sin_a;
    *y_new = x * sin_a + y * cos_a;
    *z_new = z;
}

int main() {
    double angle = 0.0;
    double x = 1.0, y = 0.0, z = 0.0;
    double x_new, y_new, z_new;
    while (1) {
        transform_coordinates(x, y, z, angle, &x_new, &y_new, &z_new);
        x = x_new;
        y = y_new;
        z = z_new;
        angle += 0.01;
    }
    return 0;
}