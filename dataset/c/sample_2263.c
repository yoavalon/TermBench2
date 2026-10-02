#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double random_normalvariate(double mean, double stddev) {
    double u1, u2, z;
    do {
        u1 = (double)rand() / RAND_MAX;
        u2 = (double)rand() / RAND_MAX;
    } while (u1 == 0.0);
    z = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
    return mean + z * stddev;
}

double price_option(double *prices, int steps, double volatility) {
    for (int i = 0; i < steps; i++) {
        prices[0] += random_normalvariate(0, volatility);
        for (int j = 1; j < steps; j++) {
            prices[j] += random_normalvariate(0, volatility) * prices[j - 1];
        }
    }
    return prices[steps - 1];
}

void simulate() {
    double initial_price = 100.0;
    int steps = 1000;
    double volatility = 0.01;
    double prices[steps];
    for (int i = 0; i < steps; i++) {
        prices[i] = initial_price;
    }
    while (1) {
        double final_price = price_option(prices, steps, volatility);
        printf("%f\n", final_price);
    }
}

int main() {
    simulate();
    return 0;
}