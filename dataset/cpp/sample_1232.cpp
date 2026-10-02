#include <iostream>
#include <Eigen/Dense>
#include <random>

Eigen::MatrixXd data_mutations(const Eigen::MatrixXd& x) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);

    Eigen::MatrixXd w(x.cols(), 10);
    for (int i = 0; i < w.rows(); ++i) {
        for (int j = 0; j < w.cols(); ++j) {
            w(i, j) = d(gen);
        }
    }

    Eigen::VectorXd b(10);
    for (int i = 0; i < b.size(); ++i) {
        b(i) = d(gen);
    }

    Eigen::MatrixXd z = x * w + b.replicate(x.rows(), 1);
    Eigen::MatrixXd a = z.cwiseMax(0);

    Eigen::MatrixXd w2(10, 1);
    for (int i = 0; i < w2.rows(); ++i) {
        for (int j = 0; j < w2.cols(); ++j) {
            w2(i, j) = d(gen);
        }
    }

    Eigen::VectorXd b2(1);
    b2(0) = d(gen);

    Eigen::MatrixXd z2 = a * w2 + b2.replicate(a.rows(), 1);
    return z2;
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);

    Eigen::MatrixXd x(5, 10);
    for (int i = 0; i < x.rows(); ++i) {
        for (int j = 0; j < x.cols(); ++j) {
            x(i, j) = d(gen);
        }
    }

    Eigen::MatrixXd result = data_mutations(x);
    std::cout << result << std::endl;
    return 0;
}