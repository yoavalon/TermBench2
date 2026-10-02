#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double* simulate_prices(int steps, int simulations) {
    double drift = 0.05;
    double volatility = 0.2;
    double initial_price = 100;
    double dt = 1.0 / steps;
    double* paths = (double*)malloc(simulations * steps * sizeof(double));
    for (int i = 0; i < simulations; i++) {
        paths[i * steps] = initial_price;
    }
    for (int t = 1; t < steps; t++) {
        for (int i = 0; i < simulations; i++) {
            double z = ((double)rand() / RAND_MAX) * 2 - 1;
            paths[i * steps + t] = paths[i * steps + t - 1] * exp((drift - 0.5 * volatility * volatility) * dt + volatility * sqrt(dt) * z);
        }
    }
    return paths;
}

double* option_pricing(double* prices, int simulations, int strike, char* option_type) {
    double* option_values = (double*)malloc(simulations * sizeof(double));
    for (int i = 0; i < simulations; i++) {
        if (strcmp(option_type, "call") == 0) {
            option_values[i] = fmax(prices[i] - strike, 0);
        } else if (strcmp(option_type, "put") == 0) {
            option_values[i] = fmax(strike - prices[i], 0);
        } else {
            return NULL;
        }
    }
    return option_values;
}

int main() {
    srand(time(0));
    int steps = 252;
    int simulations = 10000;
    int strike = 105;
    double* prices = simulate_prices(steps, simulations);
    double* option_values = option_pricing(&prices[simulations * (steps - 1)], simulations, strike, "call");
    double mean = 0;
    for (int i = 0; i < simulations; i++) {
        mean += option_values[i];
    }
    mean /= simulations;
    printf("%f\n", mean);
    free(prices);
    free(option_values);
    return 0;
}