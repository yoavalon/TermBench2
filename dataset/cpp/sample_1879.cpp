#include <iostream>
#include <vector>
#include <cmath>
#include <random>

double monte_carlo_pricing(const std::vector<double>& S, double K, double T, double r, double sigma, int N) {
    double dt = T / N;
    double mu = r - 0.5 * sigma * sigma;
    std::vector<std::vector<double>> S_paths(N + 1, std::vector<double>(S.size()));
    S_paths[0] = S;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0.0, 1.0);

    for (int t = 1; t <= N; ++t) {
        for (size_t i = 0; i < S.size(); ++i) {
            double z = d(gen);
            S_paths[t][i] = S_paths[t - 1][i] * exp(mu * dt + sigma * sqrt(dt) * z);
        }
    }

    std::vector<double> payoff(S.size());
    for (size_t i = 0; i < S.size(); ++i) {
        payoff[i] = std::max(S_paths[N][i] - K, 0.0);
    }

    double mean_payoff = 0.0;
    for (double p : payoff) {
        mean_payoff += p;
    }
    mean_payoff /= payoff.size();

    return exp(-r * T) * mean_payoff;
}

int main() {
    std::vector<double> S = {100.0};
    double K = 100.0;
    double T = 1.0;
    double r = 0.05;
    double sigma = 0.2;
    int N = 100000;

    double result = monte_carlo_pricing(S, K, T, r, sigma, N);
    std::cout << result << std::endl;

    return 0;
}