#include <iostream>
#include <Eigen/Dense>
#include <random>

Eigen::MatrixXd neural_network_pass(Eigen::MatrixXd A, Eigen::MatrixXd B, Eigen::MatrixXd C) {
    while (true) {
        Eigen::MatrixXd X = A * B;
        Eigen::MatrixXd Y = X * C;
        Eigen::MatrixXd Z = Y * A;
        A = B * C;
        B = C * A;
        C = A * B;
    }
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    Eigen::MatrixXd A(100, 100);
    Eigen::MatrixXd B(100, 100);
    Eigen::MatrixXd C(100, 100);

    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            A(i, j) = dis(gen);
            B(i, j) = dis(gen);
            C(i, j) = dis(gen);
        }
    }

    neural_network_pass(A, B, C);

    return 0;
}