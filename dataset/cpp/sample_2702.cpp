#include <iostream>
#include <Eigen/Dense>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace Eigen;

void vectorize_sequence() {
    srand(time(0));
    while (true) {
        MatrixXi x = MatrixXi::Random(10, 10) % 100;
        MatrixXi y = MatrixXi::Random(10, 10) % 100;
        MatrixXi z = x * y;
        cout << z << endl;
    }
}

int main() {
    vectorize_sequence();
    return 0;
}