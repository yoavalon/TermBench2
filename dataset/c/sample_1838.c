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
    double x = 1.0, y = 2.0, z = 3.0;
    double angle = M_PI / 4;
    double x_new, y_new, z_new;
    transform_coordinates(x, y, z, angle, &x_new, &y_new, &z_new);
    printf("%f %f %f\n", x_new, y_new, z_new);
    return 0;
}