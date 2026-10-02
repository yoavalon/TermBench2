#include <stdio.h>
#include <math.h>

void transform_coordinates(double *x, double *y, double *z, double angle) {
    double rad = angle * M_PI / 180.0;
    double cos_rad = cos(rad);
    double sin_rad = sin(rad);
    double x_new = *x * cos_rad - *y * sin_rad;
    double y_new = *x * sin_rad + *y * cos_rad;
    double z_new = *z;
    *x = x_new;
    *y = y_new;
    *z = z_new;
}

void continuous_transform(double x, double y, double z, double angle_increment) {
    while (1) {
        transform_coordinates(&x, &y, &z, angle_increment);
        printf("(%.2f, %.2f, %.2f)\n", x, y, z);
    }
}

int main() {
    double x = 1.0, y = 0.0, z = 0.0;
    double angle_increment = 5.0;
    continuous_transform(x, y, z, angle_increment);
    return 0;
}