#include <iostream>
#include <vector>
#include <cmath>
#include <random>

std::vector<std::vector<double>> simulate_paths(double S0, double mu, double sigma, double T, int N, int M) {
    double dt = T / N;
    std::vector<std::vector<double>> paths(N + 1, std::vector<double>(M));
    paths[0] = std::vector<double>(M, S0);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0.0, 1.0);
    for (int t = 1; t <= N; ++t) {
        for (int m = 0; m < M; ++m) {
            double rand = d(gen);
            paths[t][m] = paths[t - 1][m] * std::exp((mu - 0.5 * sigma * sigma) * dt + sigma * std::sqrt(dt) * rand);
        }
    }
    return paths;
}

double option_price(const std::vector<std::vector<double>>& paths, double K, double r, double T) {
    int M = paths[0].size();
    double payoff = 0.0;
    for (int m = 0; m < M; ++m) {
        payoff += std::max(paths.back()[m] - K, 0.0);
    }
    return std::exp(-r * T) * (payoff / M);
}

void main() {
    double S0 = 100;
    double K = 100;
    double r = 0.05;
    double T = 1;
    int N = 252;
    int M = 10000;
    auto paths = simulate_paths(S0, r, 0.2, T, N, M);
    double price = option_price(paths, K, r, T);
    std::cout << "Option Price: " << std::fixed << std::setprecision(4) << price << std::endl;
}