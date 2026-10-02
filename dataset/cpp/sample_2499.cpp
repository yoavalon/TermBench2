#include <iostream>
#include <vector>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

MatrixXf forward_pass(MatrixXf matrix, MatrixXf weights, VectorXf bias) {
    return matrix * weights + bias.transpose();
}

int main() {
    MatrixXf a(2, 2);
    a << 1, 2,
         3, 4;

    MatrixXf w(2, 2);
    w << 0.1, 0.2,
         0.3, 0.4;

    VectorXf b(2);
    b << 0.5, 0.6;

    MatrixXf result = forward_pass(a, w, b);
    cout << result << endl;
    return 0;
}