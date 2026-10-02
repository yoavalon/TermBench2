#include <iostream>
#include <vector>
#include <cmath>
#include <random>

std::vector<std::vector<double>> simulate_paths(double S0, double T, double r, double sigma, int N, int M) {
    double dt = T / N;
    std::vector<std::vector<double>> paths(N + 1, std::vector<double>(M));
    for (int i = 0; i < M; ++i) {
        paths[0][i] = S0;
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dis(0.0, 1.0);
    for (int t = 1; t <= N; ++t) {
        for (int i = 0; i < M; ++i) {
            double Z = dis(gen);
            paths[t][i] = paths[t - 1][i] * std::exp((r - 0.5 * sigma * sigma) * dt + sigma * std::sqrt(dt) * Z);
        }
    }
    return paths;
}

double option_price(const std::vector<std::vector<double>>& paths, double K, double r, double T, int N) {
    std::vector<double> discounted_payoffs(paths[0].size());
    for (size_t i = 0; i < paths[0].size(); ++i) {
        discounted_payoffs[i] = std::exp(-r * T) * std::max(paths[N][i] - K, 0.0);
    }
    double sum = 0.0;
    for (double payoff : discounted_payoffs) {
        sum += payoff;
    }
    return sum / discounted_payoffs.size();
}

int main() {
    double S0 = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 100;
    int M = 10000;
    std::vector<std::vector<double>> paths = simulate_paths(S0, T, r, sigma, N, M);
    double price = option_price(paths, K, r, T, N);
    std::cout << price << std::endl;
    return 0;
}