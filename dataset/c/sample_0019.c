#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

double calculate_option_price(double S, double K, double r, double T, double sigma, int N) {
    double dt = T / N;
    double dS = S * sigma * sqrt(dt);
    double paths[N];
    paths[0] = S;
    for (int i = 1; i < N; i++) {
        paths[i] = paths[i - 1] * exp((r - 0.5 * sigma * sigma) * dt + dS * ((double)rand() / RAND_MAX * 2 - 1));
    }
    double payoff = fmax(paths[N - 1] - K, 0);
    return exp(-r * T) * payoff;
}

int main() {
    srand(time(NULL));
    double result = calculate_option_price(100, 100, 0.05, 1, 0.2, 1000);
    printf("%f\n", result);
    return 0;
}