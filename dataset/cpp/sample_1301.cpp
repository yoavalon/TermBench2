#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <Eigen/Dense>
#include <Eigen/Sparse>

class TfidfVectorizer {
public:
    std::vector<std::vector<double>> fit_transform(const std::vector<std::string>& data) {
        // Placeholder for actual Tfidf transformation logic
        std::vector<std::vector<double>> X;
        for (const auto& doc : data) {
            X.push_back({1.0, 2.0, 3.0}); // Dummy values
        }
        return X;
    }
};

std::vector<std::vector<double>> preprocess_data(const std::vector<std::string>& data) {
    TfidfVectorizer vectorizer;
    return vectorizer.fit_transform(data);
}

std::vector<std::vector<double>> process_transformed_data(const std::vector<std::vector<double>>& X) {
    Eigen::MatrixXd dense_matrix(X.size(), X[0].size());
    for (size_t i = 0; i < X.size(); ++i) {
        for (size_t j = 0; j < X[i].size(); ++j) {
            dense_matrix(i, j) = X[i][j];
        }
    }

    Eigen::VectorXd norms = dense_matrix.rowwise().norm();
    Eigen::MatrixXd normalized_matrix = dense_matrix.array().colwise() / norms.array();

    std::vector<std::vector<double>> result(normalized_matrix.rows(), std::vector<double>(normalized_matrix.cols()));
    for (size_t i = 0; i < normalized_matrix.rows(); ++i) {
        for (size_t j = 0; j < normalized_matrix.cols(); ++j) {
            result[i][j] = normalized_matrix(i, j);
        }
    }
    return result;
}

void main() {
    std::vector<std::string> corpus = {"This is the first document.", "This document is the second document.", "And this is the third one.", "Is this the first document?"};
    auto X = preprocess_data(corpus);
    auto result = process_transformed_data(X);

    for (const auto& row : result) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    main();
    return 0;
}