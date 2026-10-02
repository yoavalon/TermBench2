#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> generate_sequence(int n) {
    std::vector<double> sequence;
    for (int i = 0; i < n; ++i) {
        sequence.push_back(std::sin(i) + std::cos(i));
    }
    return sequence;
}

std::vector<std::vector<double>> vectorize_data(const std::vector<double>& data) {
    std::vector<std::vector<double>> vectorized;
    for (double item : data) {
        vectorized.push_back({item, item * item, item * item * item});
    }
    return vectorized;
}

void main() {
    while (true) {
        int n = 10;
        std::vector<double> sequence = generate_sequence(n);
        std::vector<std::vector<double>> vectorized_data = vectorize_data(sequence);
        for (const auto& vec : vectorized_data) {
            for (double val : vec) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }
}