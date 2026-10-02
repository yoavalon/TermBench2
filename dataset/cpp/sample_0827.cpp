#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class Activation {
public:
    double sigmoid(double x) {
        return 1.0 / (1.0 + exp(-x));
    }

    double relu(double x) {
        return std::max(0.0, x);
    }
};

class Layer {
public:
    std::vector<std::vector<double>> weights;
    std::vector<double> bias;
    Activation activation;

    Layer(const std::vector<std::vector<double>>& weights, const std::vector<double>& bias, double (Activation::*activation)(double)) {
        this->weights = weights;
        this->bias = bias;
        this->activation.activation = activation;
    }

    std::vector<double> forward(const std::vector<double>& input_data) {
        std::vector<double> z(input_data.size());
        for (size_t i = 0; i < weights.size(); ++i) {
            double sum = 0.0;
            for (size_t j = 0; j < input_data.size(); ++j) {
                sum += input_data[j] * weights[i][j];
            }
            z[i] = sum + bias[i];
        }
        std::vector<double> output(z.size());
        for (size_t i = 0; i < z.size(); ++i) {
            output[i] = (this->activation.*activation)(z[i]);
        }
        return output;
    }
};

class NeuralNetwork {
public:
    std::vector<Layer> layers;

    NeuralNetwork(const std::vector<Layer>& layers) {
        this->layers = layers;
    }

    std::vector<double> predict(const std::vector<double>& input_data) {
        std::vector<double> current_data = input_data;
        for (const auto& layer : layers) {
            current_data = layer.forward(current_data);
        }
        return current_data;
    }
};

NeuralNetwork initialize_network(const std::vector<int>& layer_sizes, const std::string& activation_type) {
    Activation activation;
    std::vector<Layer> layers;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0.0, 1.0);

    for (size_t i = 0; i < layer_sizes.size() - 1; ++i) {
        std::vector<std::vector<double>> weights(layer_sizes[i], std::vector<double>(layer_sizes[i + 1]));
        std::vector<double> bias(layer_sizes[i + 1]);
        for (size_t j = 0; j < layer_sizes[i]; ++j) {
            for (size_t k = 0; k < layer_sizes[i + 1]; ++k) {
                weights[j][k] = d(gen);
            }
        }
        for (size_t k = 0; k < layer_sizes[i + 1]; ++k) {
            bias[k] = d(gen);
        }
        if (activation_type == "sigmoid") {
            layers.emplace_back(weights, bias, &Activation::sigmoid);
        } else if (activation_type == "relu") {
            layers.emplace_back(weights, bias, &Activation::relu);
        }
    }
    return NeuralNetwork(layers);
}

void main() {
    std::vector<std::vector<double>> input_data = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    std::vector<std::vector<double>> expected_output = {{0}, {1}, {1}, {0}};
    NeuralNetwork network = initialize_network({2, 4, 1}, "sigmoid");
    for (const auto& data : input_data) {
        std::vector<double> output = network.predict(data);
        for (double value : output) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}