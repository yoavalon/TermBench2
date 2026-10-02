#include <iostream>
#include <vector>
#include <Eigen/Dense>

using namespace Eigen;

MatrixXd optimize_supply_chain(const std::vector<std::vector<double>>& data, double epsilon) {
    MatrixXd a(data.size(), data[0].size());
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < data[0].size(); ++j) {
            a(i, j) = data[i][j];
        }
    }
    MatrixXd b = (a.transpose() * a + epsilon * MatrixXd::Identity(a.cols(), a.cols())).inverse();
    MatrixXd c = b * a.transpose();
    return c;
}

int main() {
    std::vector<std::vector<double>> data = {{1.0001, 2.0002}, {3.0003, 4.0004}};
    double epsilon = 0.0001;
    MatrixXd result = optimize_supply_chain(data, epsilon);
    std::cout << result << std::endl;
    return 0;
}