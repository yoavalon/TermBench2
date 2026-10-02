#include <iostream>
#include <vector>
#include <cmath>
#include <random>

std::vector<std::vector<double>> generate_paths(double S0, double r, double sigma, double T, int N, int M) {
    std::vector<std::vector<double>> paths;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);

    for (int i = 0; i < M; ++i) {
        std::vector<double> path = {S0};
        double dt = T / N;
        for (int j = 1; j <= N; ++j) {
            double z = d(gen);
            double S = path.back() * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z);
            path.push_back(S);
        }
        paths.push_back(path);
    }
    return paths;
}

double payoff_function(double S) {
    return std::max(S - 100, 0.0);
}

double monte_carlo_pricing(const std::vector<std::vector<double>>& paths, double (*payoff_function)(double)) {
    double total_payoff = 0;
    for (const auto& path : paths) {
        total_payoff += payoff_function(path.back());
    }
    return total_payoff / paths.size() * exp(-0.05 * 1);
}

int main() {
    double S0 = 100;
    double r = 0.05;
    double sigma = 0.2;
    double T = 1;
    int N = 252;
    int M = 10000;
    auto paths = generate_paths(S0, r, sigma, T, N, M);
    double option_price = monte_carlo_pricing(paths, payoff_function);
    std::cout << "Option Price: " << option_price << std::endl;
    return 0;
}