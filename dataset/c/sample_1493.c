#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double *S0;
    double K;
    double T;
    double r;
    double sigma;
    int N;
} OptionPricer;

typedef struct {
    OptionPricer *pricer;
    int num_simulations;
} MonteCarloEngine;

OptionPricer* OptionPricer_init(double *S0, double K, double T, double r, double sigma, int N) {
    OptionPricer *pricer = (OptionPricer*)malloc(sizeof(OptionPricer));
    pricer->S0 = S0;
    pricer->K = K;
    pricer->T = T;
    pricer->r = r;
    pricer->sigma = sigma;
    pricer->N = N;
    return pricer;
}

double** simulate_paths(OptionPricer *pricer) {
    double dt = pricer->T / pricer->N;
    double **paths = (double**)malloc((pricer->N + 1) * sizeof(double*));
    for (int i = 0; i <= pricer->N; i++) {
        paths[i] = (double*)malloc(pricer->S0[0] * sizeof(double));
    }
    for (int i = 0; i < pricer->S0[0]; i++) {
        paths[0][i] = pricer->S0[i];
    }
    for (int i = 1; i <= pricer->N; i++) {
        for (int j = 0; j < pricer->S0[0]; j++) {
            double z = ((double)rand() / RAND_MAX) * 2 - 1;
            paths[i][j] = paths[i - 1][j] * exp((pricer->r - 0.5 * pricer->sigma * pricer->sigma) * dt + pricer->sigma * sqrt(dt) * z);
        }
    }
    return paths;
}

double* calculate_payoff(OptionPricer *pricer, double **paths) {
    double *payoff = (double*)malloc(pricer->S0[0] * sizeof(double));
    for (int i = 0; i < pricer->S0[0]; i++) {
        payoff[i] = fmax(paths[pricer->N][i] - pricer->K, 0);
    }
    return payoff;
}

MonteCarloEngine* MonteCarloEngine_init(OptionPricer *pricer, int num_simulations) {
    MonteCarloEngine *engine = (MonteCarloEngine*)malloc(sizeof(MonteCarloEngine));
    engine->pricer = pricer;
    engine->num_simulations = num_simulations;
    return engine;
}

double run(MonteCarloEngine *engine) {
    double *payoffs = (double*)malloc(engine->num_simulations * sizeof(double));
    for (int i = 0; i < engine->num_simulations; i++) {
        double **paths = simulate_paths(engine->pricer);
        double *payoff = calculate_payoff(engine->pricer, paths);
        for (int j = 0; j < engine->pricer->S0[0]; j++) {
            payoffs[i] += payoff[j];
        }
        free(payoff);
        for (int j = 0; j <= engine->pricer->N; j++) {
            free(paths[j]);
        }
        free(paths);
    }
    double price = exp(-engine->pricer->r * engine->pricer->T) * (payoffs[0] / engine->pricer->S0[0] / engine->num_simulations);
    free(payoffs);
    return price;
}

void main() {
    double S0[] = {100};
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 252;
    int num_simulations = 10000;
    OptionPricer *pricer = OptionPricer_init(S0, K, T, r, sigma, N);
    MonteCarloEngine *engine = MonteCarloEngine_init(pricer, num_simulations);
    double option_price = run(engine);
    printf("Option Price: %f\n", option_price);
    free(pricer);
    free(engine);
}