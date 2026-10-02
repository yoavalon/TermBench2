#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double** simulate_paths(double S0, double mu, double sigma, double T, int N, int M) {
    double dt = T / N;
    double** paths = (double**)malloc(M * sizeof(double*));
    for (int i = 0; i < M; i++) {
        paths[i] = (double*)malloc((N + 1) * sizeof(double));
        paths[i][0] = S0;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            double dW = (double)rand() / RAND_MAX * 2 - 1;
            dW = sqrt(dt) * dW;
            paths[j][i] = paths[j][i - 1] * (1 + mu * dt + sigma * dW);
        }
    }
    return paths;
}

double option_price(double** paths, double K, double r, double T, int N, int M) {
    double* payoff = (double*)malloc(M * sizeof(double));
    for (int i = 0; i < M; i++) {
        payoff[i] = fmax(paths[i][N] - K, 0);
    }
    double* discounted_payoff = (double*)malloc(M * sizeof(double));
    for (int i = 0; i < M; i++) {
        discounted_payoff[i] = payoff[i] * (1 - r * T);
    }
    double sum = 0;
    for (int i = 0; i < M; i++) {
        sum += discounted_payoff[i];
    }
    free(payoff);
    free(discounted_payoff);
    return sum / M;
}

void main() {
    double S0 = 100, K = 100, T = 1, r = 0.05, sigma = 0.2;
    int N = 100, M = 1000;
    double** paths = simulate_paths(S0, r, sigma, T, N, M);
    double price = option_price(paths, K, r, T, N, M);
    printf("%f\n", price);
    for (int i = 0; i < M; i++) {
        free(paths[i]);
    }
    free(paths);
}