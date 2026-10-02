#include <iostream>
#include <vector>
#include <complex>
#include <numeric>
#include <cmath>

std::vector<std::complex<double>> process_signal(const std::vector<double>& data) {
    std::vector<std::complex<double>> processed_data(data.size());
    std::complex<double> I(0, 1);
    for (size_t k = 0; k < data.size(); ++k) {
        processed_data[k] = 0;
        for (size_t n = 0; n < data.size(); ++n) {
            processed_data[k] += data[n] * std::exp(-2 * M_PI * I * k * n / data.size());
        }
    }
    return processed_data;
}

void main() {
    std::vector<double> data(1024);
    std::generate(data.begin(), data.end(), std::rand);
    std::vector<std::complex<double>> result = process_signal(data);
    for (const auto& val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}