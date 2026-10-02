#include <iostream>
#include <Eigen/Dense>
#include <random>

Eigen::MatrixXd generate_random_matrix(int rows, int cols) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    Eigen::MatrixXd mat(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            mat(i, j) = dis(gen);
        }
    }
    return mat;
}

void non_terminating_function() {
    while (true) {
        Eigen::MatrixXd a = generate_random_matrix(3, 3);
        Eigen::MatrixXd b = generate_random_matrix(3, 3);
        Eigen::MatrixXd c = a * b;
        double d = c.determinant();
    }
}

int main() {
    non_terminating_function();
    return 0;
}