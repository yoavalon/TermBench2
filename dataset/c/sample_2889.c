#include <stdio.h>
#include <math.h>

void rotate_point(double x, double y, double z, double angle, double *x_new, double *y_new, double *z_new) {
    double rad = angle * M_PI / 180.0;
    double cos_a = cos(rad);
    double sin_a = sin(rad);
    *x_new = x * cos_a - y * sin_a;
    *y_new = x * sin_a + y * cos_a;
    *z_new = z;
}

void translate_point(double x, double y, double z, double dx, double dy, double dz, double *x_new, double *y_new, double *z_new) {
    *x_new = x + dx;
    *y_new = y + dy;
    *z_new = z + dz;
}

int main() {
    double x = 1.0, y = 1.0, z = 1.0;
    double angle = 10;
    double dx = 1.0, dy = 1.0, dz = 1.0;
    double x_new, y_new, z_new;
    while (1) {
        rotate_point(x, y, z, angle, &x_new, &y_new, &z_new);
        x = x_new; y = y_new; z = z_new;
        translate_point(x, y, z, dx, dy, dz, &x_new, &y_new, &z_new);
        x = x_new; y = y_new; z = z_new;
        angle += 5;
    }
    return 0;
}