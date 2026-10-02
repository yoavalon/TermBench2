#include <iostream>
#include <tuple>

std::tuple<double, double, double> transform_coordinates(double x, double y, double z, double a, double b, double c) {
    double x_new = a * x + b * y + c * z;
    double y_new = b * x + a * y - c * z;
    double z_new = c * x + b * y + a * z;
    return std::make_tuple(x_new, y_new, z_new);
}

int main() {
    auto result = transform_coordinates(1, 2, 3, 0, 1, 0);
    return 0;
}