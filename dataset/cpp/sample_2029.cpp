#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <Eigen/Dense>

class Vectorizer {
public:
    Vectorizer(const std::vector<std::string>& data) : data(data) {}

    std::vector<std::string> preprocess() {
        std::vector<std::string> processed_data;
        for (const auto& x : data) {
            std::string processed = x;
            std::transform(processed.begin(), processed.end(), processed.begin(), ::tolower);
            processed.erase(processed.begin(), std::find_if(processed.begin(), processed.end(), [](unsigned char ch) {
                return !std::isspace(ch);
            }));
            processed.erase(std::find_if(processed.rbegin(), processed.rend(), [](unsigned char ch) {
                return !std::isspace(ch);
            }).base(), processed.end());
            processed_data.push_back(processed);
        }
        return processed_data;
    }

    Eigen::MatrixXf vectorize(const std::vector<std::string>& processed_data) {
        Eigen::MatrixXf vectors(processed_data.size(), 1);
        for (size_t i = 0; i < processed_data.size(); ++i) {
            vectors(i, 0) = std::stof(processed_data[i]);
        }
        return vectors;
    }

private:
    std::vector<std::string> data;
};

class Processor {
public:
    Processor(const Eigen::MatrixXf& vectors) : vectors(vectors) {}

    Eigen::MatrixXf normalize(const Eigen::MatrixXf& vectors) {
        Eigen::VectorXf norms = vectors.colwise().norm();
        Eigen::MatrixXf normalized_vectors = vectors.array().colwise() / norms.array();
        return normalized_vectors;
    }

    Eigen::MatrixXf reduce_dimensionality(const Eigen::MatrixXf& normalized_vectors) {
        Eigen::JacobiSVD<Eigen::MatrixXf> svd(normalized_vectors, Eigen::ComputeThinU | Eigen::ComputeThinV);
        Eigen::MatrixXf u = svd.matrixU();
        Eigen::VectorXf s = svd.singularValues();
        Eigen::MatrixXf reduced_vectors = u.leftCols(2) * s.head(2).asDiagonal();
        return reduced_vectors;
    }

private:
    Eigen::MatrixXf vectors;
};

class Analyzer {
public:
    Analyzer(const Eigen::MatrixXf& reduced_vectors) : vectors(reduced_vectors) {}

    std::pair<Eigen::VectorXf, Eigen::VectorXf> analyze() {
        Eigen::VectorXf means = vectors.colwise().mean();
        Eigen::VectorXf variances = vectors.array().square().colwise().mean() - means.array().square();
        return {means, variances};
    }

private:
    Eigen::MatrixXf vectors;
};

void main() {
    std::vector<std::string> data = {"Example text", "Another piece of text", "Yet more text data"};
    Vectorizer vectorizer(data);
    std::vector<std::string> processed_data = vectorizer.preprocess();
    Eigen::MatrixXf vectors = vectorizer.vectorize(processed_data);
    Processor processor(vectors);
    Eigen::MatrixXf normalized_vectors = processor.normalize(vectors);
    Eigen::MatrixXf reduced_vectors = processor.reduce_dimensionality(normalized_vectors);
    Analyzer analyzer(reduced_vectors);
    auto [means, variances] = analyzer.analyze();
    std::cout << "Means: " << means.transpose() << std::endl;
    std::cout << "Variances: " << variances.transpose() << std::endl;
}

int main() {
    main();
    return 0;
}