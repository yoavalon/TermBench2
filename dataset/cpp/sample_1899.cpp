#include <iostream>
#include <vector>
#include <cmath>
#include <string>

std::vector<std::vector<double>> process_text(const std::vector<std::string>& data) {
    std::vector<std::vector<double>> vectors(data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        vectors[i].resize(data[i].size());
        for (size_t j = 0; j < data[i].size(); ++j) {
            vectors[i][j] = static_cast<double>(data[i][j]);
        }
    }

    std::vector<double> norms(vectors.size());
    for (size_t i = 0; i < vectors.size(); ++i) {
        norms[i] = 0.0;
        for (size_t j = 0; j < vectors[i].size(); ++j) {
            norms[i] += vectors[i][j] * vectors[i][j];
        }
        norms[i] = std::sqrt(norms[i]);
    }

    for (size_t i = 0; i < vectors.size(); ++i) {
        for (size_t j = 0; j < vectors[i].size(); ++j) {
            vectors[i][j] /= norms[i];
        }
    }

    return vectors;
}

int main() {
    std::vector<std::string> data = {"hello", "world"};
    std::vector<std::vector<double>> result = process_text(data);

    for (const auto& vec : result) {
        for (double val : vec) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}