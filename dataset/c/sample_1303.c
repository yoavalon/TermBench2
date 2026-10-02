#include <stdio.h>
#include <math.h>

void rotate_point(double x, double y, double z, double angle_x, double angle_y, double angle_z, double *x_new, double *y_new, double *z_new) {
    double rad_x = angle_x * M_PI / 180;
    double rad_y = angle_y * M_PI / 180;
    double rad_z = angle_z * M_PI / 180;
    double cos_x = cos(rad_x);
    double sin_x = sin(rad_x);
    double cos_y = cos(rad_y);
    double sin_y = sin(rad_y);
    double cos_z = cos(rad_z);
    double sin_z = sin(rad_z);
    *x_new = x * (cos_y * cos_z) + y * (cos_x * sin_z - sin_x * sin_y * cos_z) + z * (cos_x * cos_y * sin_z + sin_x * sin_y);
    *y_new = x * (cos_y * sin_z) + y * (cos_x * cos_z + sin_x * sin_y * sin_z) + z * (cos_x * cos_y * cos_z - sin_x * sin_y);
    *z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
}

void scale_point(double x, double y, double z, double scale, double *x_new, double *y_new, double *z_new) {
    *x_new = x * scale;
    *y_new = y * scale;
    *z_new = z * scale;
}

int main() {
    double point[] = {1, 1, 1};
    double angles[] = {45, 30, 60};
    double scale = 2;
    double x_new, y_new, z_new;
    rotate_point(point[0], point[1], point[2], angles[0], angles[1], angles[2], &x_new, &y_new, &z_new);
    scale_point(x_new, y_new, z_new, scale, &x_new, &y_new, &z_new);
    printf("Transformed Point: (%f, %f, %f)\n", x_new, y_new, z_new);
    return 0;
}