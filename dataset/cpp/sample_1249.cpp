#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

MatrixXd transform_coordinates(MatrixXd points, MatrixXd matrix) {
    return points * matrix.transpose();
}

int main() {
    MatrixXd points(3, 3);
    points << 1, 2, 3,
              4, 5, 6,
              7, 8, 9;

    MatrixXd matrix(3, 3);
    matrix << 0, 1, 0,
              0, 0, 1,
              1, 0, 0;

    MatrixXd transformed = transform_coordinates(points, matrix);
    cout << transformed << endl;
    return 0;
}