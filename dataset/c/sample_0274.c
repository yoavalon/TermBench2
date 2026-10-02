#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double generate_paths(double S0, double mu, double sigma, double T, int N, int M, double paths[M][N+1]) {
    double dt = T / N;
    for (int j = 0; j < M; j++) {
        paths[j][0] = S0;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            double z = rand() / (double)RAND_MAX * 2 - 1;
            double S = paths[j][i-1] * (1 + mu * dt + sigma * z * sqrt(dt));
            paths[j][i] = S;
        }
    }
}

double* payoff(double paths[M][N+1], double K, int M, double payoffs[M]) {
    for (int j = 0; j < M; j++) {
        payoffs[j] = fmax(paths[j][N] - K, 0);
    }
    return payoffs;
}

double* discount(double payoffs[M], double r, double T, int M, double discounted_payoffs[M]) {
    for (int j = 0; j < M; j++) {
        discounted_payoffs[j] = payoffs[j] / pow(1 + r, T);
    }
    return discounted_payoffs;
}

void main() {
    int S0 = 100;
    int K = 100;
    double r = 0.05;
    double T = 1;
    int N = 252;
    int M = 10000;
    double mu = 0.05;
    double sigma = 0.2;
    double paths[M][N+1];
    double payoffs[M];
    double discounted_payoffs[M];
    double option_price;

    generate_paths(S0, mu, sigma, T, N, M, paths);
    payoff(paths, K, M, payoffs);
    discount(payoffs, r, T, M, discounted_payoffs);

    double sum = 0;
    for (int j = 0; j < M; j++) {
        sum += discounted_payoffs[j];
    }
    option_price = sum / M;

    printf("Option Price: %f\n", option_price);
}