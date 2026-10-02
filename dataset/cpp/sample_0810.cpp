#include <iostream>
#include <vector>
#include <stdexcept>

class Matrix {
public:
    std::vector<std::vector<int>> data;
    int rows;
    int cols;

    Matrix(const std::vector<std::vector<int>>& data) : data(data) {
        rows = data.size();
        cols = rows > 0 ? data[0].size() : 0;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw std::invalid_argument("Matrix dimensions do not match for multiplication");
        }
        std::vector<std::vector<int>> result(rows, std::vector<int>(other.cols, 0));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return Matrix(result);
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (const auto& row : matrix.data) {
            for (int val : row) {
                os << val << " ";
            }
            os << std::endl;
        }
        return os;
    }
};

Matrix matrix_multiply_recursive(const Matrix& A, const Matrix& B, std::vector<std::vector<int>>& result = std::vector<std::vector<int>>(), int i = 0, int j = 0, int k = 0) {
    if (result.empty()) {
        result = std::vector<std::vector<int>>(A.rows, std::vector<int>(B.cols, 0));
    }
    if (i == A.rows) {
        return Matrix(result);
    }
    if (j == B.cols) {
        return matrix_multiply_recursive(A, B, result, i + 1, 0, 0);
    }
    if (k == A.cols) {
        return matrix_multiply_recursive(A, B, result, i, j + 1, 0);
    }
    result[i][j] += A.data[i][k] * B.data[k][j];
    return matrix_multiply_recursive(A, B, result, i, j, k + 1);
}

Matrix forward_pass(const std::vector<Matrix>& weights, const Matrix& inputs) {
    if (weights.empty()) {
        return inputs;
    }
    Matrix next_layer = weights[0] * inputs;
    return forward_pass(std::vector<Matrix>(weights.begin() + 1, weights.end()), next_layer);
}

int main() {
    Matrix A({{1, 2}, {3, 4}});
    Matrix B({{2, 0}, {1, 2}});
    std::cout << "Recursive Matrix Multiplication:" << std::endl;
    std::cout << matrix_multiply_recursive(A, B) << std::endl;

    std::vector<Matrix> weights = {Matrix({{1, 0}, {0, 1}}), Matrix({{2, 3}, {4, 5}})};
    Matrix inputs({{1}, {2}});
    std::cout << "\nNeural Network Forward Pass:" << std::endl;
    std::cout << forward_pass(weights, inputs) << std::endl;

    return 0;
}