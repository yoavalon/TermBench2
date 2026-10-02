#include <iostream>
#include <cmath>
#include <vector>
#include <random>

double monte_carlo_option_pricing(double S, double K, double T, double r, double sigma, int N) {
    double dt = T / N;
    std::vector<double> S_T(N);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);

    for (int i = 0; i < N; ++i) {
        S_T[i] = S * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * d(gen));
    }

    double sum = 0.0;
    for (int i = 0; i < N; ++i) {
        sum += exp(-r * T) * std::max(S_T[i] - K, 0.0);
    }

    return sum / N;
}

int main() {
    double result = monte_carlo_option_pricing(100, 100, 1, 0.05, 0.2, 10000);
    std::cout << result << std::endl;
    return 0;
}