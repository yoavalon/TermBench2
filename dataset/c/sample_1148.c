#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double S;
    double K;
    double T;
    double r;
    double sigma;
    int N;
    int M;
} OptionPricer;

OptionPricer* OptionPricer_init(double S, double K, double T, double r, double sigma, int N, int M) {
    OptionPricer* pricer = (OptionPricer*)malloc(sizeof(OptionPricer));
    pricer->S = S;
    pricer->K = K;
    pricer->T = T;
    pricer->r = r;
    pricer->sigma = sigma;
    pricer->N = N;
    pricer->M = M;
    return pricer;
}

double** simulate_stock_prices(OptionPricer* pricer) {
    double dt = pricer->T / pricer->N;
    double** paths = (double**)malloc(pricer->M * sizeof(double*));
    for (int i = 0; i < pricer->M; i++) {
        paths[i] = (double*)malloc((pricer->N + 1) * sizeof(double));
        paths[i][0] = pricer->S;
    }
    for (int t = 1; t <= pricer->N; t++) {
        for (int i = 0; i < pricer->M; i++) {
            double z = sqrt(-2.0 * log(rand() / (double)RAND_MAX)) * cos(2.0 * M_PI * rand() / (double)RAND_MAX);
            double S_next = paths[i][t - 1] * exp((pricer->r - 0.5 * pricer->sigma * pricer->sigma) * dt + pricer->sigma * z * sqrt(dt));
            paths[i][t] = S_next;
        }
    }
    return paths;
}

double* payoff(OptionPricer* pricer, double** paths) {
    double* payoffs = (double*)malloc(pricer->M * sizeof(double));
    for (int i = 0; i < pricer->M; i++) {
        payoffs[i] = fmax(paths[i][pricer->N] - pricer->K, 0.0);
    }
    return payoffs;
}

double price_option(OptionPricer* pricer) {
    double** paths = simulate_stock_prices(pricer);
    double* payoffs = payoff(pricer, paths);
    double C = exp(-pricer->r * pricer->T) * 0.0;
    for (int i = 0; i < pricer->M; i++) {
        C += payoffs[i];
    }
    C /= pricer->M;

    for (int i = 0; i < pricer->M; i++) {
        free(paths[i]);
    }
    free(paths);
    free(payoffs);

    return C;
}

void main() {
    OptionPricer* pricer = OptionPricer_init(100, 100, 1, 0.05, 0.2, 100, 1000);
    while (1) {
        double price = price_option(pricer);
        printf("Option price: %f\n", price);
    }
}