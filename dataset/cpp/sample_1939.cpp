#include <iostream>
#include <vector>
#include <cmath>
#include <random>

std::vector<std::vector<double>> simulate_stock_prices(double S0, double mu, double sigma, double T, int N, int M) {
    double dt = T / N;
    std::vector<std::vector<double>> S(M, std::vector<double>(N + 1));
    for (int i = 0; i < M; ++i) {
        S[i][0] = S0;
    }
    for (int t = 1; t <= N; ++t) {
        std::vector<double> Z(M);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(0, 1);
        for (int i = 0; i < M; ++i) {
            Z[i] = d(gen);
        }
        for (int i = 0; i < M; ++i) {
            S[i][t] = S[i][t - 1] * exp((mu - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Z[i]);
        }
    }
    return S;
}

double price_european_option(const std::vector<std::vector<double>>& S, double K, double T, double r) {
    int M = S.size();
    std::vector<double> payoff(M);
    for (int i = 0; i < M; ++i) {
        payoff[i] = std::max(S[i][S[i].size() - 1] - K, 0.0);
    }
    double mean_payoff = 0.0;
    for (int i = 0; i < M; ++i) {
        mean_payoff += payoff[i];
    }
    mean_payoff /= M;
    return exp(-r * T) * mean_payoff;
}

int main() {
    double S0 = 100.0;
    double K = 100.0;
    double T = 1.0;
    double r = 0.05;
    double sigma = 0.2;
    int N = 100;
    int M = 100000;
    std::vector<std::vector<double>> S = simulate_stock_prices(S0, r, sigma, T, N, M);
    double option_price = price_european_option(S, K, T, r);
    std::cout << option_price << std::endl;
    return 0;
}