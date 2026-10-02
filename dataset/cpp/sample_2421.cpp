#include <iostream>
#include <vector>

std::vector<std::vector<int>> transform_coordinates(const std::vector<std::vector<int>>& coords, const std::vector<std::vector<int>>& matrix) {
    std::vector<std::vector<int>> result;
    for (const auto& coord : coords) {
        std::vector<int> new_coord(3, 0);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                new_coord[i] += coord[j] * matrix[i][j];
            }
        }
        result.push_back(new_coord);
    }
    return result;
}

int main() {
    std::vector<std::vector<int>> coords = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<int>> matrix = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    std::vector<std::vector<int>> transformed = transform_coordinates(coords, matrix);

    for (const auto& coord : transformed) {
        std::cout << "(" << coord[0] << ", " << coord[1] << ", " << coord[2] << ")" << std::endl;
    }

    return 0;
}