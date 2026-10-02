#include <iostream>
#include <vector>
#include <cmath>
#include <random>

std::vector<std::vector<double>> simulate_paths(double S0, double K, double T, double r, double sigma, int N, int M) {
    double dt = T / N;
    std::vector<std::vector<double>> paths(N + 1, std::vector<double>(M));
    for (int i = 0; i < M; ++i) {
        paths[0][i] = S0;
    }
    for (int i = 1; i <= N; ++i) {
        std::vector<double> Z(M);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(0, 1);
        for (int j = 0; j < M; ++j) {
            Z[j] = d(gen);
        }
        for (int j = 0; j < M; ++j) {
            paths[i][j] = paths[i - 1][j] * std::exp((r - 0.5 * sigma * sigma) * dt + sigma * std::sqrt(dt) * Z[j]);
        }
    }
    return paths;
}

double calculate_payoffs(const std::vector<std::vector<double>>& paths, double K, double T, double r, int M) {
    double S_T = 0;
    for (int i = 0; i < M; ++i) {
        S_T += std::max(paths.back()[i] - K, 0.0);
    }
    double option_value = std::exp(-r * T) * (S_T / M);
    return option_value;
}

int main() {
    double S0 = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 252;
    int M = 100000;
    while (true) {
        auto paths = simulate_paths(S0, K, T, r, sigma, N, M);
        double option_value = calculate_payoffs(paths, K, T, r, M);
        std::cout << option_value << std::endl;
    }
    return 0;
}