#include <iostream>
#include <vector>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

class MatrixOps {
public:
    MatrixXd data;

    MatrixOps(const MatrixXd& data) : data(data) {}

    MatrixXd forward_pass(const MatrixXd& weights) {
        return data * weights;
    }
};

class Network {
public:
    vector<MatrixOps> layers;

    Network(const vector<MatrixOps>& layers) : layers(layers) {}

    MatrixXd compute(const MatrixXd& input_data) {
        MatrixXd result = input_data;
        for (const auto& layer : layers) {
            result = layer.forward_pass(result);
        }
        return result;
    }
};

class BoundaryConditions {
public:
    Network network;

    BoundaryConditions(const Network& network) : network(network) {}

    bool validate(const MatrixXd& input_data, const MatrixXd& expected_output) {
        MatrixXd output = network.compute(input_data);
        return (output.isApprox(expected_output, 1e-6));
    }
};

int main() {
    MatrixXd data(2, 2);
    data << 1, 2, 3, 4;
    MatrixXd weights1(2, 2);
    weights1 << 0.1, 0.2, 0.3, 0.4;
    MatrixXd weights2(2, 2);
    weights2 << 0.5, 0.6, 0.7, 0.8;
    MatrixOps layer1(data);
    MatrixOps layer2(weights1);
    MatrixOps layer3(weights2);
    vector<MatrixOps> layers = {layer1, layer2, layer3};
    Network network(layers);
    BoundaryConditions boundary_conditions(network);
    MatrixXd input_data(1, 2);
    input_data << 1, 1;
    MatrixXd expected_output(1, 2);
    expected_output << 0.7, 0.8;
    bool result = boundary_conditions.validate(input_data, expected_output);
    cout << result << endl;
    return 0;
}