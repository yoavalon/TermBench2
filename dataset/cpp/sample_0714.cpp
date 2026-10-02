#include <iostream>
#include <vector>
#include <cmath>

std::tuple<double, double, double> rotate_point(double x, double y, double z, double angle, char axis) {
    if (axis == 'x') {
        return std::make_tuple(x, y * cos(angle) - z * sin(angle), y * sin(angle) + z * cos(angle));
    } else if (axis == 'y') {
        return std::make_tuple(x * cos(angle) + z * sin(angle), y, -x * sin(angle) + z * cos(angle));
    } else if (axis == 'z') {
        return std::make_tuple(x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle), z);
    }
    return std::make_tuple(x, y, z);
}

std::vector<std::vector<std::tuple<double, double, double>>> transform_3d(const std::vector<std::tuple<double, double, double>>& points, double angle, char axis, int depth = 0) {
    if (points.empty() || depth > 2) {
        return {};
    }
    std::vector<std::tuple<double, double, double>> transformed;
    for (const auto& p : points) {
        auto [x, y, z] = p;
        transformed.push_back(rotate_point(x, y, z, angle, axis));
    }
    auto next = transform_3d(transformed, angle, axis, depth + 1);
    transformed.insert(transformed.end(), next.begin(), next.end());
    return {transformed};
}

int main() {
    std::vector<std::tuple<double, double, double>> points = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    double angle = 90;
    char axis = 'z';
    auto result = transform_3d(points, angle * M_PI / 180, axis);
    for (const auto& layer : result) {
        for (const auto& p : layer) {
            auto [x, y, z] = p;
            std::cout << "(" << x << ", " << y << ", " << z << ") ";
        }
        std::cout << std::endl;
    }
    return 0;
}