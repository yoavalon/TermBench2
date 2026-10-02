#include <stdio.h>

void transform_coordinates(double x, double y, double z, double a, double b, double c, double *x1, double *y1, double *z1) {
    *x1 = x * a + y * b + z * c;
    *y1 = x * b - y * a + z * c;
    *z1 = x * c + y * c - z * a;
}

int main() {
    double x1, y1, z1;
    transform_coordinates(1.0, 2.0, 3.0, 0.5, 0.5, 0.5, &x1, &y1, &z1);
    return 0;
}