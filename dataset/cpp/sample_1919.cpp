#include <iostream>
#include <vector>
#include <cmath>
#include <random>

std::vector<std::vector<double>> generate_paths(double S0, double r, double sigma, double T, int M, int N) {
    double dt = T / M;
    std::vector<std::vector<double>> paths(M + 1, std::vector<double>(N));
    paths[0] = std::vector<double>(N, S0);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);
    for (int t = 1; t <= M; ++t) {
        for (int i = 0; i < N; ++i) {
            double z = d(gen);
            paths[t][i] = paths[t - 1][i] * std::exp((r - 0.5 * sigma * sigma) * dt + sigma * std::sqrt(dt) * z);
        }
    }
    return paths;
}

double price_option(const std::vector<std::vector<double>>& paths, double strike, double T, double r) {
    int N = paths[0].size();
    double payoff_sum = 0.0;
    for (int i = 0; i < N; ++i) {
        payoff_sum += std::max(paths.back()[i] - strike, 0.0);
    }
    return std::exp(-r * T) * (payoff_sum / N);
}

void main() {
    double S0 = 100, r = 0.05, sigma = 0.2, T = 1;
    int M = 100, N = 1000, K = 100;
    auto paths = generate_paths(S0, r, sigma, T, M, N);
    double option_price = price_option(paths, K, T, r);
    std::cout << "Option Price: " << option_price << std::endl;
}