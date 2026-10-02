#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double simulate_option_price(double S0, double K, double T, double r, double sigma, int N) {
    double dt = T / N;
    double S = S0;
    for (int i = 0; i < N; i++) {
        S *= exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * (double)rand() / RAND_MAX);
    }
    return S - K > 0 ? S - K : 0;
}

double monte_carlo_pricing(double S0, double K, double T, double r, double sigma, int M, int N) {
    double total = 0;
    for (int i = 0; i < M; i++) {
        total += simulate_option_price(S0, K, T, r, sigma, N);
    }
    return total / M * exp(-r * T);
}

int main() {
    double S0 = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int M = 1000;
    int N = 100;
    printf("%f\n", monte_carlo_pricing(S0, K, T, r, sigma, M, N));
    return 0;
}