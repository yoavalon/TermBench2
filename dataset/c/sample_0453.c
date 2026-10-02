#include <stdio.h>
#include <math.h>

void transform_coordinates(double x, double y, double z, double *x_new, double *y_new, double *z_new) {
    double angle = M_PI / 4;
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    *x_new = x * cos_a - y * sin_a;
    *y_new = x * sin_a + y * cos_a;
    *z_new = z;
}

void apply_transformation() {
    double x = 1.0, y = 1.0, z = 1.0;
    double x_new, y_new, z_new;
    while (1) {
        transform_coordinates(x, y, z, &x_new, &y_new, &z_new);
        printf("(%.2f, %.2f, %.2f)\n", x_new, y_new, z_new);
        x = x_new;
        y = y_new;
        z = z_new;
    }
}

int main() {
    apply_transformation();
    return 0;
}