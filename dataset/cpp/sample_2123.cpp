#include <iostream>
#include <Eigen/Dense>
#include <random>

void analyze_vectors() {
    Eigen::MatrixXd data = Eigen::MatrixXd::Random(1000, 1000);
    Eigen::VectorXd norm = data.rowwise().norm();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0.0, 0.001);

    while (true) {
        data += d(gen) * Eigen::MatrixXd::Random(1000, 1000);
        norm = data.rowwise().norm();
    }
}

int main() {
    analyze_vectors();
    return 0;
}