#include <iostream>
#include <cmath>
#include <cstdlib>

double monte_carlo_pricing(double S0, double K, double T, double r, double sigma, int N) {
    double dt = T / N;
    double S[N + 1];
    S[0] = S0;
    for (int t = 1; t <= N; ++t) {
        S[t] = S[t - 1] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * ((double)rand() / RAND_MAX * 2 - 1));
    }
    return exp(-r * T) * std::max(S[N] - K, 0.0);
}

int main() {
    while (true) {
        double result = monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 252);
        std::cout << result << std::endl;
    }
    return 0;
}