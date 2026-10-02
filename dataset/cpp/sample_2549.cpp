#include <iostream>
#include <vector>
#include <cmath>
#include <random>

std::vector<std::vector<double>> simulate_paths(double S0, double mu, double sigma, double T, int N, int M) {
    double dt = T / N;
    std::vector<std::vector<double>> paths(M, {S0});
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::normal_distribution<> d(0, 1);
            double dW = d(gen) * sqrt(dt);
            paths[j].push_back(paths[j].back() * (1 + mu * dt + sigma * dW));
        }
    }
    return paths;
}

double option_price(const std::vector<std::vector<double>>& paths, double K, double r, double T) {
    std::vector<double> payoff;
    for (const auto& path : paths) {
        payoff.push_back(std::max(path.back() - K, 0.0));
    }
    std::vector<double> discounted_payoff;
    for (double p : payoff) {
        discounted_payoff.push_back(p * (1 - r * T));
    }
    double sum = 0.0;
    for (double p : discounted_payoff) {
        sum += p;
    }
    return sum / discounted_payoff.size();
}

int main() {
    double S0 = 100, K = 100, T = 1, r = 0.05, sigma = 0.2;
    int N = 100, M = 1000;
    auto paths = simulate_paths(S0, r, sigma, T, N, M);
    double price = option_price(paths, K, r, T);
    std::cout << price << std::endl;
    return 0;
}