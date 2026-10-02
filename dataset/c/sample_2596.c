#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double simulate_geometric_brownian_motion(double S0, double mu, double sigma, double T, int N) {
    double dt = T / N;
    double S = S0;
    for (int i = 1; i <= N; i++) {
        double dS = S * (mu * dt + sigma * sqrt(dt) * (2.0 * rand() / RAND_MAX - 1.0));
        S += dS;
    }
    return S;
}

double monte_carlo_option_pricing(double S0, double K, double T, double r, double sigma, int N, int M) {
    double C = 0;
    for (int _ = 0; _ < M; _++) {
        double ST = simulate_geometric_brownian_motion(S0, r, sigma, T, N);
        C += fmax(ST - K, 0);
    }
    return C / M;
}

int main() {
    double S0 = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 100;
    int M = 1000;
    double option_price = monte_carlo_option_pricing(S0, K, T, r, sigma, N, M);
    printf("%f\n", option_price);
    return 0;
}