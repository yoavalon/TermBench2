#include <iostream>
#include <vector>
#include <cmath>
#include <random>

std::vector<std::vector<double>> simulate_paths(double S0, double T, double r, double sigma, int N, int M) {
    double dt = T / M;
    std::vector<std::vector<double>> paths(N, std::vector<double>(M));
    for (int i = 0; i < N; ++i) {
        paths[i][0] = S0;
    }
    for (int t = 1; t < M; ++t) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(0, 1);
        for (int i = 0; i < N; ++i) {
            double z = d(gen);
            paths[i][t] = paths[i][t - 1] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z);
        }
    }
    return paths;
}

double option_pricing(const std::vector<std::vector<double>>& paths, double K, double T, double r, int M) {
    int N = paths.size();
    double payoff_sum = 0;
    for (int i = 0; i < N; ++i) {
        payoff_sum += std::max(paths[i][M - 1] - K, 0.0);
    }
    double price = exp(-r * T) * (payoff_sum / N);
    return price;
}

int main() {
    double S0 = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 10000;
    int M = 100;
    auto paths = simulate_paths(S0, T, r, sigma, N, M);
    double option_price = option_pricing(paths, K, T, r, M);
    std::cout << option_price << std::endl;
    return 0;
}