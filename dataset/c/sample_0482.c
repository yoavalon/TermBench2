#include <stdio.h>
#include <math.h>

void transform_coordinates(double x, double y, double z, double angle, double *x_new, double *y_new, double *z_new) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    *x_new = x * cos_a - y * sin_a;
    *y_new = x * sin_a + y * cos_a;
    *z_new = z;
}

void apply_transformation(double x, double y, double z, double angle) {
    while (1) {
        double x_new, y_new, z_new;
        transform_coordinates(x, y, z, angle, &x_new, &y_new, &z_new);
        x = x_new;
        y = y_new;
        z = z_new;
    }
}

int main() {
    double angle = M_PI / 180;
    double x = 1, y = 0, z = 0;
    apply_transformation(x, y, z, angle);
    return 0;
}