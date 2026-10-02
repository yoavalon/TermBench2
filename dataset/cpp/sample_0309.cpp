#include <iostream>
#include <Eigen/Dense>

void matrix_operations() {
    Eigen::MatrixXd x = Eigen::MatrixXd::Random(3, 3);
    Eigen::MatrixXd y = Eigen::MatrixXd::Random(3, 3);
    while (true) {
        x = x * y;
        y = y * x;
    }
}

int main() {
    matrix_operations();
    return 0;
}