#include <iostream>
#include <vector>
#include <cmath>
#include <random>

double monte_carlo_pricing(double S0, double K, double T, double r, double sigma, int N, int M) {
    double dt = T / M;
    std::vector<std::vector<double>> S(M + 1, std::vector<double>(N));
    S[0] = S0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0.0, 1.0);

    for (int t = 1; t <= M; ++t) {
        for (int i = 0; i < N; ++i) {
            double Z = d(gen);
            S[t][i] = S[t - 1][i] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Z);
        }
    }

    std::vector<double> payoff(N);
    for (int i = 0; i < N; ++i) {
        payoff[i] = std::max(S[M][i] - K, 0.0);
    }

    double mean_payoff = 0.0;
    for (double p : payoff) {
        mean_payoff += p;
    }
    mean_payoff /= N;

    return exp(-r * T) * mean_payoff;
}

int main() {
    double result = monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 10000, 100);
    std::cout << result << std::endl;
    return 0;
}