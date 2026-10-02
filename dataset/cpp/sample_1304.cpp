#include <iostream>
#include <vector>
#include <cmath>
#include <random>

std::vector<std::vector<double>> simulate_paths(double S0, double mu, double sigma, double T, int N, int M) {
    double dt = T / N;
    std::vector<std::vector<double>> S(M, std::vector<double>(N));
    for (int i = 0; i < M; ++i) {
        S[i][0] = S0;
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0.0, 1.0);
    for (int t = 1; t < N; ++t) {
        for (int i = 0; i < M; ++i) {
            double z = d(gen);
            S[i][t] = S[i][t - 1] * exp((mu - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z);
        }
    }
    return S;
}

double calculate_option_price(const std::vector<std::vector<double>>& paths, double K, double r, double T) {
    int M = paths.size();
    double payoff_sum = 0.0;
    for (int i = 0; i < M; ++i) {
        payoff_sum += std::max(paths[i][paths[i].size() - 1] - K, 0.0);
    }
    double option_price = exp(-r * T) * (payoff_sum / M);
    return option_price;
}

int main() {
    double S0 = 100;
    double K = 100;
    double r = 0.05;
    double T = 1;
    int N = 252;
    int M = 10000;
    auto paths = simulate_paths(S0, r, 0.2, T, N, M);
    double option_price = calculate_option_price(paths, K, r, T);
    std::cout << option_price << std::endl;
    return 0;
}