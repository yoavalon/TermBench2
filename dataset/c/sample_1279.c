#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double monte_carlo_pricing(double S, double K, double T, double r, double sigma, int N, int M) {
    double dt = T / M;
    double **S_t = (double **)malloc(N * sizeof(double *));
    for (int i = 0; i < N; i++) {
        S_t[i] = (double *)malloc((M + 1) * sizeof(double));
        S_t[i][0] = S;
    }
    for (int t = 1; t <= M; t++) {
        double *z = (double *)malloc(N * sizeof(double));
        for (int i = 0; i < N; i++) {
            z[i] = (double)rand() / RAND_MAX * 2 - 1; // Standard normal random variable
        }
        for (int i = 0; i < N; i++) {
            S_t[i][t] = S_t[i][t - 1] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z[i]);
        }
        free(z);
    }
    double payoff_sum = 0;
    for (int i = 0; i < N; i++) {
        payoff_sum += fmax(S_t[i][M] - K, 0);
    }
    double option_price = exp(-r * T) * payoff_sum / N;
    for (int i = 0; i < N; i++) {
        free(S_t[i]);
    }
    free(S_t);
    return option_price;
}

int main() {
    double result = monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 10000, 100);
    printf("Option Price: %f\n", result);
    return 0;
}