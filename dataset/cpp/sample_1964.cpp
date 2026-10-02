#include <iostream>
#include <vector>
#include <cmath>
#include <random>

std::vector<std::vector<double>> simulate_paths(double S0, double mu, double sigma, double T, int N, int M) {
    double dt = T / N;
    std::vector<std::vector<double>> paths(M, std::vector<double>(N + 1));
    for (int i = 0; i < M; ++i) {
        paths[i][0] = S0;
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0.0, 1.0);
    for (int t = 1; t <= N; ++t) {
        for (int i = 0; i < M; ++i) {
            double z = d(gen);
            paths[i][t] = paths[i][t - 1] * std::exp((mu - 0.5 * sigma * sigma) * dt + sigma * std::sqrt(dt) * z);
        }
    }
    return paths;
}

double option_price(const std::vector<std::vector<double>>& paths, double K, double r, double T) {
    double payoff_sum = 0.0;
    for (const auto& path : paths) {
        payoff_sum += std::max(path.back() - K, 0.0);
    }
    return std::exp(-r * T) * (payoff_sum / paths.size());
}

int main() {
    double S0 = 100.0;
    double K = 100.0;
    double r = 0.05;
    double T = 1.0;
    int N = 252;
    int M = 10000;
    auto paths = simulate_paths(S0, r, 0.2, T, N, M);
    double price = option_price(paths, K, r, T);
    std::cout << "Option price: " << std::fixed << std::setprecision(2) << price << std::endl;
    return 0;
}