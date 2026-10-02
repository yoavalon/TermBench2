#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<vector<double>> forward_pass(vector<vector<double>>& matrix, vector<vector<double>>& weights) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<double>> a(rows, vector<double>(cols, 0.0));
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            for (int k = 0; k < cols; ++k) {
                a[i][j] += matrix[i][k] * weights[k][j];
            }
        }
    }
    
    vector<vector<double>> result(rows, vector<double>(cols, 0.0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = tanh(a[i][j]);
        }
    }
    
    return result;
}

int main() {
    vector<vector<double>> weights = {{0.2, 0.5}, {0.4, 0.3}};
    vector<vector<double>> matrix = {{0.1, 0.2}, {0.3, 0.4}};
    vector<vector<double>> result = forward_pass(matrix, weights);
    
    for (const auto& row : result) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}