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
    int M;
} FinancialModel;

void simulate_paths(FinancialModel *model, double paths[model->N + 1][model->M]) {
    double dt = model->T / model->N;
    for (int i = 0; i < model->M; i++) {
        paths[0][i] = model->S0;
    }
    for (int i = 1; i <= model->N; i++) {
        for (int j = 0; j < model->M; j++) {
            double z = (double)rand() / RAND_MAX * 2 - 1; // Standard normal random variable
            paths[i][j] = paths[i - 1][j] * exp((model->r - 0.5 * model->sigma * model->sigma) * dt + model->sigma * sqrt(dt) * z);
        }
    }
}

double option_price(FinancialModel *model) {
    double paths[model->N + 1][model->M];
    simulate_paths(model, paths);
    double payoff = 0.0;
    for (int i = 0; i < model->M; i++) {
        payoff += fmax(paths[model->N][i] - model->K, 0);
    }
    double price = exp(-model->r * model->T) * (payoff / model->M);
    return price;
}

void main() {
    FinancialModel model;
    model.S0 = 100;
    model.K = 100;
    model.T = 1;
    model.r = 0.05;
    model.sigma = 0.2;
    model.N = 100;
    model.M = 10000;
    double price = option_price(&model);
    printf("%f\n", price);
}