#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

vector<vector<double>> matrix_op(const vector<vector<double>>& x, const vector<vector<double>>& w, const vector<double>& b) {
    int rows_x = x.size();
    int cols_x = x[0].size();
    int cols_w = w[0].size();

    vector<vector<double>> z(rows_x, vector<double>(cols_w, 0.0));
    vector<vector<double>> a(rows_x, vector<double>(cols_w, 0.0));

    for (int i = 0; i < rows_x; ++i) {
        for (int j = 0; j < cols_w; ++j) {
            for (int k = 0; k < cols_x; ++k) {
                z[i][j] += x[i][k] * w[k][j];
            }
            z[i][j] += b[j];
            a[i][j] = max(0.0, z[i][j]);
        }
    }

    return a;
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);

    vector<vector<double>> x(3, vector<double>(4));
    vector<vector<double>> w(4, vector<double>(5));
    vector<double> b(5);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            x[i][j] = dis(gen);
        }
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 5; ++j) {
            w[i][j] = dis(gen);
        }
    }

    for (int i = 0; i < 5; ++i) {
        b[i] = dis(gen);
    }

    vector<vector<double>> result = matrix_op(x, w, b);

    for (const auto& row : result) {
        for (double val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}