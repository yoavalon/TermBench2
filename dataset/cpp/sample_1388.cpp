#include <iostream>
#include <vector>
#include <tuple>

std::vector<std::tuple<double, double, double>> transform_coordinates(const std::vector<std::tuple<double, double, double>>& points, const std::vector<std::vector<double>>& matrix) {
    std::vector<std::tuple<double, double, double>> transformed;
    for (const auto& point : points) {
        double x, y, z;
        std::tie(x, y, z) = point;
        double x_new = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3];
        double y_new = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3];
        double z_new = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3];
        transformed.emplace_back(x_new, y_new, z_new);
    }
    return transformed;
}

std::vector<std::tuple<double, double, double>> apply_transformation() {
    std::vector<std::tuple<double, double, double>> points = {{1, 2, 3}, {4, 5, 6}};
    std::vector<std::vector<double>> matrix = {{1, 0, 0, 1}, {0, 1, 0, 2}, {0, 0, 1, 3}};
    return transform_coordinates(points, matrix);
}

int main() {
    auto result = apply_transformation();
    for (const auto& point : result) {
        double x, y, z;
        std::tie(x, y, z) = point;
        std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
    }
    return 0;
}