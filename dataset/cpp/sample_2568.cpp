#include <iostream>
#include <vector>
#include <random>
#include <cmath>

std::pair<std::vector<std::vector<double>>, std::vector<std::vector<double>>> initialize_weights(int input_size, int hidden_size, int output_size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dis(0.0, 1.0);

    std::vector<std::vector<double>> w1(input_size, std::vector<double>(hidden_size));
    std::vector<std::vector<double>> w2(hidden_size, std::vector<double>(output_size));

    for (int i = 0; i < input_size; ++i) {
        for (int j = 0; j < hidden_size; ++j) {
            w1[i][j] = dis(gen);
        }
    }

    for (int i = 0; i < hidden_size; ++i) {
        for (int j = 0; j < output_size; ++j) {
            w2[i][j] = dis(gen);
        }
    }

    return {w1, w2};
}

std::vector<double> forward_pass(const std::vector<double>& x, const std::vector<std::vector<double>>& w1, const std::vector<std::vector<double>>& w2) {
    int hidden_size = w1[0].size();
    int output_size = w2[0].size();

    std::vector<double> z1(hidden_size, 0.0);
    for (int i = 0; i < x.size(); ++i) {
        for (int j = 0; j < hidden_size; ++j) {
            z1[j] += x[i] * w1[i][j];
        }
    }

    std::vector<double> a1(hidden_size, 0.0);
    for (int i = 0; i < hidden_size; ++i) {
        a1[i] = std::tanh(z1[i]);
    }

    std::vector<double> z2(output_size, 0.0);
    for (int i = 0; i < hidden_size; ++i) {
        for (int j = 0; j < output_size; ++j) {
            z2[j] += a1[i] * w2[i][j];
        }
    }

    return z2;
}

void main() {
    int input_size = 3;
    int hidden_size = 4;
    int output_size = 1;
    auto [w1, w2] = initialize_weights(input_size, hidden_size, output_size);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dis(0.0, 1.0);

    std::vector<double> x(input_size);
    for (int i = 0; i < input_size; ++i) {
        x[i] = dis(gen);
    }

    std::vector<double> output = forward_pass(x, w1, w2);
    for (double val : output) {
        std::cout << val << std::endl;
    }
}

int main() {
    main();
    return 0;
}