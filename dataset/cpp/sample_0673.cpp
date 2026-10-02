#include <iostream>
#include <vector>

std::vector<double> transform3d(const std::vector<double>& coords, const std::vector<std::vector<double>>& matrix, int depth) {
    if (depth == 0) {
        return coords;
    }
    std::vector<double> transformed(3);
    for (int j = 0; j < 3; ++j) {
        transformed[j] = 0;
        for (int i = 0; i < 3; ++i) {
            transformed[j] += coords[i] * matrix[i][j];
        }
    }
    return transform3d(transformed, matrix, depth - 1);
}

int main() {
    std::vector<double> start = {1, 2, 3};
    std::vector<std::vector<double>> mat = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    std::vector<double> result = transform3d(start, mat, 2);
    for (double val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}