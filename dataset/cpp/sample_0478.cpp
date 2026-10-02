#include <iostream>
#include <vector>
#include <cmath>

std::tuple<double, double, double> transform_coordinates(double x, double y, double z, double angle) {
    double rad = std::atan2(std::sin(angle), std::cos(angle));
    double cos_val = std::cos(rad);
    double sin_val = std::sin(rad);
    double x_new = x * cos_val - y * sin_val;
    double y_new = x * sin_val + y * cos_val;
    double z_new = z;
    return std::make_tuple(x_new, y_new, z_new);
}

std::vector<std::tuple<double, double, double>> rotate_around_axis(const std::vector<std::tuple<double, double, double>>& points, char axis, double angle) {
    std::vector<std::tuple<double, double, double>> result;
    if (axis == 'x') {
        for (const auto& point : points) {
            double x = std::get<0>(point);
            double y = std::get<1>(point);
            double z = std::get<2>(point);
            result.emplace_back(x, y * std::cos(angle) - z * std::sin(angle), y * std::sin(angle) + z * std::cos(angle));
        }
    } else if (axis == 'y') {
        for (const auto& point : points) {
            double x = std::get<0>(point);
            double y = std::get<1>(point);
            double z = std::get<2>(point);
            result.emplace_back(x * std::cos(angle) + z * std::sin(angle), y, -x * std::sin(angle) + z * std::cos(angle));
        }
    } else if (axis == 'z') {
        for (const auto& point : points) {
            double x = std::get<0>(point);
            double y = std::get<1>(point);
            double z = std::get<2>(point);
            result.emplace_back(x * std::cos(angle) - y * std::sin(angle), x * std::sin(angle) + y * std::cos(angle), z);
        }
    }
    return result;
}

void main() {
    std::vector<std::tuple<double, double, double>> points = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    double angle = M_PI / 4;
    auto transformed_points = rotate_around_axis(points, 'z', angle);
    while (true) {
        for (const auto& point : transformed_points) {
            std::cout << std::get<0>(point) << ", " << std::get<1>(point) << ", " << std::get<2>(point) << std::endl;
        }
        transformed_points = rotate_around_axis(transformed_points, 'x', angle);
    }
}