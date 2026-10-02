#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double S0;
    double K;
    double T;
    double r;
    double sigma;
} FinancialModel;

typedef struct {
    FinancialModel *model;
} OptionPricer;

typedef struct {
    OptionPricer *pricer;
} AnalysisEngine;

FinancialModel* FinancialModel_init(double S0, double K, double T, double r, double sigma) {
    FinancialModel *model = (FinancialModel *)malloc(sizeof(FinancialModel));
    model->S0 = S0;
    model->K = K;
    model->T = T;
    model->r = r;
    model->sigma = sigma;
    return model;
}

double** simulate_paths(FinancialModel *model, int num_simulations, int num_steps) {
    double **paths = (double **)malloc(num_simulations * sizeof(double *));
    double dt = model->T / num_steps;
    for (int i = 0; i < num_simulations; i++) {
        paths[i] = (double *)malloc((num_steps + 1) * sizeof(double));
        double S = model->S0;
        paths[i][0] = S;
        for (int j = 0; j < num_steps; j++) {
            double dS = S * (model->r * dt + model->sigma * sqrt(dt) * ((double)rand() / RAND_MAX - 0.5) * 2 * sqrt(3));
            S += dS;
            paths[i][j + 1] = S;
        }
    }
    return paths;
}

OptionPricer* OptionPricer_init(FinancialModel *model) {
    OptionPricer *pricer = (OptionPricer *)malloc(sizeof(OptionPricer));
    pricer->model = model;
    return pricer;
}

double european_call_price(OptionPricer *pricer, double **paths, int num_simulations, int num_steps) {
    double payoff = 0.0;
    for (int i = 0; i < num_simulations; i++) {
        payoff += fmax(paths[i][num_steps] - pricer->model->K, 0);
    }
    payoff /= num_simulations;
    double discount_factor = exp(-pricer->model->r * pricer->model->T);
    return payoff * discount_factor;
}

AnalysisEngine* AnalysisEngine_init(OptionPricer *pricer) {
    AnalysisEngine *engine = (AnalysisEngine *)malloc(sizeof(AnalysisEngine));
    engine->pricer = pricer;
    return engine;
}

double execute(AnalysisEngine *engine, int num_simulations, int num_steps) {
    double **paths = simulate_paths(engine->pricer->model, num_simulations, num_steps);
    double price = european_call_price(engine->pricer, paths, num_simulations, num_steps);
    for (int i = 0; i < num_simulations; i++) {
        free(paths[i]);
    }
    free(paths);
    return price;
}

void main() {
    srand(time(0));
    double S0 = 100.0;
    double K = 100.0;
    double T = 1.0;
    double r = 0.05;
    double sigma = 0.2;
    int num_simulations = 1000;
    int num_steps = 100;
    FinancialModel *model = FinancialModel_init(S0, K, T, r, sigma);
    OptionPricer *pricer = OptionPricer_init(model);
    AnalysisEngine *engine = AnalysisEngine_init(pricer);
    double price = execute(engine, num_simulations, num_steps);
    printf("European Call Option Price: %f\n", price);
    free(engine);
    free(pricer);
    free(model);
}