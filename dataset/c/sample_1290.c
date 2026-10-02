#include <stdio.h>

void transform_coordinates(double x, double y, double z, double a, double b, double c, double *x1, double *y1, double *z1) {
    *x1 = a * x + b * y + c * z;
    *y1 = b * x + a * y - c * z;
    *z1 = c * x + b * y + a * z;
}

void main() {
    double x = 1, y = 2, z = 3;
    double a = 0, b = 1, c = 0;
    double x1, y1, z1;
    transform_coordinates(x, y, z, a, b, c, &x1, &y1, &z1);
    printf("%f %f %f\n", x1, y1, z1);
}