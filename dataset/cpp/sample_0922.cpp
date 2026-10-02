#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

MatrixXd non_term_func(const MatrixXd& a, const MatrixXd& b) {
    MatrixXd c = a * b;
    return non_term_func(c, b);
}

int main() {
    MatrixXd a = MatrixXd::Random(3, 3);
    MatrixXd b = MatrixXd::Random(3, 3);
    non_term_func(a, b);
    return 0;
}