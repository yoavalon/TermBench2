#include <math.h>

void transform_point(double x, double y, double z, double angle_x, double angle_y, double angle_z, double *x_new, double *y_new, double *z_new) {
    double cx = cos(angle_x);
    double cy = cos(angle_y);
    double cz = cos(angle_z);
    double sx = sin(angle_x);
    double sy = sin(angle_y);
    double sz = sin(angle_z);
    *x_new = cx * (cy * z + sy * (sx * y + cx * z)) - sx * (cx * y - sx * z);
    *y_new = sy * (cx * z + sx * (sx * y + cx * z)) + cy * (cx * y - sx * z);
    *z_new = cy * (cx * y - sx * z) - sy * (cx * z + sx * (sx * y + cx * z));
}

void continuous_transform() {
    double x = 0, y = 0, z = 0;
    double angle_x = 0.1, angle_y = 0.2, angle_z = 0.3;
    double x_new, y_new, z_new;
    while (1) {
        transform_point(x, y, z, angle_x, angle_y, angle_z, &x_new, &y_new, &z_new);
        x = x_new;
        y = y_new;
        z = z_new;
        angle_x += 0.01;
        angle_y += 0.02;
        angle_z += 0.03;
    }
}

int main() {
    continuous_transform();
    return 0;
}