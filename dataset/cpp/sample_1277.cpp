#include <iostream>
#include <cmath>
#include <vector>
#include <random>

double run_model(double S, double K, double T, double r, double sigma, int N, int M) {
    double dt = T / N;
    std::vector<std::vector<double>> ST(M, std::vector<double>(N + 1, S));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0.0, 1.0);

    for (int j = 0; j < M; ++j) {
        for (int i = 0; i < N; ++i) {
            ST[j][i + 1] = ST[j][i] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * d(gen));
        }
    }

    for (int j = 0; j < M; ++j) {
        for (int i = 1; i < N + 1; ++i) {
            ST[j][i] += ST[j][i - 1];
        }
    }

    std::vector<double> payoff(M);
    for (int j = 0; j < M; ++j) {
        payoff[j] = std::max(ST[j][N] - K, 0.0);
    }

    double option_price = exp(-r * T);
    for (double p : payoff) {
        option_price += p;
    }
    option_price /= M;

    return option_price;
}

int main() {
    double result = run_model(100, 100, 1, 0.05, 0.2, 252, 10000);
    std::cout << result << std::endl;
    return 0;
}