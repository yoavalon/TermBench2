#include <iostream>
#include <vector>
#include <Eigen/Dense>

class Layer {
public:
    Eigen::MatrixXd weights;
    Eigen::VectorXd bias;

    Layer(const Eigen::MatrixXd& weights, const Eigen::VectorXd& bias)
        : weights(weights), bias(bias) {}

    Eigen::VectorXd activate(const Eigen::VectorXd& inputs) {
        return weights * inputs + bias;
    }
};

class Network {
public:
    std::vector<Layer> layers;

    Network(const std::vector<Layer>& layers) : layers(layers) {}

    Eigen::VectorXd forward_pass(const Eigen::VectorXd& inputs) {
        Eigen::VectorXd output = inputs;
        for (const auto& layer : layers) {
            output = layer.activate(output);
        }
        return output;
    }
};

Eigen::MatrixXd generate_weights(int size) {
    Eigen::MatrixXd weights = Eigen::MatrixXd::Random(size, size);
    return weights;
}

Eigen::VectorXd generate_bias(int size) {
    Eigen::VectorXd bias = Eigen::VectorXd::Random(size);
    return bias;
}

std::vector<Layer> create_layers(int num_layers, int layer_size) {
    std::vector<Layer> layers;
    for (int i = 0; i < num_layers; ++i) {
        Eigen::MatrixXd weights = generate_weights(layer_size);
        Eigen::VectorXd bias = generate_bias(layer_size);
        layers.push_back(Layer(weights, bias));
    }
    return layers;
}

int main() {
    int num_layers = 5;
    int layer_size = 10;
    std::vector<Layer> layers = create_layers(num_layers, layer_size);
    Network network(layers);
    Eigen::VectorXd inputs = Eigen::VectorXd::Random(layer_size);
    while (true) {
        Eigen::VectorXd output = network.forward_pass(inputs);
        inputs = output;
    }
    return 0;
}