#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double simulate_paths(int N, int M, double S0, double K, double T, double r, double sigma, double S[N + 1][M]) {
    double dt = T / N;
    for (int i = 0; i < M; i++) {
        S[0][i] = S0;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            double Z = ((double)rand() / RAND_MAX) * 2 - 1; // standard normal approximation
            S[i][j] = S[i - 1][j] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Z);
        }
    }
    return 0;
}

double option_price(double S[N + 1][M], double K, double r, double T, int N, int M) {
    double payoff = 0;
    for (int i = 0; i < M; i++) {
        payoff += fmax(S[N][i] - K, 0);
    }
    double price = exp(-r * T) * (payoff / M);
    return price;
}

int main() {
    int S0 = 100;
    int K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 100;
    int M = 10000;
    double paths[N + 1][M];
    simulate_paths(N, M, S0, K, T, r, sigma, paths);
    double price = option_price(paths, K, r, T, N, M);
    printf("%f\n", price);
    return 0;
}