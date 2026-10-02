#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double** generate_paths(double S0, double mu, double sigma, double T, int N, int M) {
    double dt = T / N;
    double** S = (double**)malloc((N + 1) * sizeof(double*));
    for (int i = 0; i < N + 1; i++) {
        S[i] = (double*)malloc(M * sizeof(double));
        for (int j = 0; j < M; j++) {
            if (i == 0) {
                S[i][j] = S0;
            } else {
                S[i][j] = S[i - 1][j] * exp((mu - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * ((double)rand() / RAND_MAX * 2 - 1));
            }
        }
    }
    return S;
}

double option_price(double** paths, double K, double r, double T, double (*payoff)(double*, double, int)) {
    double discounted_payoffs = 0;
    for (int j = 0; j < M; j++) {
        discounted_payoffs += exp(-r * T) * payoff(paths[N], K, j);
    }
    return discounted_payoffs / M;
}

double european_call(double* S, double K, int j) {
    return S[j] - K > 0 ? S[j] - K : 0;
}

int main() {
    double S0 = 100;
    double K = 100;
    double r = 0.05;
    double T = 1;
    int N = 252;
    int M = 10000;
    double sigma = 0.2;
    double mu = 0.1;

    double** paths = generate_paths(S0, mu, sigma, T, N, M);
    double call_price = option_price(paths, K, r, T, european_call);
    printf("%f\n", call_price);

    for (int i = 0; i < N + 1; i++) {
        free(paths[i]);
    }
    free(paths);

    return 0;
}