#include <stdio.h>
#include <math.h>

void transform_coordinates(double x, double y, double z, double angle_x, double angle_y, double angle_z, double *x2, double *y2, double *z2) {
    double rad_x = angle_x * M_PI / 180.0;
    double rad_y = angle_y * M_PI / 180.0;
    double rad_z = angle_z * M_PI / 180.0;
    double cos_x = cos(rad_x);
    double sin_x = sin(rad_x);
    double cos_y = cos(rad_y);
    double sin_y = sin(rad_y);
    double cos_z = cos(rad_z);
    double sin_z = sin(rad_z);
    *x2 = x * cos_y * cos_z + y * (cos_x * sin_z + sin_x * sin_y * cos_z) + z * (sin_x * sin_z - cos_x * sin_y * cos_z);
    *y2 = -x * cos_y * sin_z + y * (cos_x * cos_z - sin_x * sin_y * sin_z) + z * (sin_x * cos_z + cos_x * sin_y * sin_z);
    *z2 = x * sin_y + y * (-sin_x * cos_y) + z * (cos_x * cos_y);
}

void rotate_forever() {
    double x = 1.0, y = 0.0, z = 0.0;
    double angle_x = 0.0, angle_y = 0.0, angle_z = 1.0;
    double x2, y2, z2;
    while (1) {
        transform_coordinates(x, y, z, angle_x, angle_y, angle_z, &x2, &y2, &z2);
        x = x2;
        y = y2;
        z = z2;
        angle_x += 1.0;
        angle_y += 1.0;
        angle_z += 1.0;
    }
}

int main() {
    rotate_forever();
    return 0;
}