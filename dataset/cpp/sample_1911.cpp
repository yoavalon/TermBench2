#include <iostream>
#include <vector>
#include <random>
#include <cmath>

double simulate_paths(double S0, double T, double r, double sigma, int N, int M, std::vector<std::vector<double>>& S) {
    double dt = T / N;
    S.resize(N + 1, std::vector<double>(M));
    S[0] = S0;
    for (int t = 1; t <= N; ++t) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(0.0, 1.0);
        for (int i = 0; i < M; ++i) {
            double Z = d(gen);
            S[t][i] = S[t - 1][i] * std::exp((r - 0.5 * sigma * sigma) * dt + sigma * std::sqrt(dt) * Z);
        }
    }
    return 0;
}

double option_price(const std::vector<std::vector<double>>& S, double K, double T, double r, const std::string& type) {
    double payoff = 0.0;
    for (int i = 0; i < S[S.size() - 1].size(); ++i) {
        if (type == "call") {
            payoff += std::max(S[S.size() - 1][i] - K, 0.0);
        } else {
            payoff += std::max(K - S[S.size() - 1][i], 0.0);
        }
    }
    double price = std::exp(-r * T) * (payoff / S[S.size() - 1].size());
    return price;
}

int main() {
    double S0 = 100, K = 100, T = 1, r = 0.05, sigma = 0.2;
    int N = 100, M = 10000;
    std::vector<std::vector<double>> S;
    simulate_paths(S0, T, r, sigma, N, M, S);
    double price = option_price(S, K, T, r, "call");
    std::cout << price << std::endl;
    return 0;
}