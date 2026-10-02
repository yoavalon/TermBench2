#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double** simulate_paths(double S0, double T, double r, double sigma, int N, int M) {
    double dt = T / N;
    double** paths = (double**)malloc((N + 1) * sizeof(double*));
    for (int i = 0; i < N + 1; i++) {
        paths[i] = (double*)malloc(M * sizeof(double));
        for (int j = 0; j < M; j++) {
            paths[i][j] = 0.0;
        }
    }
    for (int j = 0; j < M; j++) {
        paths[0][j] = S0;
    }
    for (int t = 1; t < N + 1; t++) {
        for (int j = 0; j < M; j++) {
            double Z = (double)rand() / RAND_MAX * 2.0 - 1.0;
            paths[t][j] = paths[t - 1][j] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Z);
        }
    }
    return paths;
}

double option_price(double** paths, double K, double r, double T, int N, int M) {
    double sum = 0.0;
    for (int j = 0; j < M; j++) {
        sum += exp(-r * T) * fmax(paths[N][j] - K, 0.0);
    }
    return sum / M;
}

int main() {
    double S0 = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 100;
    int M = 10000;
    double** paths = simulate_paths(S0, T, r, sigma, N, M);
    double price = option_price(paths, K, r, T, N, M);
    printf("%f\n", price);
    for (int i = 0; i < N + 1; i++) {
        free(paths[i]);
    }
    free(paths);
    return 0;
}