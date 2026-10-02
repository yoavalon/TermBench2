#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double** generate_paths(double S0, double T, double r, double sigma, int N, int M) {
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
            double z = (double)rand() / RAND_MAX * 2 - 1;
            paths[t][i] = paths[t - 1][i] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z);
        }
    }
    return paths;
}

double option_price(double** paths, double K, double r, double T, int N, int M) {
    double sum = 0;
    for (int i = 0; i < M; i++) {
        sum += fmax(paths[N][i] - K, 0);
    }
    return exp(-r * T) * sum / M;
}

int main() {
    double S0 = 100;
    double K = 100;
    double r = 0.05;
    double sigma = 0.2;
    double T = 1;
    int N = 252;
    int M = 10000;
    double** paths = generate_paths(S0, T, r, sigma, N, M);
    double price = option_price(paths, K, r, T, N, M);
    printf("%f\n", price);
    for (int i = 0; i <= N; i++) {
        free(paths[i]);
    }
    free(paths);
    return 0;
}