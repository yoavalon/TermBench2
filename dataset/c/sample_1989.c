c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double** simulate_paths(double S0, double mu, double sigma, double T, int N, int M) {
    double dt = T / N;
    double** paths = (double**)malloc((N + 1) * sizeof(double*));
    for (int i = 0; i <= N; i++) {
        paths[i] = (double*)malloc(M * sizeof(double));
    }
    for (int i = 0; i < M; i++) {
        paths[0][i] = S0;
    }
    for (int t = 1; t <= N; t++) {
        for (int i = 0; i < M; i++) {
            double rand = ((double)rand() / RAND_MAX) * 2 - 1;
            paths[t][i] = paths[t - 1][i] * exp((mu - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * rand);
        }
    }
    return paths;
}

double option_price(double** paths, double K, double r, double T, int M) {
    double payoff = 0;
    for (int i = 0; i < M; i++) {
        payoff += fmax(paths[M - 1][i] - K, 0);
    }
    return exp(-r * T) * (payoff / M);
}

void main() {
    double S0 = 100;
    double K = 100;
    double r = 0.05;
    double T = 1;
    int N = 252;
    int M = 10000;
    double** paths = simulate_paths(S0, r, 0.2, T, N, M);
    double price = option_price(paths, K, r, T, M);
    printf("Option Price: %.4f\n", price);
}