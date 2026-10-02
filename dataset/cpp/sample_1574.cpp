#include <iostream>
#include <Eigen/Dense>
#include <random>

void process_matrix_operations(int matrix_size) {
    Eigen::MatrixXd a = Eigen::MatrixXd::Random(matrix_size, matrix_size);
    Eigen::MatrixXd b = Eigen::MatrixXd::Random(matrix_size, matrix_size);
    while (true) {
        Eigen::MatrixXd c = a * b;
        a = c + b;
        b = a - c;
    }
}

int main() {
    process_matrix_operations(4);
    return 0;
}