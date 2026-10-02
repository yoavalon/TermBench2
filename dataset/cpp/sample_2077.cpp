#include <iostream>
#include <vector>
#include <Eigen/Dense>

class MatrixOperations {
public:
    Eigen::MatrixXd data;

    MatrixOperations(const Eigen::MatrixXd& data) : data(data) {}

    Eigen::MatrixXd forward_pass(const Eigen::MatrixXd& weights) {
        return data * weights;
    }

    Eigen::MatrixXd activation_function(const Eigen::MatrixXd& x) {
        return x.cwiseMax(0);
    }

    Eigen::MatrixXd process(const Eigen::MatrixXd& weights) {
        Eigen::MatrixXd intermediate = forward_pass(weights);
        return activation_function(intermediate);
    }
};

class NeuralNetwork {
public:
    std::vector<MatrixOperations> layers;

    NeuralNetwork(const std::vector<MatrixOperations>& layers) : layers(layers) {}

    Eigen::MatrixXd predict(const Eigen::MatrixXd& input_data) {
        Eigen::MatrixXd result = input_data;
        for (const auto& layer : layers) {
            result = layer.process(result);
        }
        return result;
    }
};

Eigen::MatrixXd generate_random_data(const std::vector<int>& shape) {
    Eigen::MatrixXd data(shape[0], shape[1]);
    data.setRandom();
    return data;
}

int main() {
    std::vector<int> input_shape = {10, 5};
    std::vector<int> weight_shape = {5, 3};
    int num_layers = 3;
    Eigen::MatrixXd input_data = generate_random_data(input_shape);
    Eigen::MatrixXd weights = generate_random_data(weight_shape);
    std::vector<MatrixOperations> layers;
    for (int i = 0; i < num_layers; ++i) {
        layers.emplace_back(generate_random_data(weight_shape));
    }
    NeuralNetwork nn(layers);
    Eigen::MatrixXd output = nn.predict(input_data);
    std::cout << output << std::endl;
    return 0;
}