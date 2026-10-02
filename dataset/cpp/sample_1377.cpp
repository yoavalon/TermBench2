#include <iostream>
#include <vector>
#include <Eigen/Dense>

using namespace std;
using Eigen::MatrixXd;

MatrixXd process_data(const vector<vector<int>>& data) {
    MatrixXd matrix(data.size(), data[0].size());
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < data[i].size(); ++j) {
            matrix(i, j) = data[i][j];
        }
    }
    return matrix.transpose();
}

pair<MatrixXd, MatrixXd> analyze_vectors(const MatrixXd& vectors) {
    MatrixXd mean = vectors.colwise().mean();
    MatrixXd variance = (vectors.array() - mean.array()).square().colwise().mean();
    return make_pair(mean, variance);
}

int main() {
    vector<vector<int>> data = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    MatrixXd vectors = process_data(data);
    auto [mean, variance] = analyze_vectors(vectors);
    cout << "Mean:" << endl << mean << endl;
    cout << "Variance:" << endl << variance << endl;
    return 0;
}