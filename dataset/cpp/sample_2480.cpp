#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<double>> nn_forward_pass(vector<vector<double>> x, vector<vector<double>> w, vector<double> b) {
    int n = x.size();
    int m = x[0].size();
    int k = w[0].size();

    vector<vector<double>> z(n, vector<double>(k, 0.0));
    vector<vector<double>> a(n, vector<double>(k, 0.0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            for (int l = 0; l < m; ++l) {
                z[i][j] += x[i][l] * w[l][j];
            }
            z[i][j] += b[j];
            a[i][j] = 1 / (1 + exp(-z[i][j]));
        }
    }

    return a;
}

int main() {
    vector<vector<double>> x = {{0, 1}, {1, 0}};
    vector<vector<double>> w = {{0.5, -0.5}, {-0.5, 0.5}};
    vector<double> b = {0.1, -0.1};

    vector<vector<double>> result = nn_forward_pass(x, w, b);

    for (const auto& row : result) {
        for (double val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}