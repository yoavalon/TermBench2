#include <iostream>
#include <vector>
#include <random>
#include <cmath>

std::vector<std::vector<double>> init_weights(int size) {
    std::vector<std::vector<double>> weights(size, std::vector<double>(size));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            weights[i][j] = dis(gen);
        }
    }
    return weights;
}

std::vector<double> forward_pass(const std::vector<double>& input_data, const std::vector<std::vector<double>>& weights) {
    std::vector<double> output_data(input_data.size(), 0.0);
    for (int i = 0; i < input_data.size(); ++i) {
        for (int j = 0; j < input_data.size(); ++j) {
            output_data[i] += input_data[j] * weights[j][i];
        }
    }
    return output_data;
}

bool terminate_condition(const std::vector<double>& data) {
    for (double value : data) {
        if (value >= 0.1) {
            return false;
        }
    }
    return true;
}

int main() {
    int size = 5;
    auto weights = init_weights(size);
    std::vector<double> data(size, 0.0);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < size; ++i) {
        data[i] = dis(gen);
    }
    while (true) {
        data = forward_pass(data, weights);
        if (terminate_condition(data)) {
            break;
        }
    }
    return 0;
}