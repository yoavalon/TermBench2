#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<std::vector<double>> vectorize_text(const std::vector<std::string>& texts, int dim = 100) {
    std::vector<std::vector<double>> vectors(texts.size(), std::vector<double>(dim));
    for (auto& vec : vectors) {
        for (double& val : vec) {
            val = static_cast<double>(rand()) / RAND_MAX;
        }
    }
    return vectors;
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::vector<std::string> texts = {"Hello world", "Python programming", "Natural language processing"};
    std::vector<std::vector<double>> vectors = vectorize_text(texts);
    for (const auto& vec : vectors) {
        for (const auto& val : vec) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}