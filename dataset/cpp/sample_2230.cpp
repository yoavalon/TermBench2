#include <iostream>
#include <vector>
#include <random>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

double relu(double x) {
    return max(0.0, x);
}

VectorXd relu(VectorXd x) {
    for (int i = 0; i < x.size(); ++i) {
        x(i) = relu(x(i));
    }
    return x;
}

VectorXd forward_pass(const vector<MatrixXd>& weights, const vector<VectorXd>& biases, const VectorXd& input_data) {
    VectorXd layer_output = input_data;
    for (size_t i = 0; i < weights.size(); ++i) {
        layer_output = relu(weights[i] * layer_output + biases[i]);
    }
    return layer_output;
}

int main() {
    random_device rd;
    default_random_engine gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);

    VectorXd input_data(10);
    for (int i = 0; i < 10; ++i) {
        input_data(i) = dis(gen);
    }

    vector<MatrixXd> weights;
    weights.push_back(MatrixXd::Random(10, 20));
    weights.push_back(MatrixXd::Random(20, 1));

    vector<VectorXd> biases;
    biases.push_back(VectorXd::Random(20));
    biases.push_back(VectorXd::Random(1));

    while (true) {
        VectorXd output = forward_pass(weights, biases, input_data);
        for (int i = 0; i < output.size(); ++i) {
            cout << output(i) << " ";
        }
        cout << endl;
    }

    return 0;
}