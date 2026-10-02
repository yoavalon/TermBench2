#include <iostream>
#include <cmath>
#include <vector>
#include <random>

double financial_model(double S, double K, double T, double r, double sigma, int N, int M) {
    double dt = T / N;
    double S_t = S;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0.0, 1.0);
    for (int _ = 0; _ < N; ++_) {
        std::vector<double> z(M);
        for (int i = 0; i < M; ++i) {
            z[i] = d(gen);
        }
        for (int i = 0; i < M; ++i) {
            S_t = S_t * std::exp((r - 0.5 * sigma * sigma) * dt + sigma * std::sqrt(dt) * z[i]);
        }
    }
    double payoff = 0.0;
    for (int i = 0; i < M; ++i) {
        payoff += std::max(S_t - K, 0.0);
    }
    double option_price = std::exp(-r * T) * (payoff / M);
    return option_price;
}

int main() {
    double result = financial_model(100, 100, 1, 0.05, 0.2, 100, 10000);
    std::cout << result << std::endl;
    return 0;
}