#include <iostream>
#include <vector>
#include <cmath>
#include <random>

double monte_carlo_option_pricing(double S0, double K, double T, double r, double sigma, int N) {
    double dt = T / N;
    std::vector<double> S(N + 1);
    S[0] = S0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0.0, 1.0);
    for (int i = 1; i <= N; ++i) {
        S[i] = S[i - 1] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * d(gen));
    }
    double payoff = std::max(S[N] - K, 0.0);
    double option_price = exp(-r * T) * payoff;
    return option_price;
}

int main() {
    double result = monte_carlo_option_pricing(100, 100, 1, 0.05, 0.2, 1000);
    std::cout << result << std::endl;
    return 0;
}