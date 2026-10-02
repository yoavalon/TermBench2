#include <iostream>
#include <vector>
#include <cmath>
#include <random>

double monte_carlo_pricing(double S, double K, double T, double r, double sigma, int N, int M) {
    double dt = T / M;
    std::vector<std::vector<double>> S_t(N, std::vector<double>(M + 1));
    for (int i = 0; i < N; ++i) {
        S_t[i][0] = S;
    }
    for (int t = 1; t <= M; ++t) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(0.0, 1.0);
        for (int i = 0; i < N; ++i) {
            double z = d(gen);
            S_t[i][t] = S_t[i][t - 1] * std::exp((r - 0.5 * sigma * sigma) * dt + sigma * std::sqrt(dt) * z);
        }
    }
    double payoff = 0.0;
    for (int i = 0; i < N; ++i) {
        payoff += std::max(S_t[i][M] - K, 0.0);
    }
    double option_price = std::exp(-r * T) * (payoff / N);
    return option_price;
}

int main() {
    std::cout << monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 10000, 100) << std::endl;
    return 0;
}