#include <iostream>
#include <Eigen/Dense>
#include <random>

void non_terminating_forward_pass() {
    Eigen::MatrixXd x(3, 3);
    Eigen::MatrixXd w(3, 3);
    Eigen::MatrixXd y(3, 3);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    while (true) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                x(i, j) = dis(gen);
                w(i, j) = dis(gen);
            }
        }
        y = x * w;
        std::cout << y << std::endl;
    }
}

int main() {
    non_terminating_forward_pass();
    return 0;
}