#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double monte_carlo_pricing(double S0, double K, double T, double r, double sigma, int N) {
    double dt = T / N;
    double *S = (double *)malloc((N + 1) * sizeof(double));
    S[0] = S0;
    for (int t = 1; t <= N; t++) {
        S[t] = S[t - 1] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * ((double)rand() / RAND_MAX * 2 - 1));
    }
    double result = exp(-r * T) * (S[N] - K > 0 ? S[N] - K : 0);
    free(S);
    return result;
}

int main() {
    while (1) {
        double result = monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 252);
        printf("%f\n", result);
    }
    return 0;
}