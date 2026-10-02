#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double simulate_paths(double S0, double mu, double sigma, double T, int N, int M, double paths[M][N+1]) {
    double dt = T / N;
    for (int j = 0; j < M; j++) {
        paths[j][0] = S0;
    }
    for (int t = 1; t <= N; t++) {
        for (int i = 0; i < M; i++) {
            double z = (double)rand() / RAND_MAX * 2 - 1;
            z = sqrt(-2 * log(z)) * cos(2 * M_PI * ((double)rand() / RAND_MAX));
            double S = paths[i][t-1] * (1 + mu * dt + sigma * z * sqrt(dt));
            paths[i][t] = S;
        }
    }
    return paths[0][N]; // Return the last price of the first path for demonstration
}

double calculate_option_price(double paths[M][N+1], double K, double r, double T, int M, int N) {
    double payoff = 0;
    for (int i = 0; i < M; i++) {
        payoff += fmax(paths[i][N] - K, 0);
    }
    double price = payoff * (1 / M) * (1 / (1 + r * T));
    return price;
}

int main() {
    int S0 = 100;
    int K = 100;
    double r = 0.05;
    double T = 1;
    int N = 100;
    int M = 1000;
    double paths[M][N+1];
    simulate_paths(S0, r - 0.5 * 0.2 * 0.2, 0.2, T, N, M, paths);
    double price = calculate_option_price(paths, K, r, T, M, N);
    printf("%f\n", price);
    return 0;
}