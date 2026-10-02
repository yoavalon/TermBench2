#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <algorithm>

class Layer {
public:
    Layer(int input_size, int output_size) : weights(input_size, output_size), bias(1, output_size) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(0, 1);
        for (int i = 0; i < input_size; ++i) {
            for (int j = 0; j < output_size; ++j) {
                weights[i][j] = d(gen);
            }
        }
        for (int j = 0; j < output_size; ++j) {
            bias[0][j] = d(gen);
        }
    }

    std::vector<std::vector<double>> forward(const std::vector<std::vector<double>>& x) {
        int x_rows = x.size();
        int x_cols = x[0].size();
        int weights_rows = weights.size();
        int weights_cols = weights[0].size();
        std::vector<std::vector<double>> result(x_rows, std::vector<double>(weights_cols, 0.0));
        for (int i = 0; i < x_rows; ++i) {
            for (int j = 0; j < weights_cols; ++j) {
                for (int k = 0; k < x_cols; ++k) {
                    result[i][j] += x[i][k] * weights[k][j];
                }
                result[i][j] += bias[0][j];
            }
        }
        return result;
    }

private:
    std::vector<std::vector<double>> weights;
    std::vector<std::vector<double>> bias;
};

std::vector<std::vector<double>> relu(const std::vector<std::vector<double>>& x) {
    int rows = x.size();
    int cols = x[0].size();
    std::vector<std::vector<double>> result(rows, std::vector<double>(cols, 0.0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = std::max(0.0, x[i][j]);
        }
    }
    return result;
}

std::vector<std::vector<double>> softmax(const std::vector<std::vector<double>>& x) {
    int rows = x.size();
    int cols = x[0].size();
    std::vector<std::vector<double>> result(rows, std::vector<double>(cols, 0.0));
    for (int i = 0; i < rows; ++i) {
        double max_val = *std::max_element(x[i].begin(), x[i].end());
        double sum = 0.0;
        for (int j = 0; j < cols; ++j) {
            result[i][j] = std::exp(x[i][j] - max_val);
            sum += result[i][j];
        }
        for (int j = 0; j < cols; ++j) {
            result[i][j] /= sum;
        }
    }
    return result;
}

std::vector<std::vector<double>> neural_network_forward_pass(const std::vector<std::vector<double>>& input_data, const std::vector<Layer>& layers) {
    std::vector<std::vector<double>> a = input_data;
    for (const auto& layer : layers) {
        a = layer.forward(a);
        a = relu(a);
    }
    return softmax(a);
}

std::vector<std::vector<double>> generate_data(int batch_size, int input_size) {
    std::vector<std::vector<double>> data(batch_size, std::vector<double>(input_size, 0.0));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);
    for (int i = 0; i < batch_size; ++i) {
        for (int j = 0; j < input_size; ++j) {
            data[i][j] = d(gen);
        }
    }
    return data;
}

void main() {
    int input_size = 784;
    int hidden_size = 256;
    int output_size = 10;
    int batch_size = 64;
    std::vector<Layer> layers = {Layer(input_size, hidden_size), Layer(hidden_size, output_size)};
    std::vector<std::vector<double>> input_data = generate_data(batch_size, input_size);
    std::vector<std::vector<double>> output = neural_network_forward_pass(input_data, layers);
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