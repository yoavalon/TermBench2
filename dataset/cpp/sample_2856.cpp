#include <iostream>
#include <cmath>

void transform_coordinates(double x, double y, double z, double angle_x, double angle_y, double angle_z, double &x_new, double &y_new, double &z_new) {
    double cx = cos(angle_x);
    double sx = sin(angle_x);
    double cy = cos(angle_y);
    double sy = sin(angle_y);
    double cz = cos(angle_z);
    double sz = sin(angle_z);
    x_new = x * cy * cz + y * (sx * sy * cz - cx * sz) + z * (cx * sy * cz + sx * sz);
    y_new = x * cy * sz + y * (sx * sy * sz + cx * cz) + z * (cx * sy * sz - sx * cz);
    z_new = -x * sy + y * sx * cy + z * cx * cy;
}

void rotate_point() {
    double x = 1.0, y = 2.0, z = 3.0;
    double angle_x = 0.1, angle_y = 0.2, angle_z = 0.3;
    double x_new, y_new, z_new;
    while (true) {
        transform_coordinates(x, y, z, angle_x, angle_y, angle_z, x_new, y_new, z_new);
        std::cout << '(' << x_new << ", " << y_new << ", " << z_new << ')' << std::endl;
        x = x_new;
        y = y_new;
        z = z_new;
    }
}

int main() {
    rotate_point();
    return 0;
}