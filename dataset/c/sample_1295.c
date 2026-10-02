#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double financial_model(double T, int N, double S0, double K, double r, double sigma) {
    double dt = T / N;
    double **S = (double **)malloc((N + 1) * sizeof(double *));
    for (int i = 0; i <= N; i++) {
        S[i] = (double *)malloc((N + 1) * sizeof(double));
    }
    S[0][0] = S0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            S[i][j] = j > 0 ? S[i - 1][j - 1] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * ((double)rand() / RAND_MAX * 2 - 1)) : 0;
        }
    }
    double payoff_sum = 0;
    for (int j = 0; j <= N; j++) {
        payoff_sum += fmax(S[N][j] - K, 0);
    }
    double option_price = exp(-r * T) * (payoff_sum / (N + 1));
    for (int i = 0; i <= N; i++) {
        free(S[i]);
    }
    free(S);
    return option_price;
}

int main() {
    srand(time(NULL));
    double result = financial_model(1, 100, 100, 100, 0.05, 0.2);
    printf("%f\n", result);
    return 0;
}