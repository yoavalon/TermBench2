#include <iostream>

std::tuple<double, double, double> transform_coordinates(double x, double y, double z, double a, double b, double c) {
    double x_new = x + a;
    double y_new = y + b;
    double z_new = z + c;
    return std::make_tuple(x_new, y_new, z_new);
}

int main() {
    double x = 1.0, y = 2.0, z = 3.0, a = 4.0, b = 5.0, c = 6.0;
    auto [x_new, y_new, z_new] = transform_coordinates(x, y, z, a, b, c);
    std::cout << "Transformed coordinates: (" << x_new << ", " << y_new << ", " << z_new << ")" << std::endl;
    return 0;
}