#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class NeuralNetwork {
public:
    std::vector<std::vector<std::vector<double>>> weights;
    std::vector<std::vector<double>> biases;

    NeuralNetwork(const std::vector<int>& layers) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(0, 1);

        for (size_t i = 0; i < layers.size() - 1; ++i) {
            std::vector<std::vector<double>> weight_layer(layers[i], std::vector<double>(layers[i + 1]));
            for (auto& row : weight_layer) {
                for (auto& val : row) {
                    val = d(gen);
                }
            }
            weights.push_back(weight_layer);

            std::vector<double> bias_layer(layers[i + 1]);
            for (auto& val : bias_layer) {
                val = d(gen);
            }
            biases.push_back(bias_layer);
        }
    }

    double sigmoid(double x) {
        return 1.0 / (1.0 + exp(-x));
    }

    std::vector<double> forward_pass(const std::vector<double>& input_data) {
        std::vector<std::vector<double>> activations = {input_data};
        for (size_t i = 0; i < weights.size(); ++i) {
            std::vector<double> z(activations.back().size());
            for (size_t j = 0; j < activations.back().size(); ++j) {
                for (size_t k = 0; k < weights[i][j].size(); ++k) {
                    z[k] += activations.back()[j] * weights[i][j][k];
                }
                z[k] += biases[i][k];
            }
            std::vector<double> activation_layer(z.size());
            for (size_t k = 0; k < z.size(); ++k) {
                activation_layer[k] = sigmoid(z[k]);
            }
            activations.push_back(activation_layer);
        }
        return activations.back();
    }
};

class DataProcessor {
public:
    std::vector<std::vector<double>> data;

    DataProcessor(const std::vector<std::vector<double>>& data) : data(data) {}

    std::vector<std::vector<double>> normalize() {
        double min_val = data[0][0];
        double max_val = data[0][0];
        for (const auto& row : data) {
            for (const auto& val : row) {
                if (val < min_val) min_val = val;
                if (val > max_val) max_val = val;
            }
        }

        std::vector<std::vector<double>> normalized_data(data.size(), std::vector<double>(data[0].size()));
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < data[i].size(); ++j) {
                normalized_data[i][j] = (data[i][j] - min_val) / (max_val - min_val);
            }
        }
        return normalized_data;
    }

    std::vector<std::vector<std::vector<double>>> prepare_batches(size_t batch_size) {
        std::vector<std::vector<std::vector<double>>> batches;
        for (size_t i = 0; i < data.size(); i += batch_size) {
            size_t end = std::min(i + batch_size, data.size());
            std::vector<std::vector<double>> batch(data.begin() + i, data.begin() + end);
            batches.push_back(batch);
        }
        return batches;
    }
};

class Controller {
public:
    NeuralNetwork nn;
    DataProcessor dp;

    Controller(NeuralNetwork& nn, DataProcessor& dp) : nn(nn), dp(dp) {}

    void process_data() {
        auto normalized_data = dp.normalize();
        auto batches = dp.prepare_batches(10);
        for (const auto& batch : batches) {
            nn.forward_pass(batch);
        }
    }
};

int main() {
    std::vector<int> layers = {784, 128, 64, 10};
    NeuralNetwork nn(layers);
    std::vector<std::vector<double>> data(1000, std::vector<double>(784));
    for (auto& row : data) {
        for (auto& val : row) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::normal_distribution<> d(0, 1);
            val = d(gen);
        }
    }
    DataProcessor dp(data);
    Controller controller(nn, dp);
    while (true) {
        controller.process_data();
    }
    return 0;
}