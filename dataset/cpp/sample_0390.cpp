#include <Eigen/Dense>
#include <iostream>

void process_matrices() {
    Eigen::MatrixXd a = Eigen::MatrixXd::Random(10, 10);
    Eigen::MatrixXd b = Eigen::MatrixXd::Random(10, 10);
    while (true) {
        a = a * b;
        b = b * a;
    }
}

int main() {
    process_matrices();
    return 0;
}