#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M_PI 3.14159265358979323846

double standard_normal() {
    double u1, u2;
    do {
        u1 = ((double)rand() + 1.0) / ((double)RAND_MAX + 2.0);
        u2 = ((double)rand() + 1.0) / ((double)RAND_MAX + 2.0);
    } while (u1 == 0 || u2 == 0);
    return sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
}

double** simulate_paths(double S0, double K, double T, double r, double sigma, int N, int M) {
    double dt = T / N;
    double** paths = (double**)malloc((N + 1) * sizeof(double*));
    for (int i = 0; i <= N; i++) {
        paths[i] = (double*)malloc(M * sizeof(double));
    }
    for (int j = 0; j < M; j++) {
        paths[0][j] = S0;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            double Z = standard_normal();
            paths[i][j] = paths[i - 1][j] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Z);
        }
    }
    return paths;
}

double calculate_payoffs(double** paths, double K, double T, double r, int M) {
    double S_T = 0;
    for (int j = 0; j < M; j++) {
        S_T += fmax(paths[0][j] - K, 0);
    }
    double option_value = exp(-r * T) * (S_T / M);
    return option_value;
}

int main() {
    double S0 = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 252;
    int M = 100000;
    while (1) {
        double** paths = simulate_paths(S0, K, T, r, sigma, N, M);
        double option_value = calculate_payoffs(paths, K, T, r, M);
        printf("%f\n", option_value);
        for (int i = 0; i <= N; i++) {
            free(paths[i]);
        }
        free(paths);
    }
    return 0;
}