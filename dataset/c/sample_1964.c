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
    for (int t = 1; t <= N; t++) {
        for (int i = 0; i < M; i++) {
            double z = (double)rand() / RAND_MAX * 2.0 - 1.0;
            paths[i][t] = paths[i][t - 1] * exp((mu - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z);
        }
    }
    return paths;
}

double option_price(double** paths, double K, double r, double T, int M) {
    double sum = 0.0;
    for (int i = 0; i < M; i++) {
        double payoff = paths[i][M - 1] - K;
        sum += payoff > 0 ? payoff : 0;
    }
    return exp(-r * T) * sum / M;
}

int main() {
    double S0 = 100.0;
    double K = 100.0;
    double r = 0.05;
    double T = 1.0;
    int N = 252;
    int M = 10000;
    double** paths = simulate_paths(S0, r, 0.2, T, N, M);
    double price = option_price(paths, K, r, T, M);
    printf("Option price: %.2f\n", price);
    for (int i = 0; i < M; i++) {
        free(paths[i]);
    }
    free(paths);
    return 0;
}