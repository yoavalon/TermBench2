#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <unordered_map>
#include <sstream>

std::vector<std::vector<int>> preprocess_data(const std::vector<std::string>& data) {
    std::unordered_map<std::string, int> vocabulary;
    std::vector<std::vector<int>> matrix(data.size());

    for (const auto& sentence : data) {
        std::istringstream stream(sentence);
        std::string word;
        while (stream >> word) {
            for (char& c : word) c = std::tolower(c);
            if (word.length() >= 2) {
                if (vocabulary.find(word) == vocabulary.end()) {
                    vocabulary[word] = vocabulary.size();
                }
                matrix.back().push_back(vocabulary[word]);
            }
        }
        matrix.back().resize(vocabulary.size());
    }

    return matrix;
}

std::vector<std::vector<int>> mutate_vectors(std::vector<std::vector<int>>& matrix) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 9);

    for (auto& row : matrix) {
        for (auto& value : row) {
            if (value > 0) {
                value = dis(gen);
            }
        }
    }

    return matrix;
}

void main() {
    std::vector<std::string> data_samples = {"The quick brown fox jumps over the lazy dog", "Hello world! This is a test sentence.", "Another example with some words."};
    std::vector<std::vector<int>> vector_matrix = preprocess_data(data_samples);
    std::vector<std::vector<int>> mutated_matrix = mutate_vectors(vector_matrix);

    for (const auto& row : mutated_matrix) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}