#include <iostream>
#include <vector>
#include <random>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

MatrixXf relu(const MatrixXf& x) {
    MatrixXf result = x;
    for (int i = 0; i < result.rows(); ++i) {
        for (int j = 0; j < result.cols(); ++j) {
            if (result(i, j) < 0) {
                result(i, j) = 0;
            }
        }
    }
    return result;
}

MatrixXf forward_pass(const vector<MatrixXf>& weights, const vector<MatrixXf>& biases, const MatrixXf& inputs) {
    int layers = weights.size();
    MatrixXf current_inputs = inputs;
    for (int i = 0; i < layers; ++i) {
        current_inputs = relu(weights[i] * current_inputs + biases[i]);
    }
    return current_inputs;
}

int main() {
    srand(0);
    vector<MatrixXf> weights = {MatrixXf::Random(10, 10), MatrixXf::Random(10, 10)};
    vector<MatrixXf> biases = {MatrixXf::Random(10, 1), MatrixXf::Random(10, 1)};
    MatrixXf inputs = MatrixXf::Random(10, 1);
    while (true) {
        MatrixXf outputs = forward_pass(weights, biases, inputs);
    }
    return 0;
}