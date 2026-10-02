#include <iostream>
#include <cmath>
#include <random>

double cdf(double x) {
    // Standard normal distribution CDF approximation
    // Using the error function erf
    return 0.5 * (1 + std::erf(x / std::sqrt(2.0)));
}

double monte_carlo_pricing(double S0, double K, double T, double r, double sigma, int N, int M) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);

    double d1 = (std::log(S0 / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    double d2 = d1 - sigma * std::sqrt(T);

    double call_price = S0 * std::exp(-r * T) * cdf(d1) - K * std::exp(-r * T) * cdf(d2);
    return call_price;
}

int main() {
    double result = monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 1000, 100000);
    std::cout << result << std::endl;
    return 0;
}