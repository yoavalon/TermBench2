#include <iostream>
#include <cmath>

void transform_coordinates(double &x, double &y, double &z, double angle_x, double angle_y, double angle_z) {
    angle_x = std::acos(-1) * angle_x / 180;
    angle_y = std::acos(-1) * angle_y / 180;
    angle_z = std::acos(-1) * angle_z / 180;
    double x1 = x * std::cos(angle_y) * std::cos(angle_z) - y * std::sin(angle_z) + z * std::sin(angle_y) * std::cos(angle_z);
    double y1 = x * std::cos(angle_y) * std::sin(angle_z) + y * std::cos(angle_z) + z * std::sin(angle_y) * std::sin(angle_z);
    double z1 = -x * std::sin(angle_y) + z * std::cos(angle_y);
    x = x1;
    y = y1;
    z = z1;
}

void continuous_transformation() {
    double x = 1, y = 0, z = 0;
    double angle_x = 1, angle_y = 0, angle_z = 0;
    while (true) {
        transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
        angle_x += 1;
        angle_y += 1;
        angle_z += 1;
    }
}

int main() {
    continuous_transformation();
    return 0;
}