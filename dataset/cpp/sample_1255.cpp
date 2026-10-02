#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<double>> forward_pass(vector<vector<double>>& matrix, vector<vector<double>>& weights, vector<double>& bias) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<double>> x(rows, vector<double>(cols, 0.0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            for (int k = 0; k < cols; ++k) {
                x[i][j] += matrix[i][k] * weights[k][j];
            }
            x[i][j] += bias[j];
            x[i][j] = tanh(x[i][j]);
        }
    }

    return x;
}

int main() {
    vector<vector<double>> data = {{1, 2}, {3, 4}};
    vector<vector<double>> w = {{0.1, 0.2}, {0.3, 0.4}};
    vector<double> b = {0.1, 0.2};
    vector<vector<double>> result = forward_pass(data, w, b);

    for (const auto& row : result) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}