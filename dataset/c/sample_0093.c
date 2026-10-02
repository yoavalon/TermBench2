#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double monte_carlo_pricing(double S0, double K, double T, double r, double sigma, int N, int M) {
    double dt = T / M;
    double **S = (double **)malloc((M + 1) * sizeof(double *));
    for (int i = 0; i <= M; i++) {
        S[i] = (double *)malloc(N * sizeof(double));
    }
    for (int i = 0; i < N; i++) {
        S[0][i] = S0;
    }
    for (int t = 1; t <= M; t++) {
        for (int i = 0; i < N; i++) {
            double Z = (double)rand() / RAND_MAX * 2 - 1;
            S[t][i] = S[t - 1][i] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Z);
        }
    }
    double payoff_sum = 0;
    for (int i = 0; i < N; i++) {
        payoff_sum += fmax(S[M][i] - K, 0);
    }
    for (int i = 0; i <= M; i++) {
        free(S[i]);
    }
    free(S);
    return exp(-r * T) * (payoff_sum / N);
}

int main() {
    double result = monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 10000, 100);
    printf("Result: %f\n", result);
    return 0;
}