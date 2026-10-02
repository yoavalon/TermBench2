#include <iostream>
#include <vector>
#include <cmath>
#include <random>

double simulate_paths(double S0, double T, double r, double sigma, int N, int M, std::vector<std::vector<double>>& paths) {
    double dt = T / N;
    paths.resize(M, std::vector<double>(N + 1, 0.0));
    for (int i = 0; i < M; ++i) {
        paths[i][0] = S0;
    }
    for (int t = 1; t <= N; ++t) {
        std::vector<double> z(M);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(0.0, 1.0);
        for (int i = 0; i < M; ++i) {
            z[i] = d(gen);
        }
        for (int i = 0; i < M; ++i) {
            paths[i][t] = paths[i][t - 1] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z[i]);
        }
    }
    return paths[0][0]; // Return the first element as a placeholder
}

double price_option(const std::vector<std::vector<double>>& paths, double strike, const std::string& option_type) {
    double payoff = 0.0;
    if (option_type == "call") {
        for (const auto& path : paths) {
            payoff += std::max(path.back() - strike, 0.0);
        }
    } else if (option_type == "put") {
        for (const auto& path : paths) {
            payoff += std::max(strike - path.back(), 0.0);
        }
    }
    return exp(-r * T) * (payoff / paths.size());
}

int main() {
    double S0 = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 252;
    int M = 10000;
    double strike = 100;
    std::string option_type = "call";

    while (true) {
        std::vector<std::vector<double>> paths;
        simulate_paths(S0, T, r, sigma, N, M, paths);
        double price = price_option(paths, strike, option_type);
        std::cout << price << std::endl;
    }

    return 0;
}