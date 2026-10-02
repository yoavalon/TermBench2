#include <iostream>
#include <vector>

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

void apply_transformation() {
    std::vector<std::vector<double>> coords = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<double>> matrix = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    while (true) {
        coords = transform_coordinates(coords, matrix);
        for (const auto& coord : coords) {
            for (double val : coord) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }
}

int main() {
    apply_transformation();
    return 0;
}