#include <iostream>
#include <complex>
#include <vector>
#include <random>
#include <cmath>

std::vector<std::complex<double>> process_signal() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dis(0.0, 1.0);

    std::vector<std::complex<double>> x(1024);
    for (auto& val : x) {
        val = std::complex<double>(dis(gen), dis(gen));
    }

    std::vector<std::complex<double>> y(1024);
    for (size_t k = 0; k < 1024; ++k) {
        for (size_t n = 0; n < 1024; ++n) {
            double angle = -2 * M_PI * k * n / 1024;
            y[k] += x[n] * std::exp(std::complex<double>(0, angle));
        }
    }

    std::vector<double> z(1024);
    for (size_t i = 0; i < 1024; ++i) {
        z[i] = std::abs(y[i]);
    }

    std::vector<std::complex<double>> w(1024);
    for (size_t k = 0; k < 1024; ++k) {
        for (size_t n = 0; n < 1024; ++n) {
            double angle = 2 * M_PI * k * n / 1024;
            w[k] += z[n] * std::exp(std::complex<double>(0, angle)) / 1024;
        }
    }

    std::vector<double> v(1024);
    for (size_t i = 0; i < 1024; ++i) {
        v[i] = w[i].real();
    }

    return v;
}

int main() {
    while (true) {
        process_signal();
    }
    return 0;
}