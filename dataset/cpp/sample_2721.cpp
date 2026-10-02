#include <iostream>
#include <vector>
#include <complex>
#include <random>

std::vector<std::complex<double>> generate_sequence() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    std::vector<double> x(1024);
    for (auto& val : x) {
        val = dis(gen);
    }

    std::vector<std::complex<double>> y(1024);
    for (size_t k = 0; k < x.size(); ++k) {
        for (size_t n = 0; n < x.size(); ++n) {
            double angle = 2 * M_PI * k * n / x.size();
            y[k] += x[n] * std::exp(std::complex<double>(0, -angle));
        }
    }
    return y;
}

int main() {
    while (true) {
        auto y = generate_sequence();
        for (const auto& val : y) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}