#include <math.h>

void transform_point(double x, double y, double z, double a, double b, double c, double *x_new, double *y_new, double *z_new) {
    *x_new = x + a;
    *y_new = y + b;
    *z_new = z + c;
}

void rotate_point(double x, double y, double z, double angle, double *x_new, double *y_new, double *z_new) {
    double rad = angle * M_PI / 180.0;
    double cos_rad = cos(rad);
    double sin_rad = sin(rad);
    *x_new = x * cos_rad - y * sin_rad;
    *y_new = x * sin_rad + y * cos_rad;
    *z_new = z;
}

void scale_point(double x, double y, double z, double s, double *x_new, double *y_new, double *z_new) {
    *x_new = x * s;
    *y_new = y * s;
    *z_new = z * s;
}

void recursive_transform(double x, double y, double z, double a, double b, double c, double angle, double s) {
    double x_new, y_new, z_new;
    transform_point(x, y, z, a, b, c, &x_new, &y_new, &z_new);
    rotate_point(x_new, y_new, z_new, angle, &x_new, &y_new, &z_new);
    scale_point(x_new, y_new, z_new, s, &x_new, &y_new, &z_new);
    recursive_transform(x_new, y_new, z_new, a, b, c, angle, s);
}

int main() {
    double x = 0, y = 0, z = 0;
    double a = 1, b = 1, c = 1;
    double angle = 1;
    double s = 1.01;
    recursive_transform(x, y, z, a, b, c, angle, s);
    return 0;
}