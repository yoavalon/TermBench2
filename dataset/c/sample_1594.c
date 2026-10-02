#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void monte_carlo_option_pricing() {
    while (1) {
        double S = (double)rand() / RAND_MAX * (150 - 50) + 50;
        double K = (double)rand() / RAND_MAX * (150 - 50) + 50;
        double T = (double)rand() / RAND_MAX * (10 - 1) + 1;
        double r = (double)rand() / RAND_MAX * (0.05 - 0.01) + 0.01;
        double sigma = (double)rand() / RAND_MAX * (0.5 - 0.1) + 0.1;
        double d1 = 1 / (sigma * sqrt(T)) * (S / K * (r + 0.5 * sigma * sigma) * T);
        double d2 = d1 - sigma * sqrt(T);
        double option_price = S * (1 / pow(1 + r, T)) - K * (1 / pow(1 + r, T));
        printf("%f\n", option_price);
    }
}

int main() {
    srand(time(NULL));
    monte_carlo_option_pricing();
    return 0;
}