#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M 10000

double simulate_paths(double S0, double T, double r, double sigma, int N, double paths[N + 1][M]) {
    double dt = T / N;
    for (int j = 0; j < M; j++) {
        paths[0][j] = S0;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            double z = ((double)rand() / RAND_MAX) * 2 - 1;
            paths[i][j] = paths[i - 1][j] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z);
        }
    }
    return paths[N][0];
}

double calculate_payoff(double paths[N + 1][M], double K, double T, int N) {
    double payoff = 0;
    for (int j = 0; j < M; j++) {
        double ST = paths[N][j];
        payoff += fmax(ST - K, 0);
    }
    return payoff / M;
}

double monte_carlo_pricing(double S0, double K, double T, double r, double sigma, int N) {
    double paths[N + 1][M];
    double payoff = calculate_payoff(paths, K, T, N);
    double option_price = exp(-r * T) * payoff;
    return option_price;
}

int main() {
    double S0 = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 100;
    double price = monte_carlo_pricing(S0, K, T, r, sigma, N);
    printf("Option Price: %f\n", price);
    return 0;
}