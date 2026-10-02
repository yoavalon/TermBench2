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
    FinancialModel* model;
} OptionPricer;

double** simulate_price_paths(FinancialModel* model) {
    double dt = model->T / model->N;
    double** paths = (double**)malloc((model->N + 1) * sizeof(double*));
    paths[0] = (double*)malloc(sizeof(double));
    paths[0][0] = model->S0;
    for (int i = 1; i <= model->N; i++) {
        double** new_paths = (double**)malloc((model->N + 1) * sizeof(double*));
        for (int j = 0; j <= i - 1; j++) {
            double S = paths[j][i - 1];
            double dW = sqrt(dt) * ((double)rand() / RAND_MAX - 0.5);
            double new_S = S * exp((model->r - 0.5 * model->sigma * model->sigma) * dt + model->sigma * dW);
            new_paths[j] = (double*)malloc((i + 1) * sizeof(double));
            for (int k = 0; k <= i - 1; k++) {
                new_paths[j][k] = paths[j][k];
            }
            new_paths[j][i] = new_S;
        }
        for (int j = 0; j <= i - 1; j++) {
            free(paths[j]);
        }
        free(paths);
        paths = new_paths;
    }
    return paths;
}

double payoff(OptionPricer* pricer, double* price_path) {
    return fmax(pricer->model->K - price_path[pricer->model->N], 0);
}

double price_option(OptionPricer* pricer) {
    double** paths = simulate_price_paths(pricer->model);
    double sum_discounted_payoffs = 0;
    for (int i = 0; i <= pricer->model->N; i++) {
        sum_discounted_payoffs += payoff(pricer, paths[i]) * exp(-pricer->model->r * pricer->model->T);
    }
    double option_price = sum_discounted_payoffs / (pricer->model->N + 1);
    for (int i = 0; i <= pricer->model->N; i++) {
        free(paths[i]);
    }
    free(paths);
    return option_price;
}

int main() {
    srand(time(NULL));
    FinancialModel model = {100, 100, 1, 0.05, 0.2, 100};
    OptionPricer pricer = {&model};
    double option_price = price_option(&pricer);
    printf("Option Price: %f\n", option_price);
    return 0;
}