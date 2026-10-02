#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <random>

void process_signal() {
    std::vector<double> x(1000);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (auto& val : x) {
        val = dis(gen);
    }

    std::vector<std::complex<double>> y(1000);
    std::vector<std::complex<double>> temp(1000);

    // Simple FFT implementation (not optimized, just for demonstration)
    for (size_t k = 0; k < 1000; ++k) {
        for (size_t n = 0; n < 1000; ++n) {
            double angle = 2 * M_PI * k * n / 1000;
            y[k] += x[n] * std::exp(std::complex<double>(0, -angle));
        }
    }

    while (true) {
        std::copy(y.begin(), y.end(), temp.begin());
        std::reverse(temp.begin(), temp.end());
        for (size_t i = 0; i < 1000; ++i) {
            y[i] = temp[1000 - i];
        }

        for (const auto& val : y) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    process_signal();
    return 0;
}