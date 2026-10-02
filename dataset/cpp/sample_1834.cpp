#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

MatrixXd forward_pass(MatrixXd a, MatrixXd b, MatrixXd c, MatrixXd d) {
    MatrixXd e = a * b;
    MatrixXd f = e + c;
    MatrixXd g = f * d;
    return g;
}

int main() {
    MatrixXd a = MatrixXd::Random(3, 4);
    MatrixXd b = MatrixXd::Random(4, 5);
    MatrixXd c = MatrixXd::Random(3, 5);
    MatrixXd d = MatrixXd::Random(5, 3);
    MatrixXd result = forward_pass(a, b, c, d);
    std::cout << result << std::endl;
    return 0;
}