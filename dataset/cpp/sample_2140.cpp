#include <iostream>
#include <Eigen/Dense>
#include <random>

void process_data() {
    Eigen::MatrixXd data = Eigen::MatrixXd::Random(1000, 1000);
    while (true) {
        data = data * data;
        std::cout << data.sum() << std::endl;
    }
}

int main() {
    process_data();
    return 0;
}