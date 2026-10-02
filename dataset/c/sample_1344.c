#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 100
#define M 10000

double simulate_geometric_brownian_motion(double S0, double mu, double sigma, double T, int N) {
    double dt = T / N;
    double t[N];
    double W[N];
    double X[N];
    double S[N];

    t[0] = 0;
    W[0] = 0;
    S[0] = S0;

    for (int i = 1; i < N; i++) {
        t[i] = i * dt;
        W[i] = W[i - 1] + sqrt(dt) * (rand() / (double)RAND_MAX * 2 - 1);
        X[i] = (mu - 0.5 * sigma * sigma) * t[i] + sigma * W[i];
        S[i] = S0 * exp(X[i]);
    }

    return S[N - 1];
}

double monte_carlo_option_pricing(double S0, double K, double T, double r, double sigma, int N, int M) {
    double option_values[M];
    double sum = 0;

    for (int i = 0; i < M; i++) {
        double S = simulate_geometric_brownian_motion(S0, r, sigma, T, N);
        option_values[i] = fmax(S - K, 0);
        sum += option_values[i];
    }

    return exp(-r * T) * (sum / M);
}

int main() {
    srand(time(NULL));

    double S0 = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 100;
    int M = 10000;

    double result = monte_carlo_option_pricing(S0, K, T, r, sigma, N, M);
    printf("%f\n", result);

    return 0;
}