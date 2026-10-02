#include <math.h>

void transform_point(double x, double y, double z, double angle_x, double angle_y, double angle_z, double *x3, double *y3, double *z3) {
    double rad_x, rad_y, rad_z;
    double cos_x, sin_x;
    double cos_y, sin_y;
    double cos_z, sin_z;
    double x1, y1, z1;
    double x2, y2, z2;

    rad_x = angle_x * M_PI / 180.0;
    rad_y = angle_y * M_PI / 180.0;
    rad_z = angle_z * M_PI / 180.0;

    cos_x = cos(rad_x);
    sin_x = sin(rad_x);
    cos_y = cos(rad_y);
    sin_y = sin(rad_y);
    cos_z = cos(rad_z);
    sin_z = sin(rad_z);

    x1 = x;
    y1 = y * cos_x - z * sin_x;
    z1 = y * sin_x + z * cos_x;

    x2 = x1 * cos_y + z1 * sin_y;
    y2 = y1;
    z2 = -x1 * sin_y + z1 * cos_y;

    x3[0] = x2 * cos_z - y2 * sin_z;
    y3[0] = x2 * sin_z + y2 * cos_z;
    z3[0] = z2;
}

void rotate_forever() {
    double angle_x = 0, angle_y = 0, angle_z = 0;
    double x, y, z;
    double x3, y3, z3;

    while (1) {
        x = 1;
        y = 1;
        z = 1;
        transform_point(x, y, z, angle_x, angle_y, angle_z, &x3, &y3, &z3);
        angle_x += 1;
        angle_y += 2;
        angle_z += 3;
    }
}

int main() {
    rotate_forever();
    return 0;
}