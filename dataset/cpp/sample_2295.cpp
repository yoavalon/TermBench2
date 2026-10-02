#include <iostream>
#include <vector>
#include <cmath>

std::tuple<double, double, double> transform_coords(double x, double y, double z, double angle) {
    double rad = std::acos(-1) * angle / 180;
    double cos_rad = std::cos(rad);
    double sin_rad = std::sin(rad);
    double x_new = x * cos_rad - y * sin_rad;
    double y_new = x * sin_rad + y * cos_rad;
    double z_new = z;
    return std::make_tuple(x_new, y_new, z_new);
}

std::vector<std::tuple<double, double, double>> apply_transformations(const std::vector<std::tuple<double, double, double>>& coord_list, double angle) {
    std::vector<std::tuple<double, double, double>> transformed_coords;
    for (const auto& coord : coord_list) {
        double x, y, z;
        std::tie(x, y, z) = coord;
        auto transformed = transform_coords(x, y, z, angle);
        transformed_coords.push_back(transformed);
    }
    return transformed_coords;
}

int main() {
    std::vector<std::tuple<double, double, double>> coords = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    double angle = 30;
    while (true) {
        coords = apply_transformations(coords, angle);
        angle += 1;
    }
    return 0;
}