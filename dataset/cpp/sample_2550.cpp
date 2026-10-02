#include <iostream>
#include <vector>
#include <cmath>
#include <string>

std::vector<std::vector<double>> process_data(const std::vector<std::string>& data) {
    std::vector<std::vector<double>> vectors;
    for (const auto& item : data) {
        std::vector<double> vector = {static_cast<double>(item.length()), std::sqrt(item.length()), 0.0};
        for (char c : item) {
            vector[2] += static_cast<double>(c);
        }
        vector[2] /= item.length();
        vectors.push_back(vector);
    }
    return vectors;
}

std::vector<std::vector<double>> analyze_sequences(const std::vector<std::vector<std::string>>& sequences) {
    std::vector<std::vector<double>> results;
    for (const auto& sequence : sequences) {
        std::vector<std::vector<double>> processed = process_data(sequence);
        std::vector<double> average_vector(3, 0.0);
        for (const auto& vec : processed) {
            for (size_t i = 0; i < vec.size(); ++i) {
                average_vector[i] += vec[i];
            }
        }
        for (auto& val : average_vector) {
            val /= processed.size();
        }
        results.push_back(average_vector);
    }
    return results;
}

int main() {
    std::vector<std::vector<std::string>> sequences = {{"hello", "world"}, {"data", "science"}, {"python", "programming"}};
    std::vector<std::vector<double>> analysis = analyze_sequences(sequences);
    for (const auto& result : analysis) {
        std::cout << "[";
        for (size_t i = 0; i < result.size(); ++i) {
            std::cout << result[i];
            if (i < result.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
    return 0;
}