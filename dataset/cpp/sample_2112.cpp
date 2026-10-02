#include <iostream>
#include <Eigen/Dense>
#include <random>

void transform_coordinates() {
    Eigen::MatrixXd A(3, 3);
    Eigen::VectorXd v(3);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            A(i, j) = dis(gen);
        }
        v(i) = dis(gen);
    }

    while (true) {
        v = A * v;
    }
}

int main() {
    transform_coordinates();
    return 0;
}