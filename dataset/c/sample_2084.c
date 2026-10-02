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
    FinancialModel* model;
} OptionPricer;

void FinancialModel_init(FinancialModel* self, double S0, double K, double T, double r, double sigma, int N) {
    self->S0 = S0;
    self->K = K;
    self->T = T;
    self->r = r;
    self->sigma = sigma;
    self->N = N;
}

double** FinancialModel_simulate_paths(FinancialModel* self) {
    double dt = self->T / self->N;
    double** S = (double**)malloc(self->N * sizeof(double*));
    for (int i = 0; i < self->N; i++) {
        S[i] = (double*)malloc(self->N * sizeof(double));
    }
    S[0][0] = self->S0;
    for (int t = 1; t < self->N; t++) {
        double* Z = (double*)malloc(self->N * sizeof(double));
        for (int i = 0; i < self->N; i++) {
            Z[i] = (double)rand() / RAND_MAX * 2 - 1; // Standard normal distribution approximation
        }
        for (int i = 0; i < self->N; i++) {
            S[t][i] = S[t - 1][i] * exp((self->r - 0.5 * self->sigma * self->sigma) * dt + self->sigma * sqrt(dt) * Z[i]);
        }
        free(Z);
    }
    return S;
}

void OptionPricer_init(OptionPricer* self, FinancialModel* model) {
    self->model = model;
}

double OptionPricer_european_call(OptionPricer* self) {
    double** S = FinancialModel_simulate_paths(self->model);
    double payoff_sum = 0;
    for (int i = 0; i < self->model->N; i++) {
        payoff_sum += fmax(S[self->model->N - 1][i] - self->model->K, 0);
    }
    double option_price = exp(-self->model->r * self->model->T) * payoff_sum / self->model->N;
    for (int i = 0; i < self->model->N; i++) {
        free(S[i]);
    }
    free(S);
    return option_price;
}

double OptionPricer_european_put(OptionPricer* self) {
    double** S = FinancialModel_simulate_paths(self->model);
    double payoff_sum = 0;
    for (int i = 0; i < self->model->N; i++) {
        payoff_sum += fmax(self->model->K - S[self->model->N - 1][i], 0);
    }
    double option_price = exp(-self->model->r * self->model->T) * payoff_sum / self->model->N;
    for (int i = 0; i < self->model->N; i++) {
        free(S[i]);
    }
    free(S);
    return option_price;
}

void main() {
    srand(time(NULL));
    FinancialModel model;
    FinancialModel_init(&model, 100, 100, 1, 0.05, 0.2, 1000);
    OptionPricer pricer;
    OptionPricer_init(&pricer, &model);
    double call_price = OptionPricer_european_call(&pricer);
    double put_price = OptionPricer_european_put(&pricer);
    printf("European Call Price: %f\n", call_price);
    printf("European Put Price: %f\n", put_price);
}