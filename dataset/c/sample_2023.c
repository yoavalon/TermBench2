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
    int M;
} FinancialModel;

void FinancialModel_init(FinancialModel *self, double S0, double K, double T, double r, double sigma, int N, int M) {
    self->S0 = S0;
    self->K = K;
    self->T = T;
    self->r = r;
    self->sigma = sigma;
    self->N = N;
    self->M = M;
}

void FinancialModel_simulate_paths(FinancialModel *self, double **S) {
    double dt = self->T / self->N;
    for (int i = 0; i < self->M; i++) {
        S[i][0] = self->S0;
    }
    for (int t = 1; t <= self->N; t++) {
        for (int i = 0; i < self->M; i++) {
            double Z = (double)rand() / RAND_MAX * 2 - 1;
            S[i][t] = S[i][t - 1] * exp((self->r - 0.5 * self->sigma * self->sigma) * dt + self->sigma * sqrt(dt) * Z);
        }
    }
}

double FinancialModel_calculate_option_price(FinancialModel *self) {
    double **S = (double **)malloc(self->M * sizeof(double *));
    for (int i = 0; i < self->M; i++) {
        S[i] = (double *)malloc((self->N + 1) * sizeof(double));
    }
    FinancialModel_simulate_paths(self, S);
    double payoff_sum = 0.0;
    for (int i = 0; i < self->M; i++) {
        double payoff = S[i][self->N] - self->K;
        if (payoff > 0) {
            payoff_sum += payoff;
        }
    }
    double option_price = exp(-self->r * self->T) * (payoff_sum / self->M);
    for (int i = 0; i < self->M; i++) {
        free(S[i]);
    }
    free(S);
    return option_price;
}

void main() {
    double S0 = 100.0;
    double K = 100.0;
    double T = 1.0;
    double r = 0.05;
    double sigma = 0.2;
    int N = 252;
    int M = 10000;
    FinancialModel model;
    FinancialModel_init(&model, S0, K, T, r, sigma, N, M);
    double price = FinancialModel_calculate_option_price(&model);
    printf("Option price: %.4f\n", price);
}