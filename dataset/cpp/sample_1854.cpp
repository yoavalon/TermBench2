#include <iostream>
#include <vector>
#include <string>
#include <Eigen/Dense>
#include <unordered_map>
#include <algorithm>

class TfidfVectorizer {
private:
    int max_features;
    std::unordered_map<std::string, int> word_to_index;
    std::vector<std::string> index_to_word;
    std::vector<int> word_count;
    std::vector<double> idf;

public:
    TfidfVectorizer(int dim) : max_features(dim) {}

    void fit(const std::vector<std::string>& data) {
        word_to_index.clear();
        index_to_word.clear();
        word_count.clear();
        idf.clear();

        for (const auto& text : data) {
            std::istringstream stream(text);
            std::string word;
            while (stream >> word) {
                if (word_to_index.find(word) == word_to_index.end()) {
                    word_to_index[word] = word_count.size();
                    index_to_word.push_back(word);
                    word_count.push_back(0);
                }
                word_count[word_to_index[word]]++;
            }
        }

        int n_samples = data.size();
        idf.resize(word_count.size(), 0.0);
        for (size_t i = 0; i < word_count.size(); ++i) {
            if (word_count[i] > 0) {
                idf[i] = std::log((n_samples + 1.0) / (word_count[i] + 1.0)) + 1.0;
            }
        }
    }

    Eigen::MatrixXd transform(const std::vector<std::string>& data) {
        Eigen::MatrixXd X(data.size(), max_features);
        X.setZero();

        for (size_t i = 0; i < data.size(); ++i) {
            std::istringstream stream(data[i]);
            std::string word;
            std::unordered_map<int, int> word_freq;
            while (stream >> word) {
                if (word_to_index.find(word) != word_to_index.end()) {
                    int index = word_to_index[word];
                    word_freq[index]++;
                }
            }

            for (const auto& [index, freq] : word_freq) {
                X(i, index) = freq * idf[index];
            }
        }

        return X;
    }
};

std::vector<std::vector<double>> process_text(const std::vector<std::string>& data, int dim = 100) {
    TfidfVectorizer vectorizer(dim);
    vectorizer.fit(data);
    Eigen::MatrixXd X = vectorizer.transform(data);
    std::vector<std::vector<double>> result(X.rows(), std::vector<double>(X.cols()));
    for (int i = 0; i < X.rows(); ++i) {
        for (int j = 0; j < X.cols(); ++j) {
            result[i][j] = X(i, j);
        }
    }
    return result;
}

void main() {
    std::vector<std::string> data = {"hello world", "goodbye universe", "python programming"};
    std::vector<std::vector<double>> result = process_text(data);
    for (const auto& row : result) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}