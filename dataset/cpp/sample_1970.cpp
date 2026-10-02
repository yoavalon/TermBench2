#include <iostream>
#include <vector>
#include <random>
#include <numeric>
#include <cmath>

std::vector<std::vector<double>> process_data(const std::vector<std::string>& data) {
    std::vector<std::vector<double>> vectors;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (size_t i = 0; i < data.size(); ++i) {
        std::vector<double> vector(100);
        for (double& val : vector) {
            val = dis(gen);
        }
        vectors.push_back(vector);
    }
    return vectors;
}

double analyze_vectors(const std::vector<std::vector<double>>& vectors) {
    std::vector<double> mean_vector(100, 0.0);
    for (const auto& vector : vectors) {
        for (size_t i = 0; i < vector.size(); ++i) {
            mean_vector[i] += vector[i];
        }
    }
    for (double& val : mean_vector) {
        val /= vectors.size();
    }

    double precision_loss = 0.0;
    for (const auto& vector : vectors) {
        for (size_t i = 0; i < vector.size(); ++i) {
            precision_loss += std::abs(vector[i] - mean_vector[i]);
        }
    }
    precision_loss /= (vectors.size() * vector.size());
    return precision_loss;
}

int main() {
    std::vector<std::string> data(1000, "sample text");
    std::vector<std::vector<double>> vectors = process_data(data);
    double loss = analyze_vectors(vectors);
    std::cout << "Precision Loss: " << loss << std::endl;
    return 0;
}