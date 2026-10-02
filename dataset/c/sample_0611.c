#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double monte_carlo_pricing(double S, double K, double T, double r, double sigma, int N, int M) {
    double dt = T / N;
    double paths[M][N + 1];
    for (int j = 0; j < M; j++) {
        paths[j][0] = S;
    }
    for (int t = 1; t <= N; t++) {
        for (int j = 0; j < M; j++) {
            double z = sqrt(dt) * randn();
            paths[j][t] = paths[j][t - 1] * exp((r - 0.5 * sigma * sigma) * dt + sigma * z);
        }
    }
    double payoff_sum = 0;
    for (int j = 0; j < M; j++) {
        payoff_sum += fmax(paths[j][N] - K, 0);
    }
    return exp(-r * T) * payoff_sum / M;
}

double randn() {
    double u1, u2;
    do {
        u1 = rand() / (double)RAND_MAX;
        u2 = rand() / (double)RAND_MAX;
    } while (u1 == 0 || u2 == 0);
    return sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
}

int main() {
    double result = monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 100, 10000);
    printf("%f\n", result);
    return 0;
}