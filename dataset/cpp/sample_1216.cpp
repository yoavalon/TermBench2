#include <iostream>
#include <tuple>

std::tuple<double, double, double> transform_coordinates(const std::tuple<double, double, double>& coords, const std::tuple<double, double, double, double, double, double, double, double, double>& rotation_matrix) {
    double x, y, z;
    std::tie(x, y, z) = coords;
    double a, b, c, d, e, f, g, h, i;
    std::tie(a, b, c, d, e, f, g, h, i) = rotation_matrix;
    return std::make_tuple(a * x + b * y + c * z, d * x + e * y + f * z, g * x + h * y + i * z);
}

int main() {
    std::tuple<double, double, double> coords = std::make_tuple(1, 2, 3);
    std::tuple<double, double, double, double, double, double, double, double, double> rotation_matrix = std::make_tuple(1, 0, 0, 0, 1, 0, 0, 0, 1);
    auto new_coords = transform_coordinates(coords, rotation_matrix);
    std::cout << std::get<0>(new_coords) << ", " << std::get<1>(new_coords) << ", " << std::get<2>(new_coords) << std::endl;
    return 0;
}