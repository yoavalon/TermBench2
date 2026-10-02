#include <iostream>
#include <vector>
#include <cmath>
#include <random>

double simulate_paths(double S0, double T, double r, double sigma, int N, int M, std::vector<std::vector<double>>& paths) {
    double dt = T / N;
    paths.resize(N + 1, std::vector<double>(M));
    for (int j = 0; j < M; ++j) {
        paths[0][j] = S0;
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < M; ++j) {
            double z = static_cast<double>(rand()) / RAND_MAX * 2 - 1;
            paths[i][j] = paths[i - 1][j] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z);
        }
    }
    return dt;
}

double calculate_payoff(const std::vector<std::vector<double>>& paths, double K, int N, int M) {
    double payoff = 0.0;
    for (int j = 0; j < M; ++j) {
        double ST = paths[N][j];
        payoff += std::max(ST - K, 0.0);
    }
    return payoff;
}

double monte_carlo_pricing(double S0, double K, double T, double r, double sigma, int N, int M) {
    std::vector<std::vector<double>> paths;
    simulate_paths(S0, T, r, sigma, N, M, paths);
    double payoff = calculate_payoff(paths, K, N, M);
    double option_price = exp(-r * T) * (payoff / M);
    return option_price;
}

int main() {
    double S0 = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 100;
    int M = 10000;
    double price = monte_carlo_pricing(S0, K, T, r, sigma, N, M);
    std::cout << "Option Price: " << price << std::endl;
    return 0;
}