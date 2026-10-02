#include <math.h>

void transform_point(double x, double y, double z, double angle_x, double angle_y, double angle_z, double *x_new, double *y_new, double *z_new) {
    double cos_x = cos(angle_x);
    double sin_x = sin(angle_x);
    double cos_y = cos(angle_y);
    double sin_y = sin(angle_y);
    double cos_z = cos(angle_z);
    double sin_z = sin(angle_z);
    *x_new = cos_y * (cos_z * x + sin_z * y) + sin_y * z;
    *y_new = cos_x * (sin_y * (cos_z * x + sin_z * y) - cos_y * z) - sin_x * (sin_z * x - cos_z * y);
    *z_new = sin_x * (sin_y * (cos_z * x + sin_z * y) - cos_y * z) + cos_x * (sin_z * x - cos_z * y);
}

void continuous_rotation() {
    double x = 0, y = 0, z = 0;
    double angle_x = 0, angle_y = 0, angle_z = 0;
    double increment = 0.01;
    while (1) {
        angle_x += increment;
        angle_y += increment;
        angle_z += increment;
        transform_point(x, y, z, angle_x, angle_y, angle_z, &x, &y, &z);
    }
}

int main() {
    continuous_rotation();
    return 0;
}