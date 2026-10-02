#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double run_model(double S, double K, double T, double r, double sigma, int N, int M) {
    double dt = T / N;
    double **ST = (double **)malloc(M * sizeof(double *));
    for (int i = 0; i < M; i++) {
        ST[i] = (double *)malloc((N + 1) * sizeof(double));
        ST[i][0] = S;
    }

    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            ST[j][i + 1] = ST[j][i] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * (double)rand() / RAND_MAX);
        }
    }

    for (int j = 0; j < M; j++) {
        for (int i = 1; i < N + 1; i++) {
            ST[j][i] += ST[j][i - 1];
        }
    }

    double payoff_sum = 0;
    for (int i = 0; i < M; i++) {
        double payoff = ST[i][N] - K;
        if (payoff > 0) {
            payoff_sum += payoff;
        }
    }

    double option_price = exp(-r * T) * (payoff_sum / M);

    for (int i = 0; i < M; i++) {
        free(ST[i]);
    }
    free(ST);

    return option_price;
}

int main() {
    double result = run_model(100, 100, 1, 0.05, 0.2, 252, 10000);
    printf("Option Price: %f\n", result);
    return 0;
}