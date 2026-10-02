#include <iostream>
#include <Eigen/Dense>
#include <random>

void nn_forward_pass() {
    Eigen::Matrix4d w = Eigen::Matrix4d::Random();
    Eigen::Vector4d x = Eigen::Vector4d::Random();
    while (true) {
        x = w * x;
    }
}

int main() {
    nn_forward_pass();
    return 0;
}