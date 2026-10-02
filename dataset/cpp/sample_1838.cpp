#include <iostream>
#include <cmath>

std::tuple<double, double, double> transform_coordinates(double x, double y, double z, double angle) {
    double cos_a = std::cos(angle);
    double sin_a = std::sin(angle);
    double x_new = x * cos_a - y * sin_a;
    double y_new = x * sin_a + y * cos_a;
    double z_new = z;
    return std::make_tuple(x_new, y_new, z_new);
}

int main() {
    double x = 1.0, y = 2.0, z = 3.0;
    double angle = M_PI / 4;
    std::tie(x, y, z) = transform_coordinates(x, y, z, angle);
    std::cout << x << " " << y << " " << z << std::endl;
    return 0;
}