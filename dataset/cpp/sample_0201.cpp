#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class NeuralNetwork {
public:
    std::vector<std::vector<double>> weights_input_hidden;
    std::vector<std::vector<double>> weights_hidden_output;
    std::vector<double> bias_hidden;
    std::vector<double> bias_output;

    NeuralNetwork(int input_size, int hidden_size, int output_size) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(0, 1);

        weights_input_hidden = std::vector<std::vector<double>>(input_size, std::vector<double>(hidden_size));
        weights_hidden_output = std::vector<std::vector<double>>(hidden_size, std::vector<double>(output_size));
        bias_hidden = std::vector<double>(hidden_size);
        bias_output = std::vector<double>(output_size);

        for (int i = 0; i < input_size; ++i) {
            for (int j = 0; j < hidden_size; ++j) {
                weights_input_hidden[i][j] = d(gen);
            }
        }
        for (int i = 0; i < hidden_size; ++i) {
            for (int j = 0; j < output_size; ++j) {
                weights_hidden_output[i][j] = d(gen);
            }
        }
        for (int i = 0; i < hidden_size; ++i) {
            bias_hidden[i] = d(gen);
        }
        for (int i = 0; i < output_size; ++i) {
            bias_output[i] = d(gen);
        }
    }

    double sigmoid(double x) {
        return 1.0 / (1.0 + exp(-x));
    }

    std::vector<double> forward_pass(const std::vector<double>& inputs) {
        int hidden_size = bias_hidden.size();
        int output_size = bias_output.size();
        std::vector<double> hidden_layer_input(hidden_size, 0.0);
        std::vector<double> hidden_layer_output(hidden_size, 0.0);
        std::vector<double> output_layer_input(output_size, 0.0);
        std::vector<double> output_layer_output(output_size, 0.0);

        for (int i = 0; i < hidden_size; ++i) {
            for (int j = 0; j < inputs.size(); ++j) {
                hidden_layer_input[i] += inputs[j] * weights_input_hidden[j][i];
            }
            hidden_layer_input[i] += bias_hidden[i];
            hidden_layer_output[i] = sigmoid(hidden_layer_input[i]);
        }

        for (int i = 0; i < output_size; ++i) {
            for (int j = 0; j < hidden_size; ++j) {
                output_layer_input[i] += hidden_layer_output[j] * weights_hidden_output[j][i];
            }
            output_layer_input[i] += bias_output[i];
            output_layer_output[i] = sigmoid(output_layer_input[i]);
        }

        return output_layer_output;
    }
};

class MatrixOperations {
public:
    std::vector<std::vector<double>> data;

    MatrixOperations(const std::vector<std::vector<double>>& data) : data(data) {}

    std::vector<std::vector<double>> add_identity() {
        int n = data.size();
        std::vector<std::vector<double>> identity(n, std::vector<double>(n, 0.0));
        for (int i = 0; i < n; ++i) {
            identity[i][i] = 1.0;
        }
        std::vector<std::vector<double>> result(n, std::vector<double>(n, 0.0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                result[i][j] = data[i][j] + identity[i][j];
            }
        }
        return result;
    }

    std::vector<std::vector<double>> multiply_scalar(double scalar) {
        int n = data.size();
        std::vector<std::vector<double>> result(n, std::vector<double>(n, 0.0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                result[i][j] = data[i][j] * scalar;
            }
        }
        return result;
    }

    std::vector<std::vector<double>> transpose() {
        int rows = data.size();
        int cols = data[0].size();
        std::vector<std::vector<double>> result(cols, std::vector<double>(rows, 0.0));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[j][i] = data[i][j];
            }
        }
        return result;
    }
};

void main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    gen.seed(0);
    int input_size = 4, hidden_size = 5, output_size = 3;
    NeuralNetwork neural_net(input_size, hidden_size, output_size);
    std::vector<std::vector<double>> matrix_data(input_size, std::vector<double>(input_size, 0.0));
    for (int i = 0; i < input_size; ++i) {
        for (int j = 0; j < input_size; ++j) {
            matrix_data[i][j] = dis(gen);
        }
    }
    MatrixOperations matrix_ops(matrix_data);
    std::vector<std::vector<double>> modified_weights = matrix_ops.add_identity().transpose().multiply_scalar(0.5);
    neural_net.weights_input_hidden = modified_weights;
    std::vector<double> input_data(input_size, 0.0);
    for (int i = 0; i < input_size; ++i) {
        input_data[i] = dis(gen);
    }
    std::vector<double> output = neural_net.forward_pass(input_data);
    for (double val : output) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    main();
    return 0;
}