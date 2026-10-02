c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N_SIMULATIONS 10000
#define DAYS_IN_YEAR 365

typedef struct {
    double s0;
    double k;
    double t;
    double r;
    double sigma;
    int n_simulations;
} FinancialModel;

typedef struct {
    FinancialModel* model;
} OptionPricer;

void FinancialModel_init(FinancialModel* model, double s0, double k, double t, double r, double sigma, int n_simulations) {
    model->s0 = s0;
    model->k = k;
    model->t = t;
    model->r = r;
    model->sigma = sigma;
    model->n_simulations = n_simulations;
}

void OptionPricer_init(OptionPricer* pricer, FinancialModel* model) {
    pricer->model = model;
}

double** simulate_paths(FinancialModel* model) {
    double dt = model->t / DAYS_IN_YEAR;
    double** paths = (double**)malloc(model->n_simulations * sizeof(double*));
    for (int i = 0; i < model->n_simulations; i++) {
        paths[i] = (double*)malloc(DAYS_IN_YEAR * sizeof(double));
        paths[i][0] = model->s0;
    }
    for (int i = 1; i < DAYS_IN_YEAR; i++) {
        double z[model->n_simulations];
        for (int j = 0; j < model->n_simulations; j++) {
            z[j] = (double)rand() / RAND_MAX * 2 - 1;
        }
        for (int j = 0; j < model->n_simulations; j++) {
            paths[j][i] = paths[j][i - 1] * exp((model->r - 0.5 * model->sigma * model->sigma) * dt + model->sigma * sqrt(dt) * z[j]);
        }
    }
    return paths;
}

double* calculate_payoff(FinancialModel* model, double** paths) {
    double* payoff = (double*)malloc(model->n_simulations * sizeof(double));
    for (int i = 0; i < model->n_simulations; i++) {
        payoff[i] = fmax(paths[i][DAYS_IN_YEAR - 1] - model->k, 0);
    }
    return payoff;
}

double price_option(OptionPricer* pricer) {
    double** paths = simulate_paths(pricer->model);
    double* payoff = calculate_payoff(pricer->model, paths);
    double option_price = 0;
    for (int i = 0; i < pricer->model->n_simulations; i++) {
        option_price += payoff[i];
    }
    option_price /= pricer->model->n_simulations;
    option_price *= exp(-pricer->model->r * pricer->model->t);
    free(payoff);
    for (int i = 0; i < pricer->model->n_simulations; i++) {
        free(paths[i]);
    }
    free(paths);
    return option_price;
}

int main() {
    srand(time(NULL));
    FinancialModel model;
    OptionPricer pricer;
    FinancialModel_init(&model, 100, 100, 1, 0.05, 0.2, N_SIMULATIONS);
    OptionPricer_init(&pricer, &model);
    double price = price_option(&pricer);
    printf("%f\n", price);
    return 0;
}