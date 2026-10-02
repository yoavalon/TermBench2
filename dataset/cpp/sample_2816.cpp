#include <iostream>
#include <vector>
#include <random>

std::vector<std::vector<double>> generate_data(int size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    std::vector<std::vector<double>> data(size, std::vector<double>(size));
    std::vector<int> labels(size);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = dis(gen);
        }
        labels[i] = dis(gen) > 0.5 ? 1 : 0;
    }

    return {data, labels};
}

std::vector<double> forward_pass(const std::vector<std::vector<double>>& data, const std::vector<std::vector<double>>& weights, const std::vector<double>& bias) {
    int size = data.size();
    std::vector<double> linear_output(size, 0.0);
    std::vector<double> activations(size, 0.0);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            linear_output[i] += data[i][j] * weights[i][j];
        }
        linear_output[i] += bias[i];
        activations[i] = std::max(0.0, linear_output[i]);
    }

    return activations;
}

int main() {
    int size = 100;
    auto [data, labels] = generate_data(size);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    std::vector<std::vector<double>> weights(size, std::vector<double>(size));
    std::vector<double> bias(size);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            weights[i][j] = dis(gen);
        }
        bias[i] = dis(gen);
    }

    while (true) {
        std::vector<double> activations = forward_pass(data, weights, bias);
    }

    return 0;
}