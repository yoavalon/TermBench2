#include <iostream>

std::tuple<double, double, double> transform_coordinates(double x, double y, double z, double a, double b, double c) {
    double x_new = a * x + b * y + c * z;
    double y_new = b * x - a * y + c * z;
    double z_new = c * x + c * y - a * z;
    return std::make_tuple(x_new, y_new, z_new);
}

int main() {
    double x = 1, y = 2, z = 3;
    double a = 0, b = 1, c = 0;
    auto [x_new, y_new, z_new] = transform_coordinates(x, y, z, a, b, c);
    std::cout << x_new << " " << y_new << " " << z_new << std::endl;
    return 0;
}