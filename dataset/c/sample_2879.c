#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double simulate_paths(double S0, double T, double r, double sigma, int N, int M, double paths[M][N + 1]) {
    double dt = T / N;
    for (int i = 0; i < M; i++) {
        paths[i][0] = S0;
    }
    for (int t = 1; t <= N; t++) {
        for (int i = 0; i < M; i++) {
            double z = (double)rand() / RAND_MAX * 2 - 1;
            paths[i][t] = paths[i][t - 1] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z);
        }
    }
}

double price_option(double paths[M][N + 1], double strike, char* option_type, double r, double T, int M) {
    double payoff = 0;
    for (int i = 0; i < M; i++) {
        if (strcmp(option_type, "call") == 0) {
            payoff += fmax(paths[i][N] - strike, 0);
        } else if (strcmp(option_type, "put") == 0) {
            payoff += fmax(strike - paths[i][N], 0);
        }
    }
    return exp(-r * T) * (payoff / M);
}

int main() {
    srand(time(NULL));
    double S0 = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 252;
    int M = 10000;
    double strike = 100;
    char* option_type = "call";
    double paths[M][N + 1];

    while (1) {
        simulate_paths(S0, T, r, sigma, N, M, paths);
        double price = price_option(paths, strike, option_type, r, T, M);
        printf("%f\n", price);
    }

    return 0;
}