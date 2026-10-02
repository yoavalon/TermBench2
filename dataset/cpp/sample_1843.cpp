#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

MatrixXf matrix_operations(MatrixXf a, MatrixXf b) {
    MatrixXf x = a * b;
    MatrixXf y = x + b.transpose();
    MatrixXf z = y - (a * a);
    return z;
}

int main() {
    MatrixXf a = MatrixXf::Random(3, 3);
    MatrixXf b = MatrixXf::Random(3, 3);
    MatrixXf result = matrix_operations(a, b);
    cout << result << endl;
    return 0;
}