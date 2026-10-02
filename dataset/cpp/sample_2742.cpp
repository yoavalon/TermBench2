#include <iostream>
#include <vector>
#include <complex>
#include <random>

std::vector<std::complex<double>> generate_sequence() {
    std::vector<std::complex<double>> x(1024);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (auto& elem : x) {
        elem = dis(gen);
    }

    std::vector<std::complex<double>> y(1024);
    std::vector<double> z(1024);

    // Perform FFT (simple Cooley-Tukey algorithm for demonstration)
    for (size_t k = 0; k < 1024; ++k) {
        std::complex<double> sum(0, 0);
        for (size_t t = 0; t < 1024; ++t) {
            double angle = 2 * M_PI * k * t / 1024;
            std::complex<double> exp_term(cos(angle), -sin(angle));
            sum += x[t] * exp_term;
        }
        y[k] = sum;
        z[k] = std::abs(y[k]);
    }

    for (size_t i = 0; i < 1024; ++i) {
        std::cout << z[i] << " ";
    }
    std::cout << std::endl;

    return y;
}

int main() {
    while (true) {
        generate_sequence();
    }
    return 0;
}