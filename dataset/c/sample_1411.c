#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double **simulate_paths(double S0, double mu, double sigma, double T, int N, int M) {
    double dt = T / N;
    double **paths = (double **)malloc(M * sizeof(double *));
    for (int i = 0; i < M; i++) {
        paths[i] = (double *)malloc((N + 1) * sizeof(double));
        paths[i][0] = S0;
    }
    for (int t = 1; t <= N; t++) {
        for (int i = 0; i < M; i++) {
            double z = sqrt(-2 * log((double)rand() / RAND_MAX)) * cos(2 * M_PI * (double)rand() / RAND_MAX);
            paths[i][t] = paths[i][t - 1] * exp((mu - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z);
        }
    }
    return paths;
}

double *calculate_payoffs(double **paths, double K, double T, double r, int M, const char *type) {
    double *payoffs = (double *)malloc(M * sizeof(double));
    for (int i = 0; i < M; i++) {
        double ST = paths[i][M];
        double payoff;
        if (strcmp(type, "call") == 0) {
            payoff = fmax(0, ST - K);
        } else {
            payoff = fmax(0, K - ST);
        }
        payoffs[i] = payoff * exp(-r * T);
    }
    return payoffs;
}

double monte_carlo_pricing(double S0, double K, double T, double r, double sigma, int M) {
    double **paths = simulate_paths(S0, r, sigma, T, 100, M);
    double *payoffs = calculate_payoffs(paths, K, T, r, M, "call");
    double sum = 0;
    for (int i = 0; i < M; i++) {
        sum += payoffs[i];
    }
    for (int i = 0; i < M; i++) {
        free(paths[i]);
    }
    free(paths);
    free(payoffs);
    return sum / M;
}

int main() {
    double S0 = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int M = 10000;
    double price = monte_carlo_pricing(S0, K, T, r, sigma, M);
    printf("Option Price: %.2f\n", price);
    return 0;
}