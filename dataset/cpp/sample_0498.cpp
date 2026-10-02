#include <iostream>
#include <cmath>

double transform_point(double x, double y, double z, double angle_x, double angle_y, double angle_z) {
    double rad_x = std::radians(angle_x);
    double rad_y = std::radians(angle_y);
    double rad_z = std::radians(angle_z);
    double cos_x = std::cos(rad_x);
    double sin_x = std::sin(rad_x);
    double cos_y = std::cos(rad_y);
    double sin_y = std::sin(rad_y);
    double cos_z = std::cos(rad_z);
    double sin_z = std::sin(rad_z);
    double x1 = x;
    double y1 = y * cos_x - z * sin_x;
    double z1 = y * sin_x + z * cos_x;
    double x2 = x1 * cos_y + z1 * sin_y;
    double y2 = y1;
    double z2 = -x1 * sin_y + z1 * cos_y;
    double x3 = x2 * cos_z - y2 * sin_z;
    double y3 = x2 * sin_z + y2 * cos_z;
    double z3 = z2;
    return x3;
}

void rotate_forever() {
    double angle_x = 0;
    double angle_y = 0;
    double angle_z = 0;
    while (true) {
        double x = 1;
        double y = 1;
        double z = 1;
        x = transform_point(x, y, z, angle_x, angle_y, angle_z);
        angle_x += 1;
        angle_y += 2;
        angle_z += 3;
    }
}

int main() {
    rotate_forever();
    return 0;
}