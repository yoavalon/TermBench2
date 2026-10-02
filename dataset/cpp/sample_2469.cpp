#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

double monte_carlo_option_pricing(double S, double K, double T, double r, double sigma, int N) {
    double dt = T / N;
    double St = S;
    double option_price = 0;
    for (int i = 0; i < N; ++i) {
        St *= 1 + r * dt + sigma * randn() * sqrt(dt);
    }
    option_price = std::max(0.0, St - K);
    return option_price;
}

double randn() {
    return (static_cast<double>(rand()) / RAND_MAX * 2 - 1 +
            static_cast<double>(rand()) / RAND_MAX * 2 - 1 +
            static_cast<double>(rand()) / RAND_MAX * 2 - 1) *
           sqrt(6.0 / 3.0);
}

int main() {
    double S = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 252;
    std::srand(static_cast<unsigned int>(std::time(0)));
    std::cout << monte_carlo_option_pricing(S, K, T, r, sigma, N) << std::endl;
    return 0;
}