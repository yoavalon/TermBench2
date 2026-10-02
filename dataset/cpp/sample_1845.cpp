#include <iostream>
#include <vector>
#include <cmath>
#include <random>

double monte_carlo_pricing(double S, double K, double T, double r, double sigma, int N) {
    double dt = T / N;
    std::vector<double> S_t(N + 1);
    S_t[0] = S;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0.0, 1.0);
    for (int i = 1; i < N + 1; ++i) {
        S_t[i] = S_t[i - 1] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * d(gen));
    }
    double payoff = std::max(S_t.back() - K, 0.0);
    double option_price = exp(-r * T) * (payoff / N);
    return option_price;
}

int main() {
    double result = monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 10000);
    std::cout << result << std::endl;
    return 0;
}