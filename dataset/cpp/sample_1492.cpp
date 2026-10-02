#include <iostream>
#include <vector>
#include <Eigen/Dense>

class MatrixLayer {
public:
    Eigen::MatrixXd weights;
    Eigen::VectorXd bias;

    MatrixLayer(const Eigen::MatrixXd& weights, const Eigen::VectorXd& bias)
        : weights(weights), bias(bias) {}

    Eigen::VectorXd forward(const Eigen::VectorXd& x) {
        return weights * x + bias;
    }
};

class NeuralNetwork {
public:
    std::vector<MatrixLayer> layers;

    NeuralNetwork(const std::vector<MatrixLayer>& layers) : layers(layers) {}

    Eigen::VectorXd predict(const Eigen::VectorXd& x) {
        Eigen::VectorXd input = x;
        for (const auto& layer : layers) {
            input = layer.forward(input);
        }
        return input;
    }
};

std::pair<MatrixLayer, MatrixLayer> initialize_weights(int input_size, int hidden_size, int output_size) {
    Eigen::MatrixXd weights1 = Eigen::MatrixXd::Random(input_size, hidden_size);
    Eigen::VectorXd bias1 = Eigen::VectorXd::Random(hidden_size);
    Eigen::MatrixXd weights2 = Eigen::MatrixXd::Random(hidden_size, output_size);
    Eigen::VectorXd bias2 = Eigen::VectorXd::Random(output_size);
    return {MatrixLayer(weights1, bias1), MatrixLayer(weights2, bias2)};
}

void main() {
    int input_size = 784;
    int hidden_size = 128;
    int output_size = 10;
    auto [layer1, layer2] = initialize_weights(input_size, hidden_size, output_size);
    NeuralNetwork model({layer1, layer2});
    Eigen::VectorXd input_data = Eigen::VectorXd::Random(input_size);
    Eigen::VectorXd output = model.predict(input_data);
    std::cout << output << std::endl;
}

int main() {
    main();
    return 0;
}