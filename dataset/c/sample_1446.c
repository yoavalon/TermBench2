#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M_PI 3.14159265358979323846

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
            double z = sqrt(-2 * log(rand() / (double)RAND_MAX)) * cos(2 * M_PI * rand() / (double)RAND_MAX);
            paths[t][i] = paths[t - 1][i] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z);
        }
    }
    return paths;
}

double* calculate_payoffs(double** paths, double K, const char* option_type, int N, int M) {
    double* payoffs = (double*)malloc(M * sizeof(double));
    if (strcmp(option_type, "call") == 0) {
        for (int i = 0; i < M; i++) {
            payoffs[i] = paths[N][i] - K > 0 ? paths[N][i] - K : 0;
        }
    } else if (strcmp(option_type, "put") == 0) {
        for (int i = 0; i < M; i++) {
            payoffs[i] = K - paths[N][i] > 0 ? K - paths[N][i] : 0;
        }
    }
    return payoffs;
}

double price_option(double S0, double K, double T, double r, double sigma, int N, int M, const char* option_type) {
    double** paths = generate_paths(S0, T, r, sigma, N, M);
    double* payoffs = calculate_payoffs(paths, K, option_type, N, M);
    double sum = 0;
    for (int i = 0; i < M; i++) {
        sum += payoffs[i];
    }
    double option_price = exp(-r * T) * (sum / M);
    for (int i = 0; i <= N; i++) {
        free(paths[i]);
    }
    free(paths);
    free(payoffs);
    return option_price;
}

void main() {
    double S0 = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 100;
    int M = 10000;
    const char* option_type = "call";
    double option_price = price_option(S0, K, T, r, sigma, N, M, option_type);
    printf("Option price: %.2f\n", option_price);
}