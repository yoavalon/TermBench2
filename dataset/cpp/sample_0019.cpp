#include <iostream>
#include <cmath>
#include <vector>
#include <random>

double calculate_option_price(double S, double K, double r, double T, double sigma, int N) {
    double dt = T / N;
    double dS = S * sigma * std::sqrt(dt);
    std::vector<double> paths(N);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);

    paths[0] = S;
    for (int i = 1; i < N; ++i) {
        paths[i] = paths[i - 1] * std::exp((r - 0.5 * sigma * sigma) * dt + dS * d(gen));
    }

    double payoff = std::max(paths.back() - K, 0.0);
    return std::exp(-r * T) * payoff;
}

int main() {
    double result = calculate_option_price(100, 100, 0.05, 1, 0.2, 1000);
    std::cout << result << std::endl;
    return 0;
}