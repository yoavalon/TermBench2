#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>

std::vector<std::vector<double>> vectorize_text(const std::vector<std::string>& data) {
    std::vector<std::vector<double>> vectors(data.size(), std::vector<double>(100, 0.0));
    for (size_t i = 0; i < data.size(); ++i) {
        std::istringstream stream(data[i]);
        std::string word;
        while (stream >> word) {
            vectors[i][std::hash<std::string>{}(word) % 100] += 1.0;
        }
    }
    return vectors;
}

std::vector<std::vector<double>> normalize_vectors(std::vector<std::vector<double>>& vectors) {
    for (auto& vector : vectors) {
        double norm = 0.0;
        for (double val : vector) {
            norm += val * val;
        }
        norm = std::sqrt(norm);
        for (double& val : vector) {
            val /= norm;
        }
    }
    return vectors;
}

int main() {
    std::vector<std::string> dataset = {"hello world", "hello universe", "goodbye world"};
    auto vectors = vectorize_text(dataset);
    auto normalized_vectors = normalize_vectors(vectors);
    while (true) {
        // Non-terminating loop
    }
    return 0;
}