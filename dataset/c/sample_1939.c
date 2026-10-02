#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M_PI 3.14159265358979323846

double simulate_stock_prices(double S0, double mu, double sigma, double T, int N, int M) {
    double dt = T / N;
    double **S = (double **)malloc(M * sizeof(double *));
    for (int i = 0; i < M; i++) {
        S[i] = (double *)malloc((N + 1) * sizeof(double));
        S[i][0] = S0;
    }
    for (int t = 1; t <= N; t++) {
        for (int i = 0; i < M; i++) {
            double Z = sqrt(-2 * log((double)rand() / RAND_MAX)) * cos(2 * M_PI * (double)rand() / RAND_MAX);
            S[i][t] = S[i][t - 1] * exp((mu - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Z);
        }
    }
    double option_price = 0;
    for (int i = 0; i < M; i++) {
        option_price += fmax(S[i][N] - K, 0);
    }
    option_price *= exp(-r * T) / M;
    for (int i = 0; i < M; i++) {
        free(S[i]);
    }
    free(S);
    return option_price;
}

int main() {
    double S0 = 100.0;
    double K = 100.0;
    double T = 1.0;
    double r = 0.05;
    double sigma = 0.2;
    int N = 100;
    int M = 100000;
    double option_price = simulate_stock_prices(S0, r, sigma, T, N, M);
    printf("%f\n", option_price);
    return 0;
}