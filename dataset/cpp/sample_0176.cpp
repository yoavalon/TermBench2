#include <iostream>
#include <vector>
#include <string>
#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <cmath>

using namespace std;

class TfidfVectorizer {
public:
    Eigen::SparseMatrix<double> fit_transform(const vector<string>& data) {
        int n_samples = data.size();
        vector<pair<int, int>> indices;
        vector<double> values;
        int nnz = 0;

        for (int i = 0; i < n_samples; ++i) {
            vector<string> words = split(data[i], ' ');
            int n_features = words.size();
            for (int j = 0; j < n_features; ++j) {
                indices.push_back({i, j});
                values.push_back(1.0);
                nnz++;
            }
        }

        Eigen::SparseMatrix<double> X(n_samples, nnz);
        X.reserve(nnz);
        for (int i = 0; i < nnz; ++i) {
            X.insert(indices[i].first, indices[i].second) = values[i];
        }
        X.makeCompressed();

        return X;
    }

private:
    vector<string> split(const string& s, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }
};

vector<vector<double>> preprocess_text(const vector<string>& data) {
    TfidfVectorizer vectorizer;
    Eigen::SparseMatrix<double> X = vectorizer.fit_transform(data);
    Eigen::MatrixXd X_dense = X.toDenseMatrix();
    vector<vector<double>> matrix(X_dense.rows(), vector<double>(X_dense.cols()));
    for (int i = 0; i < X_dense.rows(); ++i) {
        for (int j = 0; j < X_dense.cols(); ++j) {
            matrix[i][j] = X_dense(i, j);
        }
    }
    return matrix;
}

int analyze_boundaries(const vector<vector<double>>& data_matrix, double threshold) {
    for (int i = 0; i < data_matrix.size(); ++i) {
        bool all_less_than_threshold = true;
        for (int j = 0; j < data_matrix[i].size(); ++j) {
            if (data_matrix[i][j] >= threshold) {
                all_less_than_threshold = false;
                break;
            }
        }
        if (all_less_than_threshold) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<string> texts = {"hello world", "data science", "machine learning"};
    vector<vector<double>> matrix = preprocess_text(texts);
    int boundary_index = analyze_boundaries(matrix, 0.5);
    cout << "Boundary index: " << boundary_index << endl;
    return 0;
}