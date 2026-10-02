#include <iostream>
#include <vector>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

MatrixXd matrix_multiply(const MatrixXd& a, const MatrixXd& b) {
    return a * b;
}

MatrixXd forward_pass(const vector<MatrixXd>& weights, const MatrixXd& inputs, int layers) {
    MatrixXd output = inputs;
    for (int i = 0; i < layers; ++i) {
        output = matrix_multiply(weights[i], output);
    }
    return output;
}

int main() {
    vector<MatrixXd> weights;
    for (int i = 0; i < 5; ++i) {
        weights.push_back(MatrixXd::Random(10, 10));
    }
    MatrixXd inputs = MatrixXd::Random(10, 1);
    int layers = 5;
    MatrixXd result = forward_pass(weights, inputs, layers);
    cout << result << endl;
    return 0;
}