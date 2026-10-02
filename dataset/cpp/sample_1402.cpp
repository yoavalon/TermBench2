#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class MatrixProcessor {
public:
    std::vector<std::vector<double>> data;
    std::vector<std::vector<double>> processed_data;

    MatrixProcessor(const std::vector<std::vector<double>>& data) : data(data), processed_data(data) {}

    void normalize() {
        double mean = 0.0;
        double sum = 0.0;
        int size = data.size();
        for (const auto& row : data) {
            for (double val : row) {
                sum += val;
            }
        }
        mean = sum / (size * data[0].size());

        double std = 0.0;
        sum = 0.0;
        for (const auto& row : data) {
            for (double val : row) {
                sum += (val - mean) * (val - mean);
            }
        }
        std = std::sqrt(sum / (size * data[0].size()));

        for (auto& row : processed_data) {
            for (double& val : row) {
                val = (val - mean) / std;
            }
        }
    }

    void apply_weight(const std::vector<std::vector<double>>& weights) {
        int rows = processed_data.size();
        int cols = weights[0].size();
        int weight_rows = weights.size();
        std::vector<std::vector<double>> new_data(rows, std::vector<double>(cols, 0.0));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                for (int k = 0; k < weight_rows; ++k) {
                    new_data[i][j] += processed_data[i][k] * weights[k][j];
                }
            }
        }
        processed_data = new_data;
    }

    void activate() {
        for (auto& row : processed_data) {
            for (double& val : row) {
                val = (val > 0) ? val : 0;
            }
        }
    }
};

class NeuralNetwork {
public:
    std::vector<int> layers;
    std::vector<std::vector<std::vector<double>>> weights;

    NeuralNetwork(const std::vector<int>& layers) : layers(layers) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(0, 1);

        for (int i = 0; i < layers.size() - 1; ++i) {
            std::vector<std::vector<double>> weight_layer(layers[i], std::vector<double>(layers[i + 1], 0.0));
            for (auto& row : weight_layer) {
                for (double& val : row) {
                    val = d(gen);
                }
            }
            weights.push_back(weight_layer);
        }
    }

    std::vector<std::vector<double>> forward_pass(const std::vector<std::vector<double>>& data) {
        MatrixProcessor processor(data);
        for (int i = 0; i < weights.size(); ++i) {
            processor.normalize();
            processor.apply_weight(weights[i]);
            processor.activate();
        }
        return processor.processed_data;
    }
};

void main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> d(0.0, 1.0);

    std::vector<std::vector<double>> data(10, std::vector<double>(5, 0.0));
    for (auto& row : data) {
        for (double& val : row) {
            val = d(gen);
        }
    }

    std::vector<int> layers = {5, 10, 5};
    NeuralNetwork network(layers);
    std::vector<std::vector<double>> output = network.forward_pass(data);

    for (const auto& row : output) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    main();
    return 0;
}