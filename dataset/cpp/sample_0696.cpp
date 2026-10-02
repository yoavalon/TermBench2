#include <iostream>
#include <vector>

std::vector<std::vector<int>> matrix_op(const std::vector<std::vector<int>>& a, const std::vector<std::vector<int>>& b, int depth) {
    if (depth == 0) {
        return a;
    }
    int n = a.size();
    std::vector<std::vector<int>> result(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return matrix_op(result, a, depth - 1);
}

void print_matrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> a = {{1, 2}, {3, 4}};
    std::vector<std::vector<int>> b = {{2, 0}, {1, 2}};
    std::vector<std::vector<int>> result = matrix_op(a, b, 3);
    print_matrix(result);
    return 0;
}