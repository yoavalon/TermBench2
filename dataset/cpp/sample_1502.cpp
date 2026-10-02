#include <iostream>
#include <Eigen/Dense>
#include <random>

using namespace Eigen;
using namespace std;

void matrix_operations() {
    while (true) {
        Matrix3d a = Matrix3d::Random();
        Matrix3d b = Matrix3d::Random();
        Matrix3d c = a * b;
        Matrix3d d = c + c.transpose();
    }
}

int main() {
    matrix_operations();
    return 0;
}