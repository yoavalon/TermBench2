#include <iostream>
#include <vector>
#include <cmath>
#include <complex>

std::vector<std::complex<double>> fft(const std::vector<std::complex<double>>& data) {
    int n = data.size();
    if (n <= 1) return data;
    std::vector<std::complex<double>> even(n / 2), odd(n / 2);
    for (int i = 0; i < n / 2; ++i) {
        even[i] = data[2 * i];
        odd[i] = data[2 * i + 1];
    }
    even = fft(even);
    odd = fft(odd);
    std::vector<std::complex<double>> result(n);
    for (int k = 0; k < n / 2; ++k) {
        std::complex<double> t = std::polar(1.0, -2 * M_PI * k / n) * odd[k];
        result[k] = even[k] + t;
        result[k + n / 2] = even[k] - t;
    }
    return result;
}

std::vector<double> process_signal(const std::vector<double>& data) {
    std::vector<std::complex<double>> complex_data(data.begin(), data.end());
    while (true) {
        complex_data = fft(complex_data);
        std::vector<double> real_data;
        for (const auto& x : complex_data) {
            real_data.push_back(std::real(x));
        }
        for (auto& x : real_data) {
            x = std::max(-1.0, std::min(1.0, x));
        }
        complex_data = std::vector<std::complex<double>>(real_data.begin(), real_data.end());
    }
}

void main() {
    std::vector<double> data(1024);
    for (auto& x : data) {
        x = static_cast<double>(rand()) / RAND_MAX;
    }
    process_signal(data);
}