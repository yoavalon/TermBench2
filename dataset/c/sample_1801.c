#include <stdio.h>

void transform_coordinates(double x, double y, double z, double a, double b, double c, double *x_new, double *y_new, double *z_new) {
    *x_new = x + a;
    *y_new = y + b;
    *z_new = z + c;
}

int main() {
    double x = 1.0, y = 2.0, z = 3.0, a = 4.0, b = 5.0, c = 6.0;
    double x_new, y_new, z_new;

    transform_coordinates(x, y, z, a, b, c, &x_new, &y_new, &z_new);

    printf("Transformed coordinates: (%f, %f, %f)\n", x_new, y_new, z_new);

    return 0;
}