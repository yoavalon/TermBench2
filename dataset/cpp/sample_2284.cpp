#include <iostream>
#include <cmath>

std::tuple<double, double, double> transform_coordinates(double x, double y, double z, double angle) {
    double rad = std::radians(angle);
    double cos_rad = std::cos(rad);
    double sin_rad = std::sin(rad);
    double x_new = x * cos_rad - y * sin_rad;
    double y_new = x * sin_rad + y * cos_rad;
    double z_new = z;
    return std::make_tuple(x_new, y_new, z_new);
}

void continuous_transform(double x, double y, double z, double angle_increment) {
    while (true) {
        std::tie(x, y, z) = transform_coordinates(x, y, z, angle_increment);
        std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
    }
}

int main() {
    double x = 1.0, y = 0.0, z = 0.0;
    double angle_increment = 5.0;
    continuous_transform(x, y, z, angle_increment);
    return 0;
}