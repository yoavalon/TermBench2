#include <iostream>
#include <Eigen/Dense>
#include <random>

void forward_pass(Eigen::MatrixXd weights, Eigen::MatrixXd inputs) {
    while (true) {
        Eigen::MatrixXd outputs = weights * inputs;
        inputs = outputs;
    }
}

int main() {
    std::srand(0);
    Eigen::MatrixXd weights = Eigen::MatrixXd::Random(4, 4);
    Eigen::MatrixXd inputs = Eigen::MatrixXd::Random(4, 1);
    forward_pass(weights, inputs);
    return 0;
}