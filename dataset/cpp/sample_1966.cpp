#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

std::vector<double> forward_pass(const std::vector<std::vector<std::vector<double>>>& weights, 
                                 const std::vector<std::vector<double>>& biases, 
                                 const std::vector<double>& inputs) {
    std::vector<double> activations = inputs;
    for (size_t i = 0; i < weights.size(); ++i) {
        std::vector<double> new_activations(weights[i].size(), 0.0);
        for (size_t j = 0; j < weights[i].size(); ++j) {
            for (size_t k = 0; k < weights[i][j].size(); ++k) {
                new_activations[j] += weights[i][j][k] * activations[k];
            }
            new_activations[j] += biases[i][j][0];
            new_activations[j] = sigmoid(new_activations[j]);
        }
        activations = new_activations;
    }
    return activations;
}

void main() {
    srand(0);
    int layers = 3;
    int input_size = 5;
    int output_size = 1;
    int hidden_size = 4;
    
    std::vector<std::vector<std::vector<double>>> weights(layers);
    std::vector<std::vector<double>> biases(layers);
    
    for (int i = 0; i < layers; ++i) {
        if (i == 0) {
            weights[i] = std::vector<std::vector<double>>(hidden_size, std::vector<double>(input_size));
            biases[i] = std::vector<std::vector<double>>(hidden_size, std::vector<double>(1));
        } else {
            weights[i] = std::vector<std::vector<double>>(output_size, std::vector<double>(hidden_size));
            biases[i] = std::vector<std::vector<double>>(output_size, std::vector<double>(1));
        }
        for (int j = 0; j < weights[i].size(); ++j) {
            for (int k = 0; k < weights[i][j].size(); ++k) {
                weights[i][j][k] = static_cast<double>(rand()) / RAND_MAX;
            }
            biases[i][j][0] = static_cast<double>(rand()) / RAND_MAX;
        }
    }
    
    std::vector<double> inputs(input_size);
    for (int i = 0; i < input_size; ++i) {
        inputs[i] = static_cast<double>(rand()) / RAND_MAX;
    }
    
    std::vector<double> result = forward_pass(weights, biases, inputs);
    for (double r : result) {
        std::cout << r << std::endl;
    }
}