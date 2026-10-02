#include <iostream>
#include <vector>
#include <cmath>
#include <random>

std::vector<std::vector<double>> generate_paths(double S0, double T, double r, double sigma, int N, int M) {
    double dt = T / N;
    std::vector<std::vector<double>> paths(N + 1, std::vector<double>(M, 0.0));
    paths[0] = std::vector<double>(M, S0);
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

std::vector<double> calculate_payoffs(const std::vector<std::vector<double>>& paths, double K, const std::string& option_type) {
    int N = paths.size() - 1;
    std::vector<double> payoffs(paths[N].size(), 0.0);
    if (option_type == "call") {
        for (size_t i = 0; i < paths[N].size(); ++i) {
            payoffs[i] = std::max(paths[N][i] - K, 0.0);
        }
    } else if (option_type == "put") {
        for (size_t i = 0; i < paths[N].size(); ++i) {
            payoffs[i] = std::max(K - paths[N][i], 0.0);
        }
    }
    return payoffs;
}

double price_option(double S0, double K, double T, double r, double sigma, int N, int M, const std::string& option_type) {
    std::vector<std::vector<double>> paths = generate_paths(S0, T, r, sigma, N, M);
    std::vector<double> payoffs = calculate_payoffs(paths, K, option_type);
    double mean_payoff = 0.0;
    for (double payoff : payoffs) {
        mean_payoff += payoff;
    }
    mean_payoff /= payoffs.size();
    return std::exp(-r * T) * mean_payoff;
}

int main() {
    double S0 = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 100;
    int M = 10000;
    std::string option_type = "call";
    double option_price = price_option(S0, K, T, r, sigma, N, M, option_type);
    std::cout << "Option price: " << std::fixed << std::setprecision(2) << option_price << std::endl;
    return 0;
}