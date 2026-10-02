#include <stdio.h>

void transform_coordinates(double x, double y, double z, double a, double b, double c, double *x_new, double *y_new, double *z_new) {
    *x_new = a * x + b * y + c * z;
    *y_new = b * x + a * y - c * z;
    *z_new = c * x + b * y + a * z;
}

int main() {
    double x = 1, y = 2, z = 3, a = 0, b = 1, c = 0;
    double x_new, y_new, z_new;
    transform_coordinates(x, y, z, a, b, c, &x_new, &y_new, &z_new);
    return 0;
}