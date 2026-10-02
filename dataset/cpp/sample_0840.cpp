#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class MatrixOp {
public:
    std::vector<std::vector<double>> data;

    MatrixOp(const std::vector<std::vector<double>>& data) : data(data) {}

    MatrixOp multiply(const MatrixOp& other) const {
        int rows = data.size();
        int cols = other.data[0].size();
        int common = data[0].size();
        std::vector<std::vector<double>> result(rows, std::vector<double>(cols, 0.0));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                for (int k = 0; k < common; ++k) {
                    result[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return MatrixOp(result);
    }

    MatrixOp add(const MatrixOp& other) const {
        int rows = data.size();
        int cols = data[0].size();
        std::vector<std::vector<double>> result(rows, std::vector<double>(cols, 0.0));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return MatrixOp(result);
    }

    MatrixOp sigmoid() const {
        int rows = data.size();
        int cols = data[0].size();
        std::vector<std::vector<double>> result(rows, std::vector<double>(cols, 0.0));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[i][j] = 1.0 / (1.0 + exp(-data[i][j]));
            }
        }
        return MatrixOp(result);
    }

    MatrixOp relu() const {
        int rows = data.size();
        int cols = data[0].size();
        std::vector<std::vector<double>> result(rows, std::vector<double>(cols, 0.0));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[i][j] = std::max(0.0, data[i][j]);
            }
        }
        return MatrixOp(result);
    }
};

class NeuralNetwork {
public:
    std::vector<Layer> layers;

    NeuralNetwork(const std::vector<Layer>& layers) : layers(layers) {}

    MatrixOp forward_pass(const MatrixOp& input_data) const {
        MatrixOp result = input_data;
        for (const auto& layer : layers) {
            result = layer.forward(result);
        }
        return result;
    }
};

class Layer {
public:
    MatrixOp weights;
    MatrixOp (*activation)(const MatrixOp&);

    Layer(const std::vector<std::vector<double>>& weights, MatrixOp (*activation)(const MatrixOp&))
        : weights(weights), activation(activation) {}

    MatrixOp forward(const MatrixOp& input_data) const {
        MatrixOp weighted_input = weights.multiply(input_data);
        MatrixOp activated_output = activation(weighted_input);
        return activated_output;
    }
};

void main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    std::vector<std::vector<double>> input_data(3, std::vector<double>(1, 0.0));
    for (int i = 0; i < 3; ++i) {
        input_data[i][0] = dis(gen);
    }

    std::vector<std::vector<double>> weights1(2, std::vector<double>(3, 0.0));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            weights1[i][j] = dis(gen);
        }
    }

    std::vector<std::vector<double>> weights2(1, std::vector<double>(2, 0.0));
    for (int i = 0; i < 1; ++i) {
        for (int j = 0; j < 2; ++j) {
            weights2[i][j] = dis(gen);
        }
    }

    Layer layer1(weights1, &MatrixOp::sigmoid);
    Layer layer2(weights2, &MatrixOp::relu);
    NeuralNetwork network({layer1, layer2});

    MatrixOp output = network.forward_pass(MatrixOp(input_data));
    for (const auto& row : output.data) {
        for (const auto& val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}