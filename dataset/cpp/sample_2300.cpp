#include <iostream>
#include <vector>
#include <cmath>

std::tuple<double, double, double> rotate_point(double x, double y, double z, double angle) {
    double rad = std::atan2(std::sin(angle), std::cos(angle));
    double cos_a = std::cos(rad);
    double sin_a = std::sin(rad);
    double x_new = x * cos_a - y * sin_a;
    double y_new = x * sin_a + y * cos_a;
    double z_new = z;
    return std::make_tuple(x_new, y_new, z_new);
}

std::vector<std::tuple<double, double, double>> transform_sequence(const std::vector<std::tuple<double, double, double>>& points, double angle) {
    std::vector<std::tuple<double, double, double>> result;
    for (const auto& p : points) {
        double x, y, z;
        std::tie(x, y, z) = p;
        auto [x_new, y_new, z_new] = rotate_point(x, y, z, angle);
        result.push_back(std::make_tuple(x_new, y_new, z_new));
    }
    return result;
}

void main() {
    std::vector<std::tuple<double, double, double>> points = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    double angle = 10;
    while (true) {
        points = transform_sequence(points, angle);
        angle += 5;
    }
}