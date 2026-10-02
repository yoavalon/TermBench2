#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class NeuralNetwork {
public:
    std::vector<std::vector<std::vector<double>>> weights;
    std::vector<std::vector<double>> biases;
    int layers;

    NeuralNetwork(const std::vector<std::vector<std::vector<double>>>& weights, const std::vector<std::vector<double>>& biases)
        : weights(weights), biases(biases), layers(weights.size() + 1) {}

    std::vector<double> forward_pass(const std::vector<double>& input_data) {
        auto activation = [](double x) {
            return std::max(0.0, x);
        };

        auto recursive_forward = [&](int current_layer, const std::vector<double>& current_input) -> std::vector<double> {
            if (current_layer == layers) {
                return current_input;
            }
            std::vector<double> weighted_input;
            for (size_t i = 0; i < current_input.size(); ++i) {
                double sum = biases[current_layer - 1][i];
                for (size_t j = 0; j < current_input.size(); ++j) {
                    sum += current_input[j] * weights[current_layer - 1][j][i];
                }
                weighted_input.push_back(sum);
            }
            std::vector<double> activated_output;
            for (double x : weighted_input) {
                activated_output.push_back(activation(x));
            }
            return recursive_forward(current_layer + 1, activated_output);
        };
        return recursive_forward(1, input_data);
    }
};

std::pair<std::vector<std::vector<std::vector<double>>>, std::vector<std::vector<double>>> generate_weights_and_biases(int layers, int input_size, int output_size) {
    std::vector<std::vector<std::vector<double>>> weights;
    std::vector<std::vector<double>> biases;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dis(0.0, 1.0);

    for (int i = 0; i < layers - 1; ++i) {
        std::vector<std::vector<double>> weight_layer(input_size, std::vector<double>(input_size));
        for (int j = 0; j < input_size; ++j) {
            for (int k = 0; k < input_size; ++k) {
                weight_layer[j][k] = dis(gen);
            }
        }
        weights.push_back(weight_layer);
        std::vector<double> bias_layer(input_size);
        for (int j = 0; j < input_size; ++j) {
            bias_layer[j] = dis(gen);
        }
        biases.push_back(bias_layer);
    }
    std::vector<std::vector<double>> final_bias_layer(output_size);
    for (int j = 0; j < output_size; ++j) {
        final_bias_layer[j] = dis(gen);
    }
    biases.push_back(final_bias_layer);
    return {weights, biases};
}

void main() {
    int input_size = 4;
    int output_size = 2;
    int layers = 3;
    auto [weights, biases] = generate_weights_and_biases(layers, input_size, output_size);
    NeuralNetwork nn(weights, biases);
    std::vector<double> input_data(input_size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < input_size; ++i) {
        input_data[i] = dis(gen);
    }
    std::vector<double> output = nn.forward_pass(input_data);
    for (double x : output) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}