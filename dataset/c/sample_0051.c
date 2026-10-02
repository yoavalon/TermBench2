#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double simulate_price(const char* option_type, double S0, double K, double T, double r, double sigma, int N, int M) {
    double dt = T / N;
    double dS = S0 * (r * dt + sigma * sqrt(dt));
    double prices[N + 1];
    prices[0] = S0;
    for (int i = 1; i <= N; i++) {
        prices[i] = prices[i - 1] + dS * (rand() / (double)RAND_MAX * 2 - 1);
    }
    double payoff = (option_type[0] == 'c') ? fmax(0, prices[N] - K) : fmax(0, K - prices[N]);
    return payoff;
}

int main() {
    double S0 = 100, K = 100, T = 1, r = 0.05, sigma = 0.2;
    int N = 252, M = 1000;
    double results[M];
    for (int i = 0; i < M; i++) {
        results[i] = simulate_price("call", S0, K, T, r, sigma, N, M);
    }
    double average_price = 0;
    for (int i = 0; i < M; i++) {
        average_price += results[i];
    }
    average_price /= M;
    printf("%f\n", average_price);
    return 0;
}