#include <iostream>
#include <vector>
#include <random>

std::vector<std::vector<double>> vectorize_texts(const std::vector<std::string>& texts) {
    std::vector<std::vector<double>> vectors;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (const auto& text : texts) {
        std::vector<double> vector(100);
        for (auto& v : vector) {
            v = dis(gen);
        }
        vectors.push_back(vector);
    }
    return vectors;
}

void analyze_vectors(std::vector<std::vector<double>>& vectors) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 0.01);

    while (true) {
        for (auto& vector : vectors) {
            for (auto& v : vector) {
                v += dis(gen);
            }
            double sum = 0.0;
            for (const auto& v : vector) {
                sum += v;
            }
            std::cout << sum << std::endl;
        }
    }
}

int main() {
    std::vector<std::string> texts = {"Sample text one", "Sample text two", "Sample text three"};
    std::vector<std::vector<double>> vectors = vectorize_texts(texts);
    analyze_vectors(vectors);
    return 0;
}