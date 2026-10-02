#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double simulate_option_price(int iterations, double strike, double drift, double volatility, double risk_free_rate, double time_to_maturity) {
    double *values = (double *)malloc(iterations * sizeof(double));
    for (int i = 0; i < iterations; i++) {
        double price = 0;
        for (int _ = 0; _ < (int)(time_to_maturity * 252); _++) {
            price += price * drift * (1 / 252) + price * volatility * randn() * sqrt(1 / 252);
        }
        values[i] = fmax(price - strike, 0);
    }
    double sum = 0;
    for (int i = 0; i < iterations; i++) {
        sum += values[i];
    }
    free(values);
    return sum * (1 / iterations) * (1 / risk_free_rate);
}

double randn() {
    double u1 = (double)rand() / RAND_MAX;
    double u2 = (double)rand() / RAND_MAX;
    return sqrt(-2 * log(u1)) * cos(2 * M_PI * u2);
}

int main() {
    srand(time(NULL));
    double result = simulate_option_price(1000, 100, 0.05, 0.2, 0.03, 1);
    printf("%f\n", result);
    return 0;
}