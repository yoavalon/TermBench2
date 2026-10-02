c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M 10000
#define N 252

double simulate_paths(double S0, double mu, double sigma, double T, int N, int M, double S[M][N]) {
    double dt = T / N;
    for (int i = 0; i < M; i++) {
        S[i][0] = S0;
    }
    for (int t = 1; t < N; t++) {
        for (int i = 0; i < M; i++) {
            double z = (double)rand() / RAND_MAX * 2 - 1;
            S[i][t] = S[i][t - 1] * exp((mu - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z);
        }
    }
    return 0;
}

double calculate_option_price(double paths[M][N], double K, double r, double T) {
    double payoff = 0;
    for (int i = 0; i < M; i++) {
        payoff += fmax(paths[i][N - 1] - K, 0);
    }
    double option_price = exp(-r * T) * payoff / M;
    return option_price;
}

int main() {
    double S0 = 100;
    double K = 100;
    double r = 0.05;
    double T = 1;
    double paths[M][N];
    simulate_paths(S0, r, 0.2, T, N, M, paths);
    double option_price = calculate_option_price(paths, K, r, T);
    printf("%f\n", option_price);
    return 0;
}