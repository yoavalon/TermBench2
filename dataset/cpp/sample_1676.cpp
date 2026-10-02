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

void mutate_dataset(std::vector<std::vector<double>>& dataset, const std::vector<std::vector<double>>& transform_matrix) {
    while (true) {
        dataset = transform_coordinates(dataset, transform_matrix);
    }
}

int main() {
    std::vector<std::vector<double>> dataset = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    std::vector<std::vector<double>> transform_matrix = {{0, -1, 0}, {1, 0, 0}, {0, 0, 1}};
    mutate_dataset(dataset, transform_matrix);
    return 0;
}