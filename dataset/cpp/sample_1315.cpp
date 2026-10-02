#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

std::vector<std::vector<double>> generate_paths(double S0, double T, double r, double sigma, int N, int M) {
    double dt = T / N;
    std::vector<std::vector<double>> paths(N + 1, std::vector<double>(M, 0.0));
    for (int i = 0; i < M; ++i) {
        paths[0][i] = S0;
    }
    for (int t = 1; t <= N; ++t) {
        for (int i = 0; i < M; ++i) {
            double z = static_cast<double>(rand()) / RAND_MAX * 2.0 - 1.0;
            paths[t][i] = paths[t - 1][i] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z);
        }
    }
    return paths;
}

double option_price(const std::vector<std::vector<double>>& paths, double K, double r, double T) {
    int M = paths[0].size();
    double payoff = 0.0;
    for (int i = 0; i < M; ++i) {
        payoff += std::max(paths.back()[i] - K, 0.0);
    }
    return exp(-r * T) * (payoff / M);
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    double S0 = 100;
    double K = 100;
    double r = 0.05;
    double sigma = 0.2;
    double T = 1;
    int N = 252;
    int M = 10000;
    std::vector<std::vector<double>> paths = generate_paths(S0, T, r, sigma, N, M);
    double price = option_price(paths, K, r, T);
    std::cout << price << std::endl;
    return 0;
}