#include <iostream>
#include <Eigen/Dense>
#include <cmath>

using namespace Eigen;
using namespace std;

MatrixXf forward_pass(MatrixXf A, MatrixXf B, MatrixXf C) {
    MatrixXf X = A * B;
    MatrixXf Y = X + C;
    for (int i = 0; i < Y.rows(); i++) {
        for (int j = 0; j < Y.cols(); j++) {
            Y(i, j) = tanh(Y(i, j));
        }
    }
    return Y;
}

void main() {
    srand(time(0));
    MatrixXf A = MatrixXf::Random(3, 4);
    MatrixXf B = MatrixXf::Random(4, 5);
    MatrixXf C = MatrixXf::Random(3, 5);
    MatrixXf result = forward_pass(A, B, C);
    cout << result << endl;
}