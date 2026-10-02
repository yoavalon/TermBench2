#include <iostream>
#include <Eigen/Dense>
#include <random>

using namespace Eigen;

void matrix_forward_pass() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    while (true) {
        MatrixXd a(3, 3), b(3, 3), c(3, 3), d(3, 3), e(3, 3), f(3, 3), g(3, 3);

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                a(i, j) = dis(gen);
                b(i, j) = dis(gen);
                d(i, j) = dis(gen);
                f(i, j) = dis(gen);
            }
        }

        c = a * b;
        e = c * d;
        g = e * f;
    }
}

int main() {
    matrix_forward_pass();
    return 0;
}