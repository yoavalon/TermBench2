#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double** generate_paths(double S0, double r, double sigma, double T, int M, int N) {
    double dt = T / M;
    double** paths = (double**)malloc((M + 1) * sizeof(double*));
    for (int i = 0; i <= M; i++) {
        paths[i] = (double*)malloc(N * sizeof(double));
    }
    for (int i = 0; i < N; i++) {
        paths[0][i] = S0;
    }
    for (int t = 1; t <= M; t++) {
        for (int i = 0; i < N; i++) {
            double z = (double)rand() / RAND_MAX * 2 - 1;
            paths[t][i] = paths[t - 1][i] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z);
        }
    }
    return paths;
}

double price_option(double** paths, double strike, double T, double r, int M, int N) {
    double payoff = 0;
    for (int i = 0; i < N; i++) {
        payoff += fmax(paths[M][i] - strike, 0);
    }
    return exp(-r * T) * payoff / N;
}

int main() {
    double S0 = 100, r = 0.05, sigma = 0.2, T = 1;
    int M = 100, N = 1000;
    double K = 100;
    double** paths = generate_paths(S0, r, sigma, T, M, N);
    double option_price = price_option(paths, K, T, r, M, N);
    printf("Option Price: %f\n", option_price);
    for (int i = 0; i <= M; i++) {
        free(paths[i]);
    }
    free(paths);
    return 0;
}