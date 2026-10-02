#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

double calculate_price(const std::string& option_type, double S, double K, double T, double r, double sigma, int n) {
    if (n == 0) {
        if (option_type == "call") {
            return std::max(S - K, 0.0);
        } else {
            return std::max(K - S, 0.0);
        }
    } else {
        double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
        double d2 = d1 - sigma * std::sqrt(T);
        if (option_type == "call") {
            return S * std::exp(-r * T) * norm_cdf(d1) - K * std::exp(-r * T) * norm_cdf(d2);
        } else {
            return K * std::exp(-r * T) * norm_cdf(-d2) - S * std::exp(-r * T) * norm_cdf(-d1);
        }
    }
}

double norm_cdf(double x) {
    return 0.5 * (1.0 + std::erf(x / std::sqrt(2.0)));
}

double monte_carlo_simulation(const std::string& option_type, double S, double K, double T, double r, double sigma, int N, int n) {
    double total_price = 0.0;
    for (int _ = 0; _ < N; ++_) {
        double S_T = S;
        for (int _ = 0; _ < n; ++_) {
            double z = std::gaussrand();
            S_T *= std::exp((r - 0.5 * sigma * sigma) * T / n + sigma * std::sqrt(T / n) * z);
        }
        total_price += calculate_price(option_type, S_T, K, T, r, sigma, 0);
    }
    return total_price / N;
}

int main() {
    double S = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 10000;
    int n = 10;
    std::string option_type = "call";
    double result = monte_carlo_simulation(option_type, S, K, T, r, sigma, N, n);
    std::cout << result << std::endl;
    return 0;
}