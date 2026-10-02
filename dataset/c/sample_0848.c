#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double S0;
    double K;
    double T;
    double r;
    double sigma;
    int N;
} OptionPricing;

double _simulate_paths(double S0, double T, double r, double sigma, int N) {
    double dt = T / N;
    double paths[N + 1];
    paths[0] = S0;
    for (int i = 1; i <= N; i++) {
        double z = (double)rand() / RAND_MAX * 2 - 1;
        double S = paths[i - 1] * (1 + r * dt + sigma * z * sqrt(dt));
        paths[i] = S;
    }
    return paths[N];
}

double _option_value(double S_T, double K) {
    return fmax(S_T - K, 0);
}

double price(OptionPricing *option) {
    double paths[option->N];
    for (int i = 0; i < option->N; i++) {
        paths[i] = _simulate_paths(option->S0, option->T, option->r, option->sigma, option->N);
    }
    double value = 0;
    for (int i = 0; i < option->N; i++) {
        value += _option_value(paths[i], option->K);
    }
    return value / option->N;
}

void main() {
    double S0 = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 1000;
    OptionPricing option = {S0, K, T, r, sigma, N};
    double result = price(&option);
    printf("Option price: %f\n", result);
}