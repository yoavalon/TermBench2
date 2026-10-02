#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

vector<vector<double>> dot(const vector<vector<double>>& a, const vector<vector<double>>& b) {
    vector<vector<double>> result(a.size(), vector<double>(b[0].size()));
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = 0; j < b[0].size(); ++j) {
            for (size_t k = 0; k < b.size(); ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

vector<vector<double>> add(const vector<vector<double>>& a, const vector<vector<double>>& b) {
    vector<vector<double>> result(a.size(), vector<double>(a[0].size()));
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = 0; j < a[0].size(); ++j) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    return result;
}

vector<vector<double>> relu(const vector<vector<double>>& a) {
    vector<vector<double>> result(a.size(), vector<double>(a[0].size()));
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = 0; j < a[0].size(); ++j) {
            result[i][j] = max(0.0, a[i][j]);
        }
    }
    return result;
}

vector<vector<double>> neural_network_pass(const vector<vector<vector<double>>>& weights, const vector<vector<vector<double>>>& biases, const vector<vector<double>>& inputs) {
    vector<vector<vector<double>>> activations = {inputs};
    for (size_t i = 0; i < weights.size(); ++i) {
        auto z = add(dot(weights[i], activations.back()), biases[i]);
        activations.push_back(relu(z));
    }
    return activations.back();
}

vector<vector<double>> random_matrix(size_t rows, size_t cols) {
    vector<vector<double>> result(rows, vector<double>(cols));
    random_device rd;
    mt19937 gen(rd());
    normal_distribution<> dis(0.0, 1.0);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result[i][j] = dis(gen);
        }
    }
    return result;
}

int main() {
    vector<vector<vector<double>>> weights = {random_matrix(10, 784), random_matrix(10, 10), random_matrix(10, 10)};
    vector<vector<vector<double>>> biases = {random_matrix(10, 1), random_matrix(10, 1), random_matrix(10, 1)};
    vector<vector<double>> inputs = random_matrix(784, 1);
    auto output = neural_network_pass(weights, biases, inputs);
    for (const auto& row : output) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}