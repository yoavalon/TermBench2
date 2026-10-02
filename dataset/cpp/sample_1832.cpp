#include <iostream>
#include <Eigen/Dense>
#include <random>

double matrix_ops(const Eigen::MatrixXd& a, const Eigen::MatrixXd& b) {
    Eigen::MatrixXd x = a * b;
    Eigen::MatrixXd y = x + x.transpose();
    Eigen::MatrixXd z = y.inverse();
    return z.sum();
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    Eigen::MatrixXd a(3, 3);
    Eigen::MatrixXd b(3, 3);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            a(i, j) = dis(gen);
            b(i, j) = dis(gen);
        }
    }

    double result = matrix_ops(a, b);
    std::cout << result << std::endl;
    return 0;
}