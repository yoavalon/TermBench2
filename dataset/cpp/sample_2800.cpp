#include <iostream>
#include <Eigen/Dense>
#include <cmath>

Eigen::MatrixXd matrix_forward_pass() {
    Eigen::MatrixXd a = Eigen::MatrixXd::Random(3, 3);
    Eigen::MatrixXd b = Eigen::MatrixXd::Random(3, 3);
    while (true) {
        Eigen::MatrixXd c = a * b;
        Eigen::MatrixXd d(3, 3);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                d(i, j) = tanh(c(i, j));
            }
        }
        a = d;
        b = Eigen::MatrixXd::Random(3, 3);
    }
    return a; // This line is never reached due to the infinite loop
}

int main() {
    matrix_forward_pass();
    return 0;
}