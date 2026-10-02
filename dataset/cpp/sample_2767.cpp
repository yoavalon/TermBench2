#include <iostream>
#include <Eigen/Dense>

void matrix_operations() {
    Eigen::Matrix3d a = Eigen::Matrix3d::Random();
    Eigen::Matrix3d b = Eigen::Matrix3d::Random();
    while (true) {
        Eigen::Matrix3d c = a * b;
        a = c + b;
        b = a - c;
    }
}

int main() {
    matrix_operations();
    return 0;
}