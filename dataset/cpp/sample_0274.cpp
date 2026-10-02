#include <iostream>
#include <vector>
#include <cmath>
#include <random>

std::vector<std::vector<double>> generate_paths(double S0, double mu, double sigma, double T, int N, int M) {
    double dt = T / N;
    std::vector<std::vector<double>> paths(M, std::vector<double>(1, S0));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < M; ++j) {
            double z = d(gen);
            double S = paths[j].back() * (1 + mu * dt + sigma * z * std::sqrt(dt));
            paths[j].push_back(S);
        }
    }
    return paths;
}

std::vector<double> payoff(const std::vector<std::vector<double>>& paths, double K, double T) {
    std::vector<double> terminal_values(paths.size());
    for (size_t i = 0; i < paths.size(); ++i) {
        terminal_values[i] = paths[i].back();
    }
    std::vector<double> payoffs(terminal_values.size());
    for (size_t i = 0; i < terminal_values.size(); ++i) {
        payoffs[i] = std::max(terminal_values[i] - K, 0.0);
    }
    return payoffs;
}

std::vector<double> discount(const std::vector<double>& payoffs, double r, double T) {
    std::vector<double> discounted_payoffs(payoffs.size());
    for (size_t i = 0; i < payoffs.size(); ++i) {
        discounted_payoffs[i] = payoffs[i] / std::pow(1 + r, T);
    }
    return discounted_payoffs;
}

int main() {
    double S0 = 100;
    double K = 100;
    double r = 0.05;
    double T = 1;
    int N = 252;
    int M = 10000;
    double mu = 0.05;
    double sigma = 0.2;
    auto paths = generate_paths(S0, mu, sigma, T, N, M);
    auto payoffs = payoff(paths, K, T);
    auto discounted_payoffs = discount(payoffs, r, T);
    double option_price = 0.0;
    for (double p : discounted_payoffs) {
        option_price += p;
    }
    option_price /= M;
    std::cout << "Option Price: " << option_price << std::endl;
    return 0;
}