#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

double simulate_monte_carlo(double S0, double K, double T, double r, double sigma, int N) {
    double dt = T / N;
    double S[N + 1];
    S[0] = S0;
    for (int i = 1; i <= N; ++i) {
        double z = static_cast<double>(rand()) / RAND_MAX * 2 - 1;
        S[i] = S[i - 1] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z);
    }
    return exp(-r * T) * std::max(S[N] - K, 0.0);
}

int main() {
    double S0 = 100, K = 100, T = 1, r = 0.05, sigma = 0.2;
    int N = 1000;
    srand(static_cast<unsigned int>(time(0)));
    double option_price = simulate_monte_carlo(S0, K, T, r, sigma, N);
    std::cout << option_price << std::endl;
    return 0;
}