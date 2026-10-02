#include <iostream>
#include <vector>

std::vector<float> forward_pass(const std::vector<std::vector<float>>& matrix, const std::vector<float>& vector) {
    std::vector<float> result(matrix.size(), 0.0f);
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < vector.size(); ++j) {
            result[i] += matrix[i][j] * vector[j];
        }
    }
    return result;
}

int main() {
    std::vector<std::vector<float>> matrix = {{0.1f, 0.2f}, {0.3f, 0.4f}};
    std::vector<float> vector = {0.5f, 0.6f};
    std::vector<float> output = forward_pass(matrix, vector);
    for (float val : output) {
        std::cout << val << " ";
    }
    return 0;
}