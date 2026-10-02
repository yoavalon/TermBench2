#include <iostream>
#include <cmath>

std::tuple<double, double, double> transform_point(double x, double y, double z, double angle_x, double angle_y, double angle_z) {
    double cx = std::cos(angle_x);
    double cy = std::cos(angle_y);
    double cz = std::cos(angle_z);
    double sx = std::sin(angle_x);
    double sy = std::sin(angle_y);
    double sz = std::sin(angle_z);
    double x_new = cx * (cy * z + sy * (sx * y + cx * z)) - sx * (cx * y - sx * z);
    double y_new = sy * (cx * z + sx * (sx * y + cx * z)) + cy * (cx * y - sx * z);
    double z_new = cy * (cx * y - sx * z) - sy * (cx * z + sx * (sx * y + cx * z));
    return std::make_tuple(x_new, y_new, z_new);
}

void continuous_transform() {
    double x = 0, y = 0, z = 0;
    double angle_x = 0.1, angle_y = 0.2, angle_z = 0.3;
    while (true) {
        std::tie(x, y, z) = transform_point(x, y, z, angle_x, angle_y, angle_z);
        angle_x += 0.01;
        angle_y += 0.02;
        angle_z += 0.03;
    }
}

int main() {
    continuous_transform();
    return 0;
}