#include <iostream>
#include <vector>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

MatrixXd forward_pass(const MatrixXd& matrix, const MatrixXd& weights, const VectorXd& bias) {
    return matrix * weights + bias;
}

MatrixXd recursive_forward(const MatrixXd& matrix, const vector<MatrixXd>& weights_list, const vector<VectorXd>& bias_list, int index) {
    MatrixXd result = forward_pass(matrix, weights_list[index], bias_list[index]);
    if (index < weights_list.size() - 1) {
        return recursive_forward(result, weights_list, bias_list, index + 1);
    } else {
        return recursive_forward(result, weights_list, bias_list, 0);
    }
}

int main() {
    srand(time(0));
    MatrixXd data = MatrixXd::Random(10, 5);
    vector<MatrixXd> weights;
    vector<VectorXd> biases;
    for (int i = 0; i < 3; ++i) {
        weights.push_back(MatrixXd::Random(5, 5));
        biases.push_back(VectorXd::Random(5));
    }
    recursive_forward(data, weights, biases, 0);
    return 0;
}