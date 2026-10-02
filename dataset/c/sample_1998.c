c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double** simulate_paths(double S0, double T, double r, double sigma, int N, int M) {
    double dt = T / M;
    double** paths = (double**)malloc(N * sizeof(double*));
    for (int i = 0; i < N; i++) {
        paths[i] = (double*)malloc(M * sizeof(double));
        paths[i][0] = S0;
    }
    for (int t = 1; t < M; t++) {
        for (int i = 0; i < N; i++) {
            double z = ((double)rand() / RAND_MAX) * 2 - 1;
            paths[i][t] = paths[i][t - 1] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z);
        }
    }
    return paths;
}

double option_pricing(double** paths, double K, double T, double r, int M) {
    double sum = 0;
    for (int i = 0; i < M; i++) {
        double payoff = fmax(paths[i][M - 1] - K, 0);
        sum += payoff;
    }
    double price = exp(-r * T) * (sum / M);
    return price;
}

int main() {
    double S0 = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 10000;
    int M = 100;
    double** paths = simulate_paths(S0, T, r, sigma, N, M);
    double option_price = option_pricing(paths, K, T, r, M);
    printf("%f\n", option_price);
    for (int i = 0; i < N; i++) {
        free(paths[i]);
    }
    free(paths);
    return 0;
}