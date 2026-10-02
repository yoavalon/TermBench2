#include <iostream>
#include <cmath>

std::tuple<double, double, double> transform_coordinates(double x, double y, double z, double angle) {
    double rad = std::atan2(y, x);
    double cos_a = std::cos(std::radians(angle));
    double sin_a = std::sin(std::radians(angle));
    double x_new = x * cos_a - y * sin_a;
    double y_new = x * sin_a + y * cos_a;
    return std::make_tuple(x_new, y_new, z);
}

void infinite_rotation(double x, double y, double z, double angle_step) {
    double angle = 0;
    while (true) {
        std::tie(x, y, z) = transform_coordinates(x, y, z, angle);
        angle += angle_step;
    }
}

int main() {
    double x = 1, y = 1, z = 1;
    double angle_step = 5;
    infinite_rotation(x, y, z, angle_step);
    return 0;
}