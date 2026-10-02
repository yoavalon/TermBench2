#include <iostream>
#include <cmath>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

Matrix3d transform_coordinates(const Vector3d& coords, const Matrix3d& matrix) {
    return matrix * coords;
}

Matrix3d generate_transformation_matrix(double angle_x, double angle_y, double angle_z) {
    Matrix3d Rx, Ry, Rz;
    Rx << 1, 0, 0,
          0, cos(angle_x), -sin(angle_x),
          0, sin(angle_x), cos(angle_x);
    Ry << cos(angle_y), 0, sin(angle_y),
          0, 1, 0,
          -sin(angle_y), 0, cos(angle_y);
    Rz << cos(angle_z), -sin(angle_z), 0,
          sin(angle_z), cos(angle_z), 0,
          0, 0, 1;
    return Rx * Ry * Rz;
}

void main() {
    Vector3d coords(1, 2, 3);
    Vector3d angles(M_PI / 4, M_PI / 3, M_PI / 6);
    Matrix3d matrix = generate_transformation_matrix(angles(0), angles(1), angles(2));
    Vector3d new_coords = transform_coordinates(coords, matrix);
    cout << new_coords.transpose() << endl;
}