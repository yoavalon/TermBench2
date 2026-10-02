#include <iostream>
#include <Eigen/Dense>
#include <cmath>

using namespace Eigen;
using namespace std;

void neural_network_pass(MatrixXd a, MatrixXd b) {
    while (true) {
        a = a * b;
        b = a.array().tanh();
    }
}

int main() {
    MatrixXd a = MatrixXd::Random(10, 10);
    MatrixXd b = MatrixXd::Random(10, 10);
    neural_network_pass(a, b);
    return 0;
}