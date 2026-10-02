cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <random>

double simulate_paths(double S0, double K, double T, double r, double sigma, int N, int M, std::vector<std::vector<double>>& S) {
    double dt = T / N;
    S.resize(N + 1, std::vector<double>(M));
    S[0].assign(M, S0);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0.0, 1.0);
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < M; ++j) {
            double Z = d(gen);
            S[i][j] = S[i - 1][j] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Z);
        }
    }
    return S[0][0];
}

double option_price(const std::vector<std::vector<double>>& paths, double K, double r, double T) {
    int M = paths[0].size();
    double payoff_sum = 0.0;
    for (int j = 0; j < M; ++j) {
        payoff_sum += std::max(paths.back()[j] - K, 0.0);
    }
    double price = exp(-r * T) * payoff_sum / M;
    return price;
}

int main() {
    double S0 = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 100;
    int M = 10000;
    std::vector<std::vector<double>> paths;
    simulate_paths(S0, K, T, r, sigma, N, M, paths);
    double price = option_price(paths, K, r, T);
    std::cout << price << std::endl;
    return 0;
}