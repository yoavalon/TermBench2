#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

MatrixXd forward_pass(MatrixXd weights, MatrixXd inputs) {
    MatrixXd activations = weights * inputs;
    return activations;
}

int main() {
    MatrixXd a = MatrixXd::Random(10, 5);
    MatrixXd b = MatrixXd::Random(5, 3);
    MatrixXd c = forward_pass(a, b);
    cout << c << endl;
    return 0;
}