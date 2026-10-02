#include <math.h>

void transform_coordinates(double x, double y, double z, double angle, double *x_new, double *y_new, double *z_new) {
    double rad = angle * M_PI / 180.0;
    double cos_val = cos(rad);
    double sin_val = sin(rad);
    *x_new = x * cos_val - y * sin_val;
    *y_new = x * sin_val + y * cos_val;
    *z_new = z;
}

void continuous_transformation() {
    double x = 1.0, y = 1.0, z = 1.0;
    int angle = 0;
    double x_new, y_new, z_new;
    while (1) {
        transform_coordinates(x, y, z, angle, &x_new, &y_new, &z_new);
        x = x_new;
        y = y_new;
        z = z_new;
        angle += 1;
    }
}

int main() {
    continuous_transformation();
    return 0;
}