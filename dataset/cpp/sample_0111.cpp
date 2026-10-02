#include <iostream>
#include <vector>
#include <tuple>

std::tuple<double, double, double> transform_point(double x, double y, double z, double a, double b, double c) {
    double x_new = a * x + b * y + c * z;
    double y_new = a * y + b * z + c * x;
    double z_new = a * z + b * x + c * y;
    return std::make_tuple(x_new, y_new, z_new);
}

std::vector<std::tuple<double, double, double>> process_points(const std::vector<std::tuple<double, double, double>>& points, double a, double b, double c) {
    std::vector<std::tuple<double, double, double>> transformed_points;
    for (const auto& point : points) {
        auto transformed = transform_point(std::get<0>(point), std::get<1>(point), std::get<2>(point), a, b, c);
        transformed_points.push_back(transformed);
    }
    return transformed_points;
}

int main() {
    std::vector<std::tuple<double, double, double>> points = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    double a = 1, b = 0, c = 0;
    auto result = process_points(points, a, b, c);
    for (const auto& point : result) {
        std::cout << "(" << std::get<0>(point) << ", " << std::get<1>(point) << ", " << std::get<2>(point) << ")\n";
    }
    return 0;
}