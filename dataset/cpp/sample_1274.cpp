#include <iostream>
#include <Eigen/Dense>
#include <cmath>

Eigen::MatrixXd func(const Eigen::MatrixXd& a, const Eigen::MatrixXd& b, const Eigen::MatrixXd& c) {
    Eigen::MatrixXd x = a * b;
    Eigen::MatrixXd y = x + c;
    Eigen::MatrixXd z = y.array().tanh();
    return z;
}

int main() {
    Eigen::MatrixXd a = Eigen::MatrixXd::Random(3, 4);
    Eigen::MatrixXd b = Eigen::MatrixXd::Random(4, 5);
    Eigen::MatrixXd c = Eigen::MatrixXd::Random(3, 5);
    Eigen::MatrixXd result = func(a, b, c);
    std::cout << result << std::endl;
    return 0;
}