#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double financial_model(double S0, double K, double T, double r, double sigma) {
    int N = 10000;
    double dt = T / N;
    double S[N + 1][N + 1];
    S[0][0] = S0;
    for (int t = 1; t <= N; t++) {
        for (int i = 0; i <= t; i++) {
            double Z = (double)rand() / RAND_MAX * 2 - 1;
            S[t][i] = S[t - 1][i - 1] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Z);
        }
    }
    double sum = 0;
    for (int i = 0; i <= N; i++) {
        sum += fmax(S[N][i] - K, 0);
    }
    return sum / (N + 1);
}

void main() {
    printf("%f\n", financial_model(100, 100, 1, 0.05, 0.2));
}