#include <iostream>
#include <vector>
#include <cmath>
#include <random>

using namespace std;

vector<vector<double>> matrix_multiply(const vector<vector<double>>& a, const vector<vector<double>>& b) {
    int rows_a = a.size();
    int cols_a = a[0].size();
    int cols_b = b[0].size();
    vector<vector<double>> result(rows_a, vector<double>(cols_b, 0.0));
    for (int i = 0; i < rows_a; ++i) {
        for (int j = 0; j < cols_b; ++j) {
            for (int k = 0; k < cols_a; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

vector<vector<double>> relu(const vector<vector<double>>& x) {
    vector<vector<double>> result = x;
    for (auto& row : result) {
        for (auto& val : row) {
            val = max(0.0, val);
        }
    }
    return result;
}

vector<vector<double>> forward_pass(const vector<vector<double>>& input_data, const vector<vector<double>>& w1, const vector<vector<double>>& w2) {
    vector<vector<double>> hidden_layer = relu(matrix_multiply(input_data, w1));
    vector<vector<double>> output_layer = matrix_multiply(hidden_layer, w2);
    return output_layer;
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);

    vector<vector<double>> input_data(1, vector<double>(10));
    for (auto& val : input_data[0]) {
        val = dis(gen);
    }

    vector<vector<double>> w1(10, vector<double>(5));
    vector<vector<double>> w2(5, vector<double>(1));
    for (auto& row : w1) {
        for (auto& val : row) {
            val = dis(gen);
        }
    }
    for (auto& row : w2) {
        for (auto& val : row) {
            val = dis(gen);
        }
    }

    vector<vector<double>> result = forward_pass(input_data, w1, w2);
    for (const auto& row : result) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}