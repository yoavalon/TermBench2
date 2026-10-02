#include <iostream>
#include <vector>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

MatrixXd initialize_weights(int input_size, int output_size) {
    return MatrixXd::Random(input_size, output_size);
}

VectorXd forward_pass(const VectorXd& inputs, const MatrixXd& weights) {
    return inputs * weights;
}

vector<VectorXd> process_data(const vector<VectorXd>& data, const MatrixXd& weights) {
    vector<VectorXd> results;
    for (const auto& item : data) {
        VectorXd result = forward_pass(item, weights);
        results.push_back(result);
    }
    return results;
}

int main() {
    srand(time(0));
    vector<VectorXd> data(100, VectorXd(10));
    for (auto& item : data) {
        item = VectorXd::Random(10);
    }
    MatrixXd weights = initialize_weights(10, 5);
    while (true) {
        vector<VectorXd> outputs = process_data(data, weights);
        weights = MatrixXd::Random(10, 5);
    }
    return 0;
}