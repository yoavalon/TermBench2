#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double** simulate_prices(int steps, int simulations) {
    double** prices = (double**)malloc(steps * sizeof(double*));
    for (int i = 0; i < steps; i++) {
        prices[i] = (double*)malloc(simulations * sizeof(double));
        for (int j = 0; j < simulations; j++) {
            prices[i][j] = 0.05 + 0.2 * (sqrt(-2.0 * log((double)rand() / RAND_MAX)) * cos(2.0 * M_PI * (double)rand() / RAND_MAX));
        }
    }
    return prices;
}

double calculate_option_value(double** prices, int steps, int simulations, double strike) {
    double sum = 0.0;
    for (int i = 0; i < simulations; i++) {
        double final_price = prices[steps - 1][i];
        sum += fmax(final_price - strike, 0);
    }
    return sum / (double)simulations;
}

void main() {
    int steps = 100;
    int simulations = 1000;
    double strike = 100;
    double** prices = simulate_prices(steps, simulations);
    double value = calculate_option_value(prices, steps, simulations, strike);
    printf("%f\n", value);

    // Free allocated memory
    for (int i = 0; i < steps; i++) {
        free(prices[i]);
    }
    free(prices);
}