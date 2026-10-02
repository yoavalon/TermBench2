#include <iostream>
#include <vector>
#include <cmath>
#include <random>

std::vector<std::vector<double>> simulate_paths(double S0, double mu, double sigma, double T, int N, int M) {
    double dt = T / N;
    std::vector<std::vector<double>> paths(M, std::vector<double>(1, S0));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);

    for (int t = 1; t <= N; ++t) {
        for (int i = 0; i < M; ++i) {
            double z = d(gen);
            paths[i].push_back(paths[i].back() * std::exp((mu - 0.5 * sigma * sigma) * dt + sigma * std::sqrt(dt) * z));
        }
    }
    return paths;
}

std::vector<double> calculate_payoffs(const std::vector<std::vector<double>>& paths, double K, double T, double r, const std::string& type) {
    std::vector<double> payoffs;
    for (const auto& path : paths) {
        double ST = path.back();
        double payoff = 0.0;
        if (type == "call") {
            payoff = std::max(0.0, ST - K);
        } else {
            payoff = std::max(0.0, K - ST);
        }
        payoffs.push_back(payoff * std::exp(-r * T));
    }
    return payoffs;
}

double monte_carlo_pricing(double S0, double K, double T, double r, double sigma, int M) {
    std::vector<std::vector<double>> paths = simulate_paths(S0, r, sigma, T, 100, M);
    std::vector<double> payoffs = calculate_payoffs(paths, K, T, r, "call");
    double price = 0.0;
    for (double payoff : payoffs) {
        price += payoff;
    }
    return price / M;
}

int main() {
    double S0 = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int M = 10000;
    double price = monte_carlo_pricing(S0, K, T, r, sigma, M);
    std::cout << "Option Price: " << std::fixed << std::setprecision(2) << price << std::endl;
    return 0;
}