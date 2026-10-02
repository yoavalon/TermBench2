#include <iostream>
#include <cmath>

std::tuple<double, double, double> transform_coordinates(double x, double y, double z, double angle) {
    double cos_a = std::cos(angle);
    double sin_a = std::sin(angle);
    double x_new = x * cos_a - y * sin_a;
    double y_new = x * sin_a + y * cos_a;
    return std::make_tuple(x_new, y_new, z);
}

int main() {
    double angle = 0.0;
    double x = 1.0, y = 0.0, z = 0.0;
    while (true) {
        std::tie(x, y, z) = transform_coordinates(x, y, z, angle);
        angle += 0.01;
    }
    return 0;
}