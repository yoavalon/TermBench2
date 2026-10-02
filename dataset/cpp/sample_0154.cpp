#include <iostream>
#include <vector>
#include <tuple>

std::tuple<double, double, double> transform_coordinates(double x, double y, double z, const std::vector<std::vector<double>>& matrix) {
    double x_new = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z;
    double y_new = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z;
    double z_new = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z;
    return std::make_tuple(x_new, y_new, z_new);
}

std::vector<std::tuple<double, double, double>> apply_transformations(const std::vector<std::tuple<double, double, double>>& coord_list, const std::vector<std::vector<std::vector<double>>>& matrix_list) {
    std::vector<std::tuple<double, double, double>> transformed_coords;
    for (const auto& coord : coord_list) {
        double x = std::get<0>(coord);
        double y = std::get<1>(coord);
        double z = std::get<2>(coord);
        for (const auto& matrix : matrix_list) {
            std::tie(x, y, z) = transform_coordinates(x, y, z, matrix);
        }
        transformed_coords.emplace_back(x, y, z);
    }
    return transformed_coords;
}

int main() {
    std::vector<std::tuple<double, double, double>> coords = {{1, 2, 3}, {4, 5, 6}};
    std::vector<std::vector<std::vector<double>>> matrices = {
        {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}},
        {{0, 0, 1}, {1, 0, 0}, {0, 1, 0}}
    };
    auto result = apply_transformations(coords, matrices);
    for (const auto& coord : result) {
        std::cout << "(" << std::get<0>(coord) << ", " << std::get<1>(coord) << ", " << std::get<2>(coord) << ")\n";
    }
    return 0;
}