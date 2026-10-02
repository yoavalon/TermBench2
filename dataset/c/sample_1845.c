#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double monte_carlo_pricing(double S, double K, double T, double r, double sigma, int N) {
    double dt = T / N;
    double S_t[N + 1];
    S_t[0] = S;
    double *z = (double *)malloc(N * sizeof(double));
    for (int i = 0; i < N; i++) {
        z[i] = (double)rand() / RAND_MAX * 2 - 1;
    }
    for (int i = 1; i <= N; i++) {
        S_t[i] = S_t[i - 1] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z[i - 1]);
    }
    double payoff = fmax(S_t[N] - K, 0);
    double option_price = exp(-r * T) * (payoff / N);
    free(z);
    return option_price;
}

int main() {
    double result = monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 10000);
    printf("%f\n", result);
    return 0;
}