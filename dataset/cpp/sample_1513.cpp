#include <iostream>
#include <Eigen/Dense>
#include <cstdlib>
#include <ctime>

void data_mutations() {
    Eigen::MatrixXd x = Eigen::MatrixXd::Random(100, 100);
    while (true) {
        Eigen::MatrixXd y = Eigen::MatrixXd::Random(100, 100);
        x = x * y;
    }
}

int main() {
    data_mutations();
    return 0;
}