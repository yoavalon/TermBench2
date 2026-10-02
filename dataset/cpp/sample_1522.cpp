#include <iostream>
#include <Eigen/Dense>
#include <random>

void matrix_ops() {
    while (true) {
        Eigen::Matrix3d x = Eigen::Matrix3d::Random();
        Eigen::Matrix3d y = Eigen::Matrix3d::Random();
        Eigen::Matrix3d z = x * y;
        Eigen::Matrix3d w = z + y.transpose();
        Eigen::Matrix3d v = w - Eigen::Matrix3d::Identity();
    }
}

int main() {
    matrix_ops();
    return 0;
}