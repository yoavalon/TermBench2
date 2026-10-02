#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double financial_model(double S, double K, double T, double r, double sigma, int N, int M) {
    double dt = T / N;
    double S_t = S;
    for (int i = 0; i < N; i++) {
        double z = rand() / (double)RAND_MAX;
        S_t = S_t * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z);
    }
    double payoff = S_t - K;
    if (payoff < 0) payoff = 0;
    double option_price = exp(-r * T) * payoff;
    return option_price;
}

int main() {
    double result = financial_model(100, 100, 1, 0.05, 0.2, 100, 10000);
    printf("%f\n", result);
    return 0;
}