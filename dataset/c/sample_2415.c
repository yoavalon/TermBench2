#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double simulate_option_price(double S0, double K, double T, double r, double sigma, int steps, int trials) {
    double dt = T / steps;
    double **dW = (double **)malloc(steps * sizeof(double *));
    for (int i = 0; i < steps; i++) {
        dW[i] = (double *)malloc(trials * sizeof(double));
    }
    for (int i = 0; i < steps; i++) {
        for (int j = 0; j < trials; j++) {
            dW[i][j] = randn() * sqrt(dt);
        }
    }
    double **S = (double **)malloc((steps + 1) * sizeof(double *));
    for (int i = 0; i <= steps; i++) {
        S[i] = (double *)malloc(trials * sizeof(double));
    }
    S[0][0] = S0;
    for (int i = 0; i < steps; i++) {
        for (int j = 0; j < trials; j++) {
            S[i + 1][j] = S[i][j] * exp((r - 0.5 * sigma * sigma) * dt + sigma * dW[i][j]);
        }
    }
    double payoff = 0;
    for (int j = 0; j < trials; j++) {
        payoff += fmax(S[steps][j] - K, 0);
    }
    payoff /= trials;
    for (int i = 0; i < steps; i++) {
        free(dW[i]);
    }
    free(dW);
    for (int i = 0; i <= steps; i++) {
        free(S[i]);
    }
    free(S);
    return exp(-r * T) * payoff;
}

double randn() {
    double u1 = (double)rand() / RAND_MAX;
    double u2 = (double)rand() / RAND_MAX;
    return sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
}

int main() {
    double result = simulate_option_price(100, 100, 1, 0.05, 0.2, 100, 1000);
    printf("Option Price: %f\n", result);
    return 0;
}