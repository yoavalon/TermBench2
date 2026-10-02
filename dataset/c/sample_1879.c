#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double monte_carlo_pricing(double S[], int K, double T, double r, double sigma, int N) {
    double dt = T / N;
    double mu = r - 0.5 * sigma * sigma;
    double S_paths[N + 1][1];
    S_paths[0][0] = S[0];
    for (int t = 1; t <= N; t++) {
        double z = (double)rand() / RAND_MAX * 2 - 1;
        S_paths[t][0] = S_paths[t - 1][0] * exp(mu * dt + sigma * sqrt(dt) * z);
    }
    double payoff = fmax(S_paths[N][0] - K, 0);
    return exp(-r * T) * payoff;
}

int main() {
    double S[] = {100};
    double result = monte_carlo_pricing(S, 100, 1, 0.05, 0.2, 100000);
    printf("%f\n", result);
    return 0;
}