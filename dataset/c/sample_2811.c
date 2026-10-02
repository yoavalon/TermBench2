#include <stdio.h>
#include <math.h>

void rotate_point(double x, double y, double z, double angle, double *x_new, double *y_new, double *z_new) {
    double cos_theta = cos(angle);
    double sin_theta = sin(angle);
    *x_new = x * cos_theta - y * sin_theta;
    *y_new = x * sin_theta + y * cos_theta;
    *z_new = z;
}

void translate_point(double x, double y, double z, double dx, double dy, double dz, double *x_new, double *y_new, double *z_new) {
    *x_new = x + dx;
    *y_new = y + dy;
    *z_new = z + dz;
}

int main() {
    double x = 0, y = 0, z = 0;
    double dx = 1, dy = 2, dz = 3;
    double angle = M_PI / 4;
    while (1) {
        double x_new, y_new, z_new;
        rotate_point(x, y, z, angle, &x_new, &y_new, &z_new);
        x = x_new;
        y = y_new;
        z = z_new;
        translate_point(x, y, z, dx, dy, dz, &x_new, &y_new, &z_new);
        x = x_new;
        y = y_new;
        z = z_new;
        printf("(%.2f, %.2f, %.2f)\n", x, y, z);
    }
    return 0;
}