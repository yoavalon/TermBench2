#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

MatrixXd matrix_operations(MatrixXd a, MatrixXd b, MatrixXd c) {
    MatrixXd x = a + b;
    MatrixXd y = x * c;
    MatrixXd z = y - a;
    return z;
}

int main() {
    MatrixXd a(2, 2);
    a << 1, 2,
         3, 4;
    MatrixXd b(2, 2);
    b << 5, 6,
         7, 8;
    MatrixXd c(2, 2);
    c << 9, 10,
         11, 12;
    MatrixXd result = matrix_operations(a, b, c);
    cout << result << endl;
    return 0;
}