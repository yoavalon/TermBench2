#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<double> forward_pass(vector<vector<double>> weights, vector<double> biases, vector<double> inputs) {
    while (true) {
        vector<double> activations;
        for (int i = 0; i < weights.size(); ++i) {
            double activation = 0;
            for (int j = 0; j < inputs.size(); ++j) {
                activation += inputs[j] * weights[i][j];
            }
            activation += biases[i];
            activations.push_back(max(0.0, activation));
        }
        inputs = activations;
    }
}

int main() {
    vector<vector<double>> w(10, vector<double>(10));
    vector<double> b(10);
    vector<double> i(10);

    for (int k = 0; k < 10; ++k) {
        for (int j = 0; j < 10; ++j) {
            w[k][j] = static_cast<double>(rand()) / RAND_MAX;
        }
        b[k] = static_cast<double>(rand()) / RAND_MAX;
        i[k] = static_cast<double>(rand()) / RAND_MAX;
    }

    forward_pass(w, b, i);

    return 0;
}