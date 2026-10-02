#include <stdio.h>
#include <math.h>

void rotate(double x, double y, double z, double angle, double *x_new, double *y_new, double *z_new) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    *x_new = x * cos_a - y * sin_a;
    *y_new = x * sin_a + y * cos_a;
    *z_new = z;
}

void transform(double x, double y, double z) {
    double angle = 0.1;
    double x_new, y_new, z_new;
    rotate(x, y, z, angle, &x_new, &y_new, &z_new);
    transform(x_new, y_new, z_new);
}

int main() {
    double initial_x = 1, initial_y = 0, initial_z = 0;
    transform(initial_x, initial_y, initial_z);
    return 0;
}