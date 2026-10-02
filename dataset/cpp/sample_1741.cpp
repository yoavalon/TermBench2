#include <iostream>
#include <cmath>
#include <vector>

std::tuple<double, double, double> rotate_point(double x, double y, double z, double angle, char axis) {
    double cos_theta = std::cos(angle);
    double sin_theta = std::sin(angle);
    if (axis == 'x') {
        double y_new = cos_theta * y - sin_theta * z;
        double z_new = sin_theta * y + cos_theta * z;
        return std::make_tuple(x, y_new, z_new);
    } else if (axis == 'y') {
        double x_new = cos_theta * x + sin_theta * z;
        double z_new = -sin_theta * x + cos_theta * z;
        return std::make_tuple(x_new, y, z_new);
    } else if (axis == 'z') {
        double x_new = cos_theta * x - sin_theta * y;
        double y_new = sin_theta * x + cos_theta * y;
        return std::make_tuple(x_new, y_new, z);
    }
    return std::make_tuple(x, y, z);
}

std::tuple<double, double, double> translate_point(double x, double y, double z, double dx, double dy, double dz) {
    return std::make_tuple(x + dx, y + dy, z + dz);
}

std::vector<std::tuple<double, double, double>> apply_transformations(const std::vector<std::tuple<double, double, double>>& points, const std::vector<std::tuple<double, char>>& rotations, const std::vector<std::tuple<double, double, double>>& translations) {
    std::vector<std::tuple<double, double, double>> transformed_points;
    for (const auto& point : points) {
        double x, y, z;
        std::tie(x, y, z) = point;
        for (const auto& rotation : rotations) {
            double angle;
            char axis;
            std::tie(angle, axis) = rotation;
            std::tie(x, y, z) = rotate_point(x, y, z, angle, axis);
        }
        for (const auto& translation : translations) {
            double dx, dy, dz;
            std::tie(dx, dy, dz) = translation;
            std::tie(x, y, z) = translate_point(x, y, z, dx, dy, dz);
        }
        transformed_points.emplace_back(x, y, z);
    }
    return transformed_points;
}

void main() {
    std::vector<std::tuple<double, double, double>> points = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    std::vector<std::tuple<double, char>> rotations = {{M_PI / 4, 'x'}, {M_PI / 4, 'y'}};
    std::vector<std::tuple<double, double, double>> translations = {{1, 1, 1}};
    while (true) {
        points = apply_transformations(points, rotations, translations);
        for (const auto& point : points) {
            double x, y, z;
            std::tie(x, y, z) = point;
            std::cout << "(" << x << ", " << y << ", " << z << ") ";
        }
        std::cout << std::endl;
    }
}