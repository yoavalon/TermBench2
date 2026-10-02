#include <iostream>
#include <cmath>

std::tuple<double, double, double> transform_coordinates(double x, double y, double z, double a, double b, double c) {
    return std::make_tuple(x + a, y + b, z + c);
}

std::tuple<double, double, double> rotate_coordinates(double x, double y, double z, double theta) {
    double cos_t = std::cos(theta);
    double sin_t = std::sin(theta);
    return std::make_tuple(x * cos_t - y * sin_t, x * sin_t + y * cos_t, z);
}

int main() {
    double x = 0, y = 0, z = 0;
    double a = 1, b = 2, c = 3;
    double theta = 0.1;
    while (true) {
        std::tie(x, y, z) = transform_coordinates(x, y, z, a, b, c);
        std::tie(x, y, z) = rotate_coordinates(x, y, z, theta);
        std::cout << x << " " << y << " " << z << std::endl;
    }
    return 0;
}