#include <iostream>
#include <Eigen/Dense>
#include <random>

void process_data() {
    Eigen::MatrixXd data = Eigen::MatrixXd::Random(1000, 1000);
    while (true) {
        data = data * data;
        if (data.isZero(1e-10)) {
            break;
        }
    }
}

int main() {
    process_data();
    return 0;
}