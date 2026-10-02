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
} FinancialModel;

typedef struct {
    FinancialModel *model;
} OptionPricer;

void FinancialModel_init(FinancialModel *model, double S0, double K, double T, double r, double sigma, int N) {
    model->S0 = S0;
    model->K = K;
    model->T = T;
    model->r = r;
    model->sigma = sigma;
    model->N = N;
}

double** FinancialModel_simulate_paths(FinancialModel *model) {
    double **paths = (double **)malloc(model->N * sizeof(double *));
    for (int i = 0; i < model->N; i++) {
        paths[i] = (double *)malloc((model->T * 252 + 1) * sizeof(double));
        paths[i][0] = model->S0;
        for (int j = 1; j <= model->T * 252; j++) {
            double S_next = paths[i][j - 1] * (1 + randn() * model->sigma * sqrt(1 / 252));
            paths[i][j] = S_next;
        }
    }
    return paths;
}

double* FinancialModel_calculate_payoffs(FinancialModel *model, double **paths) {
    double *payoffs = (double *)malloc(model->N * sizeof(double));
    for (int i = 0; i < model->N; i++) {
        double payoff = fmax(0, paths[i][model->T * 252] - model->K);
        payoffs[i] = payoff;
    }
    return payoffs;
}

void OptionPricer_init(OptionPricer *pricer, FinancialModel *model) {
    pricer->model = model;
}

double OptionPricer_price_option(OptionPricer *pricer) {
    double **paths = FinancialModel_simulate_paths(pricer->model);
    double *payoffs = FinancialModel_calculate_payoffs(pricer->model, paths);
    double sum_discounted_payoffs = 0;
    for (int i = 0; i < pricer->model->N; i++) {
        sum_discounted_payoffs += payoffs[i] * exp(-pricer->model->r);
    }
    free(payoffs);
    for (int i = 0; i < pricer->model->N; i++) {
        free(paths[i]);
    }
    free(paths);
    return sum_discounted_payoffs / pricer->model->N;
}

double randn() {
    double u1 = (double)rand() / RAND_MAX;
    double u2 = (double)rand() / RAND_MAX;
    return sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
}

int main() {
    double S0 = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 10000;
    FinancialModel model;
    FinancialModel_init(&model, S0, K, T, r, sigma, N);
    OptionPricer pricer;
    OptionPricer_init(&pricer, &model);
    double option_price = OptionPricer_price_option(&pricer);
    printf("Option Price: %f\n", option_price);
    return 0;
}