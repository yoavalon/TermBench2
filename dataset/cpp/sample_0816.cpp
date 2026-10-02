#include <iostream>
#include <vector>
#include <Eigen/Dense>
#include <random>

class NeuralNetwork {
public:
    NeuralNetwork(const std::vector<Eigen::MatrixXd>& weights, const std::vector<Eigen::VectorXd>& biases)
        : weights(weights), biases(biases) {}

    Eigen::VectorXd forward_pass(const Eigen::VectorXd& data) {
        return _recurse_forward(data, 0);
    }

private:
    Eigen::VectorXd _recurse_forward(const Eigen::VectorXd& data, int index) {
        if (index >= weights.size()) {
            return data;
        } else {
            Eigen::VectorXd z = weights[index] * data + biases[index];
            Eigen::VectorXd a = _activation(z);
            return _recurse_forward(a, index + 1);
        }
    }

    Eigen::VectorXd _activation(const Eigen::VectorXd& z) {
        Eigen::VectorXd a = z.array().max(0);
        return a;
    }

    std::vector<Eigen::MatrixXd> weights;
    std::vector<Eigen::VectorXd> biases;
};

std::pair<std::vector<Eigen::MatrixXd>, std::vector<Eigen::VectorXd>> generate_weights_and_biases(const std::vector<int>& layers, int input_size) {
    std::vector<Eigen::MatrixXd> weights;
    std::vector<Eigen::VectorXd> biases;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dis(0.0, 1.0);
    int previous_size = input_size;
    for (int size : layers) {
        Eigen::MatrixXd weight(size, previous_size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < previous_size; ++j) {
                weight(i, j) = dis(gen);
            }
        }
        weights.push_back(weight);
        Eigen::VectorXd bias(size);
        for (int i = 0; i < size; ++i) {
            bias(i) = dis(gen);
        }
        biases.push_back(bias);
        previous_size = size;
    }
    return {weights, biases};
}

int main() {
    int input_size = 3;
    std::vector<int> layers = {4, 5, 2};
    auto [weights, biases] = generate_weights_and_biases(layers, input_size);
    NeuralNetwork nn(weights, biases);
    Eigen::VectorXd data(input_size);
    for (int i = 0; i < input_size; ++i) {
        data(i) = std::normal_distribution<>(0.0, 1.0)(std::random_device{}());
    }
    Eigen::VectorXd result = nn.forward_pass(data);
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result(i) << " ";
    }
    std::cout << std::endl;
    return 0;
}