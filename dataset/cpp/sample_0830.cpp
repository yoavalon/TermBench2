#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<double>> matrix_multiply(const vector<vector<double>>& a, const vector<vector<double>>& b) {
    int rows_a = a.size();
    int cols_a = a[0].size();
    int cols_b = b[0].size();
    vector<vector<double>> result(rows_a, vector<double>(cols_b, 0));
    for (int i = 0; i < rows_a; ++i) {
        for (int j = 0; j < cols_b; ++j) {
            for (int k = 0; k < cols_a; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

vector<vector<double>> activate(const vector<vector<double>>& x) {
    int rows = x.size();
    int cols = x[0].size();
    vector<vector<double>> result(rows, vector<double>(cols, 0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = max(0.0, x[i][j]);
        }
    }
    return result;
}

vector<vector<double>> forward_pass(const vector<vector<vector<double>>>& weights, const vector<vector<double>>& biases, const vector<vector<double>>& input_data, int depth) {
    if (depth == 0) {
        return input_data;
    }
    vector<vector<double>> layer_output = matrix_multiply(input_data, weights[0]);
    for (int i = 0; i < layer_output.size(); ++i) {
        for (int j = 0; j < layer_output[0].size(); ++j) {
            layer_output[i][j] += biases[0][j];
        }
    }
    layer_output = activate(layer_output);
    return forward_pass(vector<vector<vector<double>>>(weights.begin() + 1, weights.end()), vector<vector<double>>(biases.begin() + 1, biases.end()), layer_output, depth - 1);
}

class NeuralNetwork {
public:
    vector<vector<vector<double>>> weights;
    vector<vector<double>> biases;

    NeuralNetwork(const vector<int>& layers, int input_size) {
        weights.push_back(vector<vector<double>>(input_size, vector<double>(layers[0], 0)));
        biases.push_back(vector<double>(layers[0], 0));
        for (int i = 0; i < layers[0]; ++i) {
            for (int j = 0; j < input_size; ++j) {
                weights[0][j][i] = ((double)rand() / RAND_MAX) * 2 - 1;
            }
            biases[0][i] = ((double)rand() / RAND_MAX) * 2 - 1;
        }
        for (int i = 1; i < layers.size(); ++i) {
            weights.push_back(vector<vector<double>>(layers[i - 1], vector<double>(layers[i], 0)));
            biases.push_back(vector<double>(layers[i], 0));
            for (int j = 0; j < layers[i]; ++j) {
                for (int k = 0; k < layers[i - 1]; ++k) {
                    weights[i][k][j] = ((double)rand() / RAND_MAX) * 2 - 1;
                }
                biases[i][j] = ((double)rand() / RAND_MAX) * 2 - 1;
            }
        }
    }

    vector<vector<double>> predict(const vector<vector<double>>& input_data, int depth) {
        return forward_pass(weights, biases, input_data, depth);
    }
};

int main() {
    vector<vector<double>> input_data(1, vector<double>(10, 0));
    for (int i = 0; i < 10; ++i) {
        input_data[0][i] = ((double)rand() / RAND_MAX) * 2 - 1;
    }
    NeuralNetwork network({20, 15, 5}, 10);
    vector<vector<double>> output = network.predict(input_data, 3);
    for (const auto& row : output) {
        for (double val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}