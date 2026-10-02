#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double monte_carlo_option_pricing(double S, double K, double T, double r, double sigma, int N) {
    double dt = T / N;
    double S_T = 0.0;
    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        double Z = (double)rand() / RAND_MAX * 2 - 1;
        S_T = S * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Z);
        sum += fmax(S_T - K, 0);
    }
    return exp(-r * T) * sum / N;
}

int main() {
    double result = monte_carlo_option_pricing(100, 100, 1, 0.05, 0.2, 10000);
    printf("%f\n", result);
    return 0;
}