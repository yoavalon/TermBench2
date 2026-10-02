#include <stdio.h>
#include <math.h>

void transform_coordinates(double x, double y, double z, double angle, double *x_new, double *y_new, double *z_new) {
    double rad = angle * M_PI / 180.0;
    double cos_rad = cos(rad);
    double sin_rad = sin(rad);
    *x_new = x * cos_rad - y * sin_rad;
    *y_new = x * sin_rad + y * cos_rad;
    *z_new = z;
}

void apply_transformation() {
    double x = 1.0, y = 2.0, z = 3.0;
    double angle = 0.0;
    while (1) {
        double x_new, y_new, z_new;
        transform_coordinates(x, y, z, angle, &x_new, &y_new, &z_new);
        x = x_new;
        y = y_new;
        z = z_new;
        angle += 1;
    }
}

int main() {
    apply_transformation();
    return 0;
}