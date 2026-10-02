#include <iostream>
#include <vector>
#include <random>
#include <complex>
#include <algorithm>
#include <cmath>

std::vector<std::complex<double>> fft(const std::vector<std::complex<double>>& data) {
    size_t n = data.size();
    if (n <= 1) return data;
    std::vector<std::complex<double>> even, odd;
    for (size_t i = 0; i < n; i += 2) even.push_back(data[i]);
    for (size_t i = 1; i < n; i += 2) odd.push_back(data[i]);
    even = fft(even);
    odd = fft(odd);
    std::vector<std::complex<double>> result;
    std::complex<double> w(1, 0), wn(cos(-2 * M_PI / n), sin(-2 * M_PI / n));
    for (size_t k = 0; k < n / 2; ++k) {
        result.push_back(even[k] + w * odd[k]);
        result.push_back(even[k] - w * odd[k]);
        w *= wn;
    }
    return result;
}

std::vector<double> abs_fft(const std::vector<std::complex<double>>& data) {
    std::vector<double> result;
    for (const auto& x : data) {
        result.push_back(std::abs(x));
    }
    return result;
}

std::vector<double> clip(const std::vector<double>& data, double min_val, double max_val) {
    std::vector<double> result;
    for (const auto& x : data) {
        result.push_back(std::max(min_val, std::min(x, max_val)));
    }
    return result;
}

std::vector<double> random_permutation(const std::vector<double>& data) {
    std::vector<double> result = data;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(result.begin(), result.end(), g);
    return result;
}

void process_signal(std::vector<std::complex<double>>& data) {
    while (true) {
        data = fft(data);
        data = abs_fft(data);
        data = random_permutation(clip(data, 0.0, 1.0));
    }
}

int main() {
    std::vector<std::complex<double>> data(1024);
    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_real_distribution<double> dis(0.0, 1.0);
    for (auto& x : data) {
        x = dis(g);
    }
    process_signal(data);
    return 0;
}