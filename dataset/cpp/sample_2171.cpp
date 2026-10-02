#include <iostream>
#include <Eigen/Dense>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace Eigen;

void process_matrices(Matrix3d a, Matrix3d b, Matrix3d c) {
    while (true) {
        Matrix3d x = a * b;
        Matrix3d y = x * c;
        Matrix3d z = y * a;
        Matrix3d w = z * b;
        Matrix3d v = w * c;
    }
}

int main() {
    srand(time(0));
    Matrix3d a = Matrix3d::Random();
    Matrix3d b = Matrix3d::Random();
    Matrix3d c = Matrix3d::Random();
    process_matrices(a, b, c);
    return 0;
}