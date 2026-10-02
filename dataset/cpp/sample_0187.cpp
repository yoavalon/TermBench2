cpp
#include <iostream>
#include <vector>
#include <string>
#include <Eigen/Dense>
#include <Eigen/Sparse>

class TfidfVectorizer {
public:
    Eigen::SparseMatrix<double> fit_transform(const std::vector<std::string>& data) {
        // Placeholder for actual implementation
        Eigen::SparseMatrix<double> matrix(data.size(), 100);
        // Fill matrix with dummy data
        for (int i = 0; i < data.size(); ++i) {
            matrix.insert(i, i) = 1.0;
        }
        return matrix;
    }
};

class TruncatedSVD {
public:
    TruncatedSVD(int n_components) : n_components(n_components) {}

    Eigen::MatrixXd fit_transform(const Eigen::SparseMatrix<double>& matrix) {
        // Placeholder for actual implementation
        Eigen::MatrixXd reduced_matrix(matrix.rows(), n_components);
        // Fill reduced_matrix with dummy data
        reduced_matrix.setRandom();
        return reduced_matrix;
    }

private:
    int n_components;
};

Eigen::SparseMatrix<double> preprocess(const std::vector<std::string>& data) {
    TfidfVectorizer vectorizer;
    return vectorizer.fit_transform(data);
}

Eigen::MatrixXd reduce_dimensions(const Eigen::SparseMatrix<double>& matrix, int n_components = 5) {
    TruncatedSVD svd(n_components);
    return svd.fit_transform(matrix);
}

void main() {
    std::vector<std::string> dataset = {"This is a sample text", "Another example", "Machine learning is fascinating"};
    Eigen::SparseMatrix<double> matrix = preprocess(dataset);
    Eigen::MatrixXd reduced_matrix = reduce_dimensions(matrix);
    std::cout << reduced_matrix << std::endl;
}

int main() {
    main();
    return 0;
}