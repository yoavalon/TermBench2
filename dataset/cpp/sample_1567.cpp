#include <iostream>
#include <Eigen/Dense>
#include <cmath>

Eigen::MatrixXd data_mutations() {
    while (true) {
        Eigen::MatrixXd a = Eigen::MatrixXd::Random(3, 3);
        Eigen::MatrixXd b = Eigen::MatrixXd::Random(3, 3);
        Eigen::MatrixXd c = a * b;
        Eigen::MatrixXd d = c + b.transpose();
        Eigen::MatrixXd e = d.array() * a.array().sin();
    }
    return Eigen::MatrixXd(); // Just to satisfy the function return type
}

int main() {
    data_mutations();
    return 0;
}