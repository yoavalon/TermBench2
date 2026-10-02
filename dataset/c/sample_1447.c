c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double** generate_paths(double s0, double mu, double sigma, double dt, double T, int N) {
    double** paths = (double**)malloc(N * sizeof(double*));
    for (int i = 0; i < N; i++) {
        paths[i] = (double*)malloc((int(T / dt) + 1) * sizeof(double));
        paths[i][0] = s0;
    }
    for (int t = 1; t <= int(T / dt); t++) {
        double* z = (double*)malloc(N * sizeof(double));
        for (int i = 0; i < N; i++) {
            z[i] = (double)rand() / RAND_MAX * 2 - 1;
        }
        for (int i = 0; i < N; i++) {
            paths[i][t] = paths[i][t - 1] * exp((mu - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z[i]);
        }
        free(z);
    }
    return paths;
}

double* calculate_payoff(double** paths, double strike, const char* option_type, int N) {
    double* payoff = (double*)malloc(N * sizeof(double));
    if (strcmp(option_type, "call") == 0) {
        for (int i = 0; i < N; i++) {
            payoff[i] = fmax(paths[i][int(T / dt)] - strike, 0);
        }
    } else if (strcmp(option_type, "put") == 0) {
        for (int i = 0; i < N; i++) {
            payoff[i] = fmax(strike - paths[i][int(T / dt)], 0);
        }
    }
    return payoff;
}

double monte_carlo_pricing(double s0, double strike, double r, double T, double sigma, int N, double dt, const char* option_type) {
    double** paths = generate_paths(s0, r, sigma, dt, T, N);
    double* payoff = calculate_payoff(paths, strike, option_type, N);
    double discount_factor = exp(-r * T);
    double option_price = 0;
    for (int i = 0; i < N; i++) {
        option_price += payoff[i];
    }
    option_price *= discount_factor / N;
    for (int i = 0; i < N; i++) {
        free(paths[i]);
    }
    free(paths);
    free(payoff);
    return option_price;
}

int main() {
    double s0 = 100.0;
    double strike = 100.0;
    double r = 0.05;
    double T = 1.0;
    double sigma = 0.2;
    int N = 10000;
    double dt = 0.01;
    const char* option_type = "call";
    double price = monte_carlo_pricing(s0, strike, r, T, sigma, N, dt, option_type);
    printf("%f\n", price);
    return 0;
}