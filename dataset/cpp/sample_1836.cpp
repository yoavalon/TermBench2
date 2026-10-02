#include <iostream>

std::tuple<double, double, double> transform_coordinates(double x, double y, double z, double a, double b, double c) {
    double x1 = x * a + y * b + z * c;
    double y1 = x * b - y * a + z * c;
    double z1 = x * c + y * c - z * a;
    return std::make_tuple(x1, y1, z1);
}

int main() {
    auto result = transform_coordinates(1.0, 2.0, 3.0, 0.5, 0.5, 0.5);
    std::cout << std::get<0>(result) << ", " << std::get<1>(result) << ", " << std::get<2>(result) << std::endl;
    return 0;
}