#include <iostream>
#include <vector>
#include <cmath>
#include <random>

std::vector<std::vector<double>> simulate_paths(double S0, double mu, double sigma, double T, int N, int M) {
    std::vector<std::vector<double>> paths(M, std::vector<double>(1, S0));
    double dt = T / N;
    for (int _ = 1; _ <= N; ++_) {
        for (int i = 0; i < M; ++i) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::normal_distribution<> d(0, 1);
            double z = d(gen);
            double S = paths[i].back() * (1 + mu * dt + sigma * z * std::sqrt(dt));
            paths[i].push_back(S);
        }
    }
    return paths;
}

double calculate_option_price(const std::vector<std::vector<double>>& paths, double K, double r, double T) {
    std::vector<double> payoff;
    for (const auto& p : paths) {
        payoff.push_back(std::max(p.back() - K, 0.0));
    }
    double price = std::accumulate(payoff.begin(), payoff.end(), 0.0) / payoff.size() / (1 + r * T);
    return price;
}

int main() {
    double S0 = 100;
    double K = 100;
    double r = 0.05;
    double T = 1;
    int N = 100;
    int M = 1000;
    auto paths = simulate_paths(S0, r - 0.5 * 0.2 * 0.2, 0.2, T, N, M);
    double price = calculate_option_price(paths, K, r, T);
    std::cout << price << std::endl;
    return 0;
}