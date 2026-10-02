#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double monte_carlo_option_pricing(double S0, double K, double T, double r, double sigma, int N) {
    double dt = T / N;
    double *S = (double *)malloc((N + 1) * sizeof(double));
    S[0] = S0;
    for (int i = 1; i <= N; i++) {
        S[i] = S[i - 1] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * ((double)rand() / RAND_MAX * 2 - 1));
    }
    double payoff = S[N] - K > 0 ? S[N] - K : 0;
    double option_price = exp(-r * T) * payoff;
    free(S);
    return option_price;
}

int main() {
    double result = monte_carlo_option_pricing(100, 100, 1, 0.05, 0.2, 1000);
    printf("%f\n", result);
    return 0;
}