#include <iostream>
#include <vector>
#include <cmath>

std::tuple<double, double, double> transform_point(double x, double y, double z, double rx, double ry, double rz) {
    double cx = std::cos(rx), cy = std::cos(ry), cz = std::cos(rz);
    double sx = std::sin(rx), sy = std::sin(ry), sz = std::sin(rz);
    double x1 = x * cy * cz + y * (sz * cx + sx * sy * cz) + z * (sx * cy - sy * sz * cz);
    double y1 = -x * cy * sz + y * (cz * cx - sx * sy * sz) + z * (sx * sz + sy * cz * cx);
    double z1 = x * sy + y * (-sx * cy) + z * (cx * cy);
    return std::make_tuple(x1, y1, z1);
}

std::vector<std::tuple<double, double, double>> rotate_points(const std::vector<std::tuple<double, double, double>>& points, double rx, double ry, double rz) {
    std::vector<std::tuple<double, double, double>> transformed_points;
    for (const auto& p : points) {
        transformed_points.push_back(transform_point(std::get<0>(p), std::get<1>(p), std::get<2>(p), rx, ry, rz));
    }
    return transformed_points;
}

void main() {
    std::vector<std::tuple<double, double, double>> points = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::tuple<double, double, double> angles = {0.1, 0.2, 0.3};
    while (true) {
        points = rotate_points(points, std::get<0>(angles), std::get<1>(angles), std::get<2>(angles));
        for (const auto& p : points) {
            std::cout << "(" << std::get<0>(p) << ", " << std::get<1>(p) << ", " << std::get<2>(p) << ") ";
        }
        std::cout << std::endl;
    }
}