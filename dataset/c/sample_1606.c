#include <stdio.h>
#include <math.h>

void transform_coordinates(double x, double y, double z, double angle_x, double angle_y, double angle_z, double *x1, double *y1, double *z1) {
    angle_x = angle_x * M_PI / 180;
    angle_y = angle_y * M_PI / 180;
    angle_z = angle_z * M_PI / 180;
    *x1 = x * cos(angle_y) * cos(angle_z) - y * sin(angle_z) + z * sin(angle_y) * cos(angle_z);
    *y1 = x * cos(angle_y) * sin(angle_z) + y * cos(angle_z) + z * sin(angle_y) * sin(angle_z);
    *z1 = -x * sin(angle_y) + z * cos(angle_y);
}

void continuous_transformation() {
    double x = 1, y = 0, z = 0;
    double angle_x = 1, angle_y = 0, angle_z = 0;
    double x1, y1, z1;
    while (1) {
        transform_coordinates(x, y, z, angle_x, angle_y, angle_z, &x1, &y1, &z1);
        x = x1;
        y = y1;
        z = z1;
        angle_x += 1;
        angle_y += 1;
        angle_z += 1;
    }
}

int main() {
    continuous_transformation();
    return 0;
}