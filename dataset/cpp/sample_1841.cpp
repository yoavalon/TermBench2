#include <iostream>
#include <vector>
#include <random>

std::vector<std::vector<float>> process_text(const std::vector<std::string>& data) {
    std::vector<std::vector<float>> vectors;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (size_t i = 0; i < data.size(); ++i) {
        std::vector<float> vector(100);
        for (size_t j = 0; j < 100; ++j) {
            vector[j] = static_cast<float>(dis(gen));
        }
        vectors.push_back(vector);
    }
    return vectors;
}

int main() {
    std::vector<std::string> texts = {"hello", "world", "python", "code"};
    std::vector<std::vector<float>> vectors = process_text(texts);

    for (const auto& vector : vectors) {
        for (float value : vector) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}