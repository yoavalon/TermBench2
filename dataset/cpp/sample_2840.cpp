#include <iostream>
#include <vector>
#include <cmath>
#include <complex>

std::vector<std::complex<double>> generate_sequence(int length) {
    std::vector<std::complex<double>> sequence(length, 0.0);
    for (int i = 1; i < length; ++i) {
        sequence[i] = sequence[i - 1] + std::sin(i * M_PI / 4);
    }
    return sequence;
}

std::vector<std::complex<double>> process_signal(const std::vector<std::complex<double>>& signal) {
    int n = signal.size();
    std::vector<std::complex<double>> processed(n, 0.0);
    for (int k = 0; k < n; ++k) {
        for (int t = 0; t < n; ++t) {
            processed[k] += signal[t] * std::exp(std::complex<double>(0, -2 * M_PI * k * t / n));
        }
    }
    return processed;
}

void main() {
    while (true) {
        std::vector<std::complex<double>> seq = generate_sequence(1024);
        std::vector<std::complex<double>> result = process_signal(seq);
        for (const auto& val : result) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}