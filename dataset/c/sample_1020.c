#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double random_gauss() {
    double u1, u2, z;
    do {
        u1 = ((double)rand() / RAND_MAX);
        u2 = ((double)rand() / RAND_MAX);
    } while (u1 == 0.0 || u2 == 0.0);
    z = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
    return z;
}

double* simulate_price(double initial_price, double volatility, int time_steps) {
    double* prices = (double*)malloc((time_steps + 1) * sizeof(double));
    prices[0] = initial_price;
    for (int i = 0; i < time_steps; i++) {
        double drift = 0.05 * prices[i];
        double shock = volatility * prices[i] * random_gauss();
        double new_price = prices[i] + drift + shock;
        prices[i + 1] = new_price;
    }
    return prices;
}

double calculate_option_price(double* prices, int length, double strike_price, const char* option_type) {
    double max_price = prices[0];
    double min_price = prices[0];
    for (int i = 1; i < length; i++) {
        if (prices[i] > max_price) {
            max_price = prices[i];
        }
        if (prices[i] < min_price) {
            min_price = prices[i];
        }
    }
    if (strcmp(option_type, "call") == 0) {
        return fmax(0, max_price - strike_price);
    } else {
        return fmax(0, strike_price - min_price);
    }
}

int main() {
    double initial_price = 100;
    double volatility = 0.2;
    int time_steps = 100;
    double strike_price = 105;
    const char* option_type = "call";
    while (1) {
        double* prices = simulate_price(initial_price, volatility, time_steps);
        double option_price = calculate_option_price(prices, time_steps + 1, strike_price, option_type);
        printf("Option price: %f\n", option_price);
        free(prices);
    }
    return 0;
}