#include <iostream>
#include <vector>
#include <cmath>

std::tuple<double, double, double> rotate_point(double x, double y, double z, double angle) {
    double cos_a = std::cos(angle);
    double sin_a = std::sin(angle);
    double x_new = x * cos_a - y * sin_a;
    double y_new = x * sin_a + y * cos_a;
    return std::make_tuple(x_new, y_new, z);
}

std::vector<std::tuple<double, double, double>> transform_coordinates(const std::vector<std::tuple<double, double, double>>& points, double angle, int depth) {
    if (depth == 0) {
        return points;
    }
    std::vector<std::tuple<double, double, double>> transformed;
    for (const auto& point : points) {
        auto [x, y, z] = point;
        transformed.push_back(rotate_point(x, y, z, angle));
    }
    return transform_coordinates(transformed, angle, depth - 1);
}

int main() {
    std::vector<std::tuple<double, double, double>> initial_points = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    double angle = 0.7853981633974483;
    int depth = 5;
    auto result = transform_coordinates(initial_points, angle, depth);
    for (const auto& point : result) {
        auto [x, y, z] = point;
        std::cout << "(" << x << ", " << y << ", " << z << ")\n";
    }
    return 0;
}