#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double financial_model(double S, double K, double T, double r, double sigma, int N) {
    double dt = T / N;
    double dS = S * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * ((double)rand() / RAND_MAX * 2 - 1));
    double payoff = (dS - K > 0) ? dS - K : 0;
    double option_price = exp(-r * T) * payoff;
    return option_price;
}

int main() {
    srand(time(NULL));
    financial_model(100, 100, 1, 0.05, 0.2, 1000);
    return 0;
}