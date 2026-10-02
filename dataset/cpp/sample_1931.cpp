#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

MatrixXd process_text(const vector<string>& data) {
    int n = data.size();
    int dim = data[0].size();
    MatrixXd vectors(n, dim);
    for (int i = 0; i < n; ++i) {
        stringstream ss(data[i]);
        for (int j = 0; j < dim; ++j) {
            ss >> vectors(i, j);
        }
    }
    return vectors;
}

MatrixXd compute_similarity(const MatrixXd& vectors) {
    MatrixXd dot_products = vectors * vectors.transpose();
    VectorXd norms = vectors.rowwise().norm();
    MatrixXd similarities = dot_products.array() / (norms * norms.transpose()).array();
    return similarities;
}

int main() {
    vector<string> data = {"0.1 0.2 0.3", "0.4 0.5 0.6", "0.7 0.8 0.9"};
    MatrixXd vectors = process_text(data);
    MatrixXd similarities = compute_similarity(vectors);
    cout << similarities << endl;
    return 0;
}