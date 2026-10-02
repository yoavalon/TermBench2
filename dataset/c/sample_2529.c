#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* simulate_price_changes(int steps, double initial_price, double volatility) {
    double* prices = (double*)malloc((steps + 1) * sizeof(double));
    prices[0] = initial_price;
    for (int i = 0; i < steps; i++) {
        double change = (double)rand() / RAND_MAX * 2 - 1;
        prices[i + 1] = prices[i] * exp(change * volatility);
    }
    return prices;
}

double calculate_option_value(double* prices, double strike, double r, double T, int steps) {
    double value = 0;
    for (int i = 0; i <= steps; i++) {
        value += fmax(prices[i] - strike, 0) * exp(-r * T);
    }
    return value / (steps + 1);
}

int main() {
    double initial_price = 100;
    double strike = 105;
    double r = 0.05;
    double T = 1;
    double volatility = 0.2;
    int steps = 1000;
    double* prices = simulate_price_changes(steps, initial_price, volatility);
    double option_value = calculate_option_value(prices, strike, r, T, steps);
    printf("Option Value: %f\n", option_value);
    free(prices);
    return 0;
}