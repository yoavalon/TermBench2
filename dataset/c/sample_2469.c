#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double monte_carlo_option_pricing(double S, double K, double T, double r, double sigma, int N) {
    double dt = T / N;
    double St = S;
    double option_price = 0;
    for (int i = 0; i < N; i++) {
        St *= 1 + r * dt + sigma * randn() * sqrt(dt);
    }
    option_price = St - K > 0 ? St - K : 0;
    return option_price;
}

double randn() {
    double u1 = (double)rand() / RAND_MAX;
    double u2 = (double)rand() / RAND_MAX;
    return sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
}

int main() {
    double S = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 252;
    printf("%f\n", monte_carlo_option_pricing(S, K, T, r, sigma, N));
    return 0;
}