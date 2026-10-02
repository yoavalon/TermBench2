#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

double simulate_stock_price(double S0, double mu, double sigma, double T, double dt) {
    double S = S0;
    for (int i = 0; i < int(T / dt); ++i) {
        double dS = mu * S * dt + sigma * S * sqrt(dt) * ((double)rand() / RAND_MAX * 2 - 1);
        S += dS;
    }
    return S;
}

double monte_carlo_option_price(double S0, double K, double T, double r, double sigma, int N, double dt) {
    double option_price = 0;
    for (int i = 0; i < N; ++i) {
        double S_T = simulate_stock_price(S0, r, sigma, T, dt);
        option_price += std::max(S_T - K, 0.0);
    }
    return option_price * (1.0 / N) * exp(-r * T);
}

int main() {
    srand(time(0));
    double S0 = 100, K = 100, T = 1, r = 0.05, sigma = 0.2;
    int N = 100000;
    double dt = 0.01;
    double price = monte_carlo_option_price(S0, K, T, r, sigma, N, dt);
    std::cout << "Option Price: " << price << std::endl;
    return 0;
}