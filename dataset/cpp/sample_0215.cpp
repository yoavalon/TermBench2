#include <iostream>
#include <vector>
#include <cmath>
#include <random>

std::vector<std::vector<double>> simulate_paths(double S0, double T, double r, double sigma, int N, int M) {
    double dt = T / N;
    std::vector<std::vector<double>> paths(N + 1, std::vector<double>(M));
    paths[0].assign(M, S0);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0.0, 1.0);
    for (int t = 1; t <= N; ++t) {
        for (int i = 0; i < M; ++i) {
            double z = d(gen);
            paths[t][i] = paths[t - 1][i] * std::exp((r - 0.5 * sigma * sigma) * dt + sigma * std::sqrt(dt) * z);
        }
    }
    return paths;
}

std::vector<double> payoff_function(const std::vector<std::vector<double>>& paths, double K, const std::string& option_type) {
    std::vector<double> payoff(paths.back().size());
    if (option_type == "call") {
        for (size_t i = 0; i < paths.back().size(); ++i) {
            payoff[i] = std::max(paths.back()[i] - K, 0.0);
        }
    } else if (option_type == "put") {
        for (size_t i = 0; i < paths.back().size(); ++i) {
            payoff[i] = std::max(K - paths.back()[i], 0.0);
        }
    }
    return payoff;
}

double price_option(double S0, double K, double T, double r, double sigma, int N, int M, const std::string& option_type) {
    std::vector<std::vector<double>> paths = simulate_paths(S0, T, r, sigma, N, M);
    std::vector<double> payoff = payoff_function(paths, K, option_type);
    double sum = 0.0;
    for (double p : payoff) {
        sum += p;
    }
    return std::exp(-r * T) * (sum / M);
}

int main() {
    double S0 = 100.0;
    double K = 100.0;
    double T = 1.0;
    double r = 0.05;
    double sigma = 0.2;
    int N = 252;
    int M = 10000;
    std::string option_type = "call";
    double option_price = price_option(S0, K, T, r, sigma, N, M, option_type);
    std::cout << "Option Price: " << option_price << std::endl;
    return 0;
}