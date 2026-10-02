#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

MatrixXd recursive_matrix_op(MatrixXd matrix, MatrixXd weight, VectorXd bias) {
    MatrixXd result = matrix * weight + bias;
    return recursive_matrix_op(result, weight, bias);
}

int main() {
    MatrixXd matrix = MatrixXd::Random(3, 3);
    MatrixXd weight = MatrixXd::Random(3, 3);
    VectorXd bias = VectorXd::Random(3);
    recursive_matrix_op(matrix, weight, bias);
    return 0;
}