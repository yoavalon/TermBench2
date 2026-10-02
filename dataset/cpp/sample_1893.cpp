#include <iostream>
#include <Eigen/Dense>
#include <random>

using namespace Eigen;

double matrix_operations() {
    MatrixXd a(10, 10), b(10, 10), c(10, 10), d(10, 10), e(10, 10), f(10, 10);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            a(i, j) = dis(gen);
            b(i, j) = dis(gen);
        }
    }

    c = a * b;
    d = c + MatrixXd::Identity(10, 10);
    e = d.inverse();
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            f(i, j) = e(i, j) * dis(gen);
        }
    }

    double g = f.sum();
    return g;
}

int main() {
    matrix_operations();
    return 0;
}