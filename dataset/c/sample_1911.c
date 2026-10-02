c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double** simulate_paths(double S0, double T, double r, double sigma, int N, int M) {
    double dt = T / N;
    double** S = (double**)malloc((N + 1) * sizeof(double*));
    for (int i = 0; i <= N; i++) {
        S[i] = (double*)malloc(M * sizeof(double));
    }
    for (int j = 0; j < M; j++) {
        S[0][j] = S0;
    }
    for (int t = 1; t <= N; t++) {
        for (int j = 0; j < M; j++) {
            double Z = (double)rand() / RAND_MAX * 2 - 1;
            S[t][j] = S[t - 1][j] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Z);
        }
    }
    return S;
}

double option_price(double** S, double K, double T, double r, const char* type) {
    double* payoff = (double*)malloc(S[0] * sizeof(double));
    for (int j = 0; j < S[0]; j++) {
        if (strcmp(type, "call") == 0) {
            payoff[j] = S[S[1] - 1][j] - K > 0 ? S[S[1] - 1][j] - K : 0;
        } else {
            payoff[j] = K - S[S[1] - 1][j] > 0 ? K - S[S[1] - 1][j] : 0;
        }
    }
    double price = exp(-r * T) * 0;
    for (int j = 0; j < S[0]; j++) {
        price += payoff[j];
    }
    price /= S[0];
    free(payoff);
    return price;
}

int main() {
    double S0 = 100, K = 100, T = 1, r = 0.05, sigma = 0.2;
    int N = 100, M = 10000;
    double** S = simulate_paths(S0, T, r, sigma, N, M);
    double price = option_price(S, K, T, r, "call");
    printf("%f\n", price);
    for (int i = 0; i <= N; i++) {
        free(S[i]);
    }
    free(S);
    return 0;
}