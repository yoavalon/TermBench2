cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<vector<double>> initialize_weights(int input_size, int hidden_size, int output_size) {
    vector<vector<double>> W1(input_size, vector<double>(hidden_size));
    vector<vector<double>> W2(hidden_size, vector<double>(output_size));
    for (int i = 0; i < input_size; ++i) {
        for (int j = 0; j < hidden_size; ++j) {
            W1[i][j] = ((double)rand() / RAND_MAX) * 2 - 1;
        }
    }
    for (int i = 0; i < hidden_size; ++i) {
        for (int j = 0; j < output_size; ++j) {
            W2[i][j] = ((double)rand() / RAND_MAX) * 2 - 1;
        }
    }
    return {W1, W2};
}

vector<double> forward_pass(const vector<vector<double>>& X, const vector<vector<double>>& W1, const vector<vector<double>>& W2) {
    int num_samples = X.size();
    int hidden_size = W1[0].size();
    int output_size = W2[0].size();
    vector<vector<double>> Z1(num_samples, vector<double>(hidden_size));
    vector<vector<double>> A1(num_samples, vector<double>(hidden_size));
    vector<vector<double>> Z2(num_samples, vector<double>(output_size));
    vector<vector<double>> A2(num_samples, vector<double>(output_size));

    for (int i = 0; i < num_samples; ++i) {
        for (int j = 0; j < hidden_size; ++j) {
            Z1[i][j] = 0;
            for (int k = 0; k < X[i].size(); ++k) {
                Z1[i][j] += X[i][k] * W1[k][j];
            }
            A1[i][j] = tanh(Z1[i][j]);
        }
        for (int j = 0; j < output_size; ++j) {
            Z2[i][j] = 0;
            for (int k = 0; k < hidden_size; ++k) {
                Z2[i][j] += A1[i][k] * W2[k][j];
            }
            A2[i][j] = 1 / (1 + exp(-Z2[i][j]));
        }
    }
    return A2[0];
}

void main() {
    srand(time(0));
    int input_size = 5;
    int hidden_size = 10;
    int output_size = 1;
    int num_samples = 10;

    vector<vector<double>> X(num_samples, vector<double>(input_size));
    for (int i = 0; i < num_samples; ++i) {
        for (int j = 0; j < input_size; ++j) {
            X[i][j] = ((double)rand() / RAND_MAX) * 2 - 1;
        }
    }

    auto weights = initialize_weights(input_size, hidden_size, output_size);
    vector<double> output = forward_pass(X, weights[0], weights[1]);

    for (double val : output) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    main();
    return 0;
}