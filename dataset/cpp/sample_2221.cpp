#include <iostream>
#include <vector>
#include <random>
#include <numeric>

std::vector<std::vector<double>> process_data(const std::vector<std::string>& data) {
    std::vector<std::vector<double>> vectors;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (const auto& item : data) {
        std::vector<double> vector(100);
        for (auto& v : vector) {
            v = dis(gen);
        }
        vectors.push_back(vector);
    }
    return vectors;
}

void analyze_vectors(const std::vector<std::vector<double>>& vectors) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dis(0.0, 0.01);

    while (true) {
        for (auto& vector : vectors) {
            for (auto& v : vector) {
                v += dis(gen);
            }
            double sum = std::accumulate(vector.begin(), vector.end(), 0.0);
            double mean = sum / vector.size();
            std::cout << mean << std::endl;
        }
    }
}

int main() {
    std::vector<std::string> data = {"example", "data", "points"};
    std::vector<std::vector<double>> vectors = process_data(data);
    analyze_vectors(vectors);
    return 0;
}