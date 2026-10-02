#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <random>
#include <numeric>

std::vector<std::string> preprocess_text(const std::vector<std::string>& data) {
    std::vector<std::string> result;
    for (const auto& x : data) {
        std::string lowercased = x;
        std::transform(lowercased.begin(), lowercased.end(), lowercased.begin(), ::tolower);
        lowercased.erase(lowercased.begin(), std::find_if(lowercased.begin(), lowercased.end(), [](unsigned char ch) {
            return !std::isspace(ch);
        }));
        lowercased.erase(std::find_if(lowercased.rbegin(), lowercased.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
        }).base(), lowercased.end());
        result.push_back(lowercased);
    }
    return result;
}

std::vector<std::vector<double>> create_embedding_matrix(int vocab_size, int embedding_dim) {
    std::vector<std::vector<double>> result(vocab_size, std::vector<double>(embedding_dim));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for (auto& row : result) {
        std::generate(row.begin(), row.end(), [&dis, &gen]() { return dis(gen); });
    }
    return result;
}

std::vector<std::vector<double>> vectorize_text(const std::vector<std::string>& data, const std::vector<std::vector<double>>& embedding_matrix) {
    std::vector<std::string> processed_data = preprocess_text(data);
    std::string joined_data = std::accumulate(processed_data.begin(), processed_data.end(), std::string());
    std::vector<std::vector<double>> vectorized_data;
    for (char char : joined_data) {
        int index = static_cast<int>(char) % embedding_matrix.size();
        vectorized_data.push_back(embedding_matrix[index]);
    }
    return vectorized_data;
}

int main() {
    std::vector<std::string> data = {"Hello", "world", "this", "is", "a", "test"};
    int vocab_size = 128;
    int embedding_dim = 10;
    std::vector<std::vector<double>> embedding_matrix = create_embedding_matrix(vocab_size, embedding_dim);
    std::vector<std::vector<double>> result = vectorize_text(data, embedding_matrix);
    for (const auto& row : result) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}