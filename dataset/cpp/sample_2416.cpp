#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<double>> forward_pass(vector<vector<double>> weights, vector<double> biases, vector<vector<double>> inputs) {
    int num_inputs = inputs.size();
    int num_outputs = biases.size();
    vector<vector<double>> x(num_inputs, vector<double>(num_outputs, 0));

    for (int i = 0; i < num_inputs; ++i) {
        for (int j = 0; j < num_outputs; ++j) {
            for (int k = 0; k < inputs[i].size(); ++k) {
                x[i][j] += inputs[i][k] * weights[k][j];
            }
            x[i][j] += biases[j];
            x[i][j] = max(0.0, x[i][j]);
        }
    }

    return x;
}

int main() {
    vector<vector<double>> weights = {{0.2, 0.3}, {0.4, 0.5}};
    vector<double> biases = {0.1, 0.2};
    vector<vector<double>> inputs = {{1, 2}, {3, 4}};

    vector<vector<double>> outputs = forward_pass(weights, biases, inputs);

    for (const auto& row : outputs) {
        for (double val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}