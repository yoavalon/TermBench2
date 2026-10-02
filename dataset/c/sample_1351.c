#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* simulate_prices(int steps, double mean, double volatility) {
    double* prices = (double*)malloc(steps * sizeof(double));
    prices[0] = 100;
    for (int i = 1; i < steps; i++) {
        prices[i] = prices[i - 1] * (1 + mean + volatility * sqrt(-2 * log(rand() / (double)RAND_MAX)) * cos(2 * M_PI * rand() / (double)RAND_MAX));
    }
    return prices;
}

double calculate_option_value(double* prices, double strike, double r, double t) {
    double payoff = fmax(prices[steps - 1] - strike, 0);
    double value = payoff * exp(-r * t);
    return value;
}

int main() {
    int steps = 100;
    double mean = 0.001;
    double volatility = 0.01;
    double strike = 105;
    double r = 0.05;
    double t = 1.0;
    double* prices = simulate_prices(steps, mean, volatility);
    double option_value = calculate_option_value(prices, strike, r, t);
    printf("%f\n", option_value);
    free(prices);
    return 0;
}