#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    double S0;
    double K;
    double T;
    double r;
    double sigma;
    int N;
} FinancialModel;

typedef struct {
    FinancialModel *model;
} PricingEngine;

double **simulate_paths(FinancialModel *model) {
    double dt = model->T / model->N;
    double **paths = (double **)malloc(model->N * sizeof(double *));
    paths[0] = (double *)malloc(model->N * sizeof(double));
    paths[0][0] = model->S0;
    for (int i = 1; i < model->N; i++) {
        paths[i] = (double *)malloc(model->N * sizeof(double));
        for (int j = 0; j < i; j++) {
            double S = paths[j][i - 1];
            double Z = (double)rand() / RAND_MAX * 2 - 1;
            double S_new = S * exp((model->r - 0.5 * model->sigma * model->sigma) * dt + model->sigma * Z * sqrt(dt));
            paths[j][i] = S_new;
        }
    }
    return paths;
}

double *calculate_payoff(FinancialModel *model, double **paths) {
    double *payoffs = (double *)malloc(model->N * sizeof(double));
    for (int i = 0; i < model->N; i++) {
        double ST = paths[i][model->N - 1];
        double payoff = fmax(0, ST - model->K);
        payoffs[i] = payoff;
    }
    return payoffs;
}

double price_option(PricingEngine *engine) {
    FinancialModel *model = engine->model;
    double **paths = simulate_paths(model);
    double *payoffs = calculate_payoff(model, paths);
    double discounted_payoffs = 0;
    for (int i = 0; i < model->N; i++) {
        discounted_payoffs += payoffs[i] * exp(-model->r * model->T);
    }
    double option_price = discounted_payoffs / model->N;
    free(paths);
    free(payoffs);
    return option_price;
}

int main() {
    srand(time(NULL));
    FinancialModel model = {100, 100, 1, 0.05, 0.2, 100};
    PricingEngine engine = {&model};
    double price = price_option(&engine);
    printf("%f\n", price);
    return 0;
}