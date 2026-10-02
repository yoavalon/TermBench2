#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double generate_paths(double S0, double r, double sigma, double T, int N, int M, double paths[M][N+1]) {
    for (int m = 0; m < M; m++) {
        paths[m][0] = S0;
        double dt = T / N;
        for (int n = 1; n <= N; n++) {
            double z = rand() / (double)RAND_MAX * 2 - 1;
            double S = paths[m][n-1] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z);
            paths[m][n] = S;
        }
    }
}

double payoff_function(double S) {
    return S > 100 ? S - 100 : 0;
}

double monte_carlo_pricing(double paths[M][N+1], int M, double (*payoff_function)(double)) {
    double total_payoff = 0;
    for (int m = 0; m < M; m++) {
        total_payoff += payoff_function(paths[m][N]);
    }
    return total_payoff / M * exp(-0.05 * 1);
}

int main() {
    double S0 = 100;
    double r = 0.05;
    double sigma = 0.2;
    double T = 1;
    int N = 252;
    int M = 10000;
    double paths[M][N+1];
    generate_paths(S0, r, sigma, T, N, M, paths);
    double option_price = monte_carlo_pricing(paths, M, payoff_function);
    printf("Option Price: %f\n", option_price);
    return 0;
}