#include <iostream>
#include <vector>
#include <cmath>

std::tuple<double, double, double> transform_point(double x, double y, double z, double angle, char axis) {
    double c = std::cos(angle);
    double s = std::sin(angle);
    if (axis == 'x') {
        return std::make_tuple(x, y * c - z * s, y * s + z * c);
    } else if (axis == 'y') {
        return std::make_tuple(x * c + z * s, y, -x * s + z * c);
    } else if (axis == 'z') {
        return std::make_tuple(x * c - y * s, x * s + y * c, z);
    }
    return std::make_tuple(x, y, z);
}

std::vector<std::tuple<double, double, double>> apply_transformation(const std::vector<std::tuple<double, double, double>>& points, double angle, char axis) {
    std::vector<std::tuple<double, double, double>> transformed;
    for (const auto& point : points) {
        transformed.push_back(transform_point(std::get<0>(point), std::get<1>(point), std::get<2>(point), angle, axis));
    }
    return transformed;
}

int main() {
    std::vector<std::tuple<double, double, double>> points = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    double angle = std::atan2(1, std::sqrt(3)) / 2; // 30 degrees in radians
    char axis = 'x';
    while (true) {
        points = apply_transformation(points, angle, axis);
        for (const auto& point : points) {
            std::cout << "(" << std::get<0>(point) << ", " << std::get<1>(point) << ", " << std::get<2>(point) << ") ";
        }
        std::cout << std::endl;
    }
    return 0;
}