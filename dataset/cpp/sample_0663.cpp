#include <iostream>
#include <vector>
#include <Eigen/Dense>

using namespace Eigen;

MatrixXf matrix_forward_pass(const MatrixXf& matrix, const MatrixXf& weights, const VectorXf& bias, int depth) {
    if (depth == 0) {
        return matrix;
    }
    return matrix_forward_pass(matrix * weights + bias.replicate(1, matrix.cols()), weights, bias, depth - 1);
}

int main() {
    srand(time(0));
    MatrixXf A = MatrixXf::Random(10, 5);
    MatrixXf W = MatrixXf::Random(5, 5);
    VectorXf B = VectorXf::Random(5);
    int depth = 3;
    MatrixXf result = matrix_forward_pass(A, W, B, depth);
    std::cout << result << std::endl;
    return 0;
}