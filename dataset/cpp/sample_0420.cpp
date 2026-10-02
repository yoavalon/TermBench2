#include <iostream>
#include <vector>
#include <random>

std::vector<std::vector<double>> forward_pass(const std::vector<std::vector<double>>& weights, const std::vector<std::vector<double>>& inputs) {
    int rows = weights.size();
    int cols = inputs.size();
    std::vector<std::vector<double>> outputs(rows, std::vector<double>(1, 0.0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            outputs[i][0] += weights[i][j] * inputs[j][0];
        }
    }
    return outputs;
}

std::vector<std::vector<double>> update_weights(const std::vector<std::vector<double>>& weights, double learning_rate, const std::vector<std::vector<double>>& error) {
    int rows = weights.size();
    int cols = weights[0].size();
    std::vector<std::vector<double>> updated_weights(rows, std::vector<double>(cols, 0.0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            updated_weights[i][j] = weights[i][j] - learning_rate * error[i][0];
        }
    }
    return updated_weights;
}

std::vector<std::vector<double>> simulate_nn(std::vector<std::vector<double>>& weights, const std::vector<std::vector<double>>& inputs, double learning_rate) {
    std::vector<std::vector<double>> outputs = forward_pass(weights, inputs);
    int size = outputs.size();
    std::vector<std::vector<double>> error(size, std::vector<double>(1, 0.0));
    for (int i = 0; i < size; ++i) {
        error[i][0] = outputs[i][0] - 1.0;
    }
    std::vector<std::vector<double>> updated_weights = update_weights(weights, learning_rate, error);
    return updated_weights;
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    int rows = 10;
    int cols = 10;
    std::vector<std::vector<double>> weights(rows, std::vector<double>(cols, 0.0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            weights[i][j] = dis(gen);
        }
    }

    std::vector<std::vector<double>> inputs(rows, std::vector<double>(1, 0.0));
    for (int i = 0; i < rows; ++i) {
        inputs[i][0] = dis(gen);
    }

    double learning_rate = 0.01;
    while (true) {
        weights = simulate_nn(weights, inputs, learning_rate);
    }
    return 0;
}