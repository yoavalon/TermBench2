#include <stdio.h>
#include <math.h>

void transform_point(double x, double y, double z, double angle_x, double angle_y, double angle_z, double *x_new, double *y_new, double *z_new) {
    double cos_x = cos(angle_x);
    double sin_x = sin(angle_x);
    double cos_y = cos(angle_y);
    double sin_y = sin(angle_y);
    double cos_z = cos(angle_z);
    double sin_z = sin(angle_z);
    *x_new = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z);
    *y_new = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z);
    *z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
}

void rotate_around_axis() {
    double x = 1.0, y = 2.0, z = 3.0;
    double angle_x = M_PI / 4;
    double angle_y = M_PI / 4;
    double angle_z = M_PI / 4;
    while (1) {
        double x_new, y_new, z_new;
        transform_point(x, y, z, angle_x, angle_y, angle_z, &x_new, &y_new, &z_new);
        printf("Coordinates: (%.6f, %.6f, %.6f)\n", x_new, y_new, z_new);
        x = x_new;
        y = y_new;
        z = z_new;
    }
}

int main() {
    rotate_around_axis();
    return 0;
}