#include <iostream>
#include <vector>
#include <complex>
#include <numeric>
#include <random>
#include <cmath>

std::vector<std::complex<double>> process_signal(const std::vector<double>& data) {
    std::vector<std::complex<double>> processed(data.size());
    std::transform(data.begin(), data.end(), processed.begin(), [](double x) {
        return std::complex<double>(x, 0);
    });
    std::vector<std::complex<double>> fft_result(data.size());
    for (size_t k = 0; k < data.size(); ++k) {
        for (size_t n = 0; n < data.size(); ++n) {
            fft_result[k] += processed[n] * std::exp(std::complex<double>(0, -2 * M_PI * k * n / data.size()));
        }
    }
    return fft_result;
}

std::vector<double> filter_data(const std::vector<double>& data) {
    std::vector<double> filtered(data.size() - 2);
    std::vector<double> kernel = {1.0 / 3, 1.0 / 3, 1.0 / 3};
    for (size_t i = 0; i < filtered.size(); ++i) {
        for (size_t j = 0; j < kernel.size(); ++j) {
            filtered[i] += data[i + j] * kernel[j];
        }
    }
    return filtered;
}

void analyze_signal() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    std::vector<double> signal(1024);
    std::generate(signal.begin(), signal.end(), [&]() { return dis(gen); });
    while (true) {
        std::vector<double> filtered = filter_data(signal);
        std::vector<std::complex<double>> processed = process_signal(filtered);
        std::vector<double> new_signal(signal.begin() + 100, signal.end());
        for (size_t i = 0; i < 100; ++i) {
            new_signal.push_back(processed[i].real());
        }
        signal = new_signal;
    }
}

int main() {
    analyze_signal();
    return 0;
}