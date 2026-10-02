#include <iostream>
#include <cmath>
#include <random>
#include <vector>

double simulate_option_price(double S0, double K, double T, double r, double sigma, int steps, int trials) {
    double dt = T / steps;
    std::vector<std::vector<double>> dW(steps, std::vector<double>(trials));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0.0, std::sqrt(dt));

    for (int i = 0; i < steps; ++i) {
        for (int j = 0; j < trials; ++j) {
            dW[i][j] = d(gen);
        }
    }

    std::vector<double> S(trials, S0);
    for (int i = 0; i < steps; ++i) {
        for (int j = 0; j < trials; ++j) {
            S[j] *= std::exp((r - 0.5 * sigma * sigma) * dt + sigma * dW[i][j]);
        }
    }

    double payoff = 0.0;
    for (int j = 0; j < trials; ++j) {
        payoff += std::max(S[j] - K, 0.0);
    }
    payoff /= trials;

    return std::exp(-r * T) * payoff;
}

int main() {
    double result = simulate_option_price(100, 100, 1, 0.05, 0.2, 100, 1000);
    std::cout << result << std::endl;
    return 0;
}