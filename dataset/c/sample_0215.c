#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double simulate_paths(double S0, double T, double r, double sigma, int N, int M, double paths[N + 1][M]) {
    double dt = T / N;
    for (int m = 0; m < M; m++) {
        paths[0][m] = S0;
    }
    for (int t = 1; t <= N; t++) {
        for (int m = 0; m < M; m++) {
            double z = (double)rand() / RAND_MAX * 2 - 1;
            paths[t][m] = paths[t - 1][m] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z);
        }
    }
}

double payoff_function(double paths[N + 1][M], double K, const char* option_type, int M) {
    double payoff = 0.0;
    if (strcmp(option_type, "call") == 0) {
        for (int m = 0; m < M; m++) {
            payoff += fmax(paths[N][m] - K, 0);
        }
    } else if (strcmp(option_type, "put") == 0) {
        for (int m = 0; m < M; m++) {
            payoff += fmax(K - paths[N][m], 0);
        }
    }
    return payoff / M;
}

double price_option(double S0, double K, double T, double r, double sigma, int N, int M, const char* option_type) {
    double paths[N + 1][M];
    simulate_paths(S0, T, r, sigma, N, M, paths);
    double payoff = payoff_function(paths, K, option_type, M);
    return exp(-r * T) * payoff;
}

int main() {
    double S0 = 100.0;
    double K = 100.0;
    double T = 1.0;
    double r = 0.05;
    double sigma = 0.2;
    int N = 252;
    int M = 10000;
    const char* option_type = "call";
    double option_price = price_option(S0, K, T, r, sigma, N, M, option_type);
    printf("Option Price: %f\n", option_price);
    return 0;
}