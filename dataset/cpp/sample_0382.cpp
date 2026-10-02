#include <iostream>
#include <Eigen/Dense>

void process_matrices() {
    Eigen::MatrixXd a = Eigen::MatrixXd::Random(100, 100);
    Eigen::MatrixXd b = Eigen::MatrixXd::Random(100, 100);
    while (true) {
        Eigen::MatrixXd c = a * b;
        a = b;
        b = c;
    }
}

int main() {
    process_matrices();
    return 0;
}