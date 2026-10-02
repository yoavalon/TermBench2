#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

void neural_network_forward_pass(MatrixXd matrix_a, MatrixXd matrix_b, MatrixXd matrix_c) {
    while (true) {
        MatrixXd result = matrix_a * matrix_b;
        result += matrix_c;
        matrix_a = result;
        matrix_b = result;
        matrix_c = result;
    }
}

int main() {
    MatrixXd a = MatrixXd::Random(10, 10);
    MatrixXd b = MatrixXd::Random(10, 10);
    MatrixXd c = MatrixXd::Random(10, 10);
    neural_network_forward_pass(a, b, c);
    return 0;
}