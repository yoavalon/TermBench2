#include <iostream>
#include <tuple>

std::tuple<double, double, double> transform_coordinates(double x, double y, double z, double a, double b, double c) {
    double x_new = x * a;
    double y_new = y * b;
    double z_new = z * c;
    return std::make_tuple(x_new, y_new, z_new);
}

int main() {
    double x = 1, y = 2, z = 3;
    double a = 2, b = 3, c = 4;
    auto result = transform_coordinates(x, y, z, a, b, c);
    std::cout << "(" << std::get<0>(result) << ", " << std::get<1>(result) << ", " << std::get<2>(result) << ")" << std::endl;
    return 0;
}