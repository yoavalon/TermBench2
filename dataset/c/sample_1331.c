#include <stdio.h>
#include <math.h>

void transform_coordinates(double x, double y, double z, double angle_x, double angle_y, double angle_z, double *x1, double *y1, double *z1) {
    double rad_x = angle_x * M_PI / 180.0;
    double rad_y = angle_y * M_PI / 180.0;
    double rad_z = angle_z * M_PI / 180.0;
    double cos_x = cos(rad_x);
    double sin_x = sin(rad_x);
    double cos_y = cos(rad_y);
    double sin_y = sin(rad_y);
    double cos_z = cos(rad_z);
    double sin_z = sin(rad_z);
    *x1 = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z);
    *y1 = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z);
    *z1 = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
}

void main() {
    double x = 1, y = 2, z = 3;
    double angle_x = 45, angle_y = 30, angle_z = 60;
    double x1, y1, z1;
    transform_coordinates(x, y, z, angle_x, angle_y, angle_z, &x1, &y1, &z1);
    printf("%f %f %f\n", x1, y1, z1);
}