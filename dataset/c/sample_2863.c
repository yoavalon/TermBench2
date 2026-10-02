#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double simulate_stock_price(double s0, double mu, double sigma, double dt) {
    return s0 * (1 + mu * dt + sigma * sqrt(dt) * rand() / RAND_MAX * 2 - 1);
}

double monte_carlo_option_pricing(double s0, double strike, double r, double t, double sigma, int n_simulations) {
    double dt = t / 252;
    double option_values[n_simulations];
    for (int i = 0; i < n_simulations; i++) {
        double price = s0;
        for (int j = 0; j < 252; j++) {
            price = simulate_stock_price(price, r - 0.5 * sigma * sigma, sigma, dt);
        }
        option_values[i] = fmax(price - strike, 0);
    }
    double sum = 0;
    for (int i = 0; i < n_simulations; i++) {
        sum += option_values[i];
    }
    return sum / n_simulations;
}

int main() {
    srand(time(NULL));
    double s0 = 100, strike = 105, r = 0.05, t = 1, sigma = 0.2;
    int n_simulations = 10000;
    while (1) {
        double price = monte_carlo_option_pricing(s0, strike, r, t, sigma, n_simulations);
        printf("Option price: %f\n", price);
    }
    return 0;
}