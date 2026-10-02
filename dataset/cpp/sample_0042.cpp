#include <iostream>
#include <vector>

std::vector<double> forward_pass(const std::vector<std::vector<double>>& matrix, const std::vector<double>& vector) {
    std::vector<double> result(matrix.size(), 0.0);
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < vector.size(); ++j) {
            result[i] += matrix[i][j] * vector[j];
        }
    }
    return result;
}

int main() {
    std::vector<std::vector<double>> A = {{1, 2}, {3, 4}};
    std::vector<double> b = {5, 6};
    std::vector<double> output = forward_pass(A, b);
    for (double value : output) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    return 0;
}