#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M_PI 3.14159265358979323846

typedef struct {
    double *S0;
    double K;
    double T;
    double r;
    double sigma;
    int N;
    double dt;
} FinancialModel;

typedef struct {
    FinancialModel *financial_model;
    int M;
} OptionPricer;

FinancialModel* FinancialModel_init(double *S0, double K, double T, double r, double sigma, int N) {
    FinancialModel *self = (FinancialModel*)malloc(sizeof(FinancialModel));
    self->S0 = S0;
    self->K = K;
    self->T = T;
    self->r = r;
    self->sigma = sigma;
    self->N = N;
    self->dt = T / N;
    return self;
}

double** FinancialModel_simulate_paths(FinancialModel *self) {
    double **paths = (double**)malloc((self->N + 1) * sizeof(double*));
    for (int i = 0; i <= self->N; i++) {
        paths[i] = (double*)malloc((self->N + 1) * sizeof(double));
    }
    for (int i = 0; i < self->N + 1; i++) {
        paths[0][i] = self->S0[i];
    }
    for (int t = 1; t <= self->N; t++) {
        double *z = (double*)malloc(self->N * sizeof(double));
        for (int i = 0; i < self->N; i++) {
            z[i] = sqrt(-2.0 * log((double)rand() / (double)RAND_MAX)) * cos(2 * M_PI * (double)rand() / (double)RAND_MAX);
        }
        for (int i = 0; i < self->N + 1; i++) {
            paths[t][i] = paths[t - 1][i] * exp((self->r - 0.5 * self->sigma * self->sigma) * self->dt + self->sigma * sqrt(self->dt) * z[i]);
        }
        free(z);
    }
    return paths;
}

double* FinancialModel_payoff(FinancialModel *self, double **paths) {
    double *payoff = (double*)malloc((self->N + 1) * sizeof(double));
    for (int i = 0; i < self->N + 1; i++) {
        payoff[i] = fmax(paths[self->N][i] - self->K, 0);
    }
    return payoff;
}

OptionPricer* OptionPricer_init(FinancialModel *financial_model, int M) {
    OptionPricer *self = (OptionPricer*)malloc(sizeof(OptionPricer));
    self->financial_model = financial_model;
    self->M = M;
    return self;
}

double OptionPricer_price_option(OptionPricer *self) {
    double *payoffs = (double*)malloc(self->M * sizeof(double));
    for (int i = 0; i < self->M; i++) {
        double **paths = FinancialModel_simulate_paths(self->financial_model);
        double *payoff = FinancialModel_payoff(self->financial_model, paths);
        payoffs[i] = payoff[self->financial_model->N];
        free(payoff);
        for (int j = 0; j <= self->financial_model->N; j++) {
            free(paths[j]);
        }
        free(paths);
    }
    double option_price = exp(-self->financial_model->r * self->financial_model->T) * 0.0;
    for (int i = 0; i < self->M; i++) {
        option_price += payoffs[i];
    }
    option_price /= self->M;
    free(payoffs);
    return option_price;
}

void main() {
    double S0[] = {100, 100, 100};
    double K = 100;
    double T = 1.0;
    double r = 0.05;
    double sigma = 0.2;
    int N = 100;
    int M = 10000;
    FinancialModel *financial_model = FinancialModel_init(S0, K, T, r, sigma, N);
    OptionPricer *option_pricer = OptionPricer_init(financial_model, M);
    printf("%f\n", OptionPricer_price_option(option_pricer));
}