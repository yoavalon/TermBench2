#include <vector>
#include <iostream>

std::vector<std::vector<double>> transform_coordinates(const std::vector<std::vector<double>>& coords, const std::vector<std::vector<double>>& matrix) {
    std::vector<std::vector<double>> result;
    for (const auto& coord : coords) {
        std::vector<double> new_coord(3, 0);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                new_coord[i] += coord[j] * matrix[i][j];
            }
        }
        result.push_back(new_coord);
    }
    return result;
}

std::vector<std::vector<double>> apply_boundary_conditions(const std::vector<std::vector<double>>& coords, const std::vector<std::vector<double>>& boundary) {
    std::vector<std::vector<double>> transformed = transform_coordinates(coords, boundary);
    return transformed;
}

int main() {
    std::vector<std::vector<double>> coords = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<double>> boundary = {{0, 1, 0}, {0, 0, 1}, {1, 0, 0}};
    while (true) {
        coords = apply_boundary_conditions(coords, boundary);
    }
    return 0;
}