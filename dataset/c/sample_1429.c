#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double *data;
    int size;
} DataMutation;

void DataMutation_init(DataMutation *self, double *data, int size) {
    self->data = data;
    self->size = size;
}

double* DataMutation_apply_mutation(DataMutation *self, double (*mutation_function)(double*, int)) {
    self->data = mutation_function(self->data, self->size);
    return self->data;
}

typedef struct {
    double initial_price;
    double volatility;
    double risk_free_rate;
    int time_steps;
    int simulations;
} FinancialModel;

void FinancialModel_init(FinancialModel *self, double initial_price, double volatility, double risk_free_rate, int time_steps, int simulations) {
    self->initial_price = initial_price;
    self->volatility = volatility;
    self->risk_free_rate = risk_free_rate;
    self->time_steps = time_steps;
    self->simulations = simulations;
}

double** FinancialModel_simulate_paths(FinancialModel *self) {
    double dt = 1.0 / self->time_steps;
    double drift = (self->risk_free_rate - 0.5 * self->volatility * self->volatility) * dt;
    double diffusion = self->volatility * sqrt(dt);
    double **paths = (double**)malloc((self->time_steps + 1) * sizeof(double*));
    for (int i = 0; i <= self->time_steps; i++) {
        paths[i] = (double*)malloc(self->simulations * sizeof(double));
    }
    for (int i = 0; i < self->simulations; i++) {
        paths[0][i] = self->initial_price;
    }
    for (int t = 1; t <= self->time_steps; t++) {
        for (int i = 0; i < self->simulations; i++) {
            double rand = ((double)rand() / RAND_MAX) * 2 - 1;
            paths[t][i] = paths[t - 1][i] * exp(drift + diffusion * rand);
        }
    }
    return paths;
}

double* FinancialModel_calculate_payoff(FinancialModel *self, double strike_price, const char *option_type) {
    double **paths = FinancialModel_simulate_paths(self);
    double *payoff = (double*)malloc(self->simulations * sizeof(double));
    if (strcmp(option_type, "call") == 0) {
        for (int i = 0; i < self->simulations; i++) {
            payoff[i] = paths[self->time_steps][i] > strike_price ? paths[self->time_steps][i] - strike_price : 0;
        }
    } else if (strcmp(option_type, "put") == 0) {
        for (int i = 0; i < self->simulations; i++) {
            payoff[i] = strike_price > paths[self->time_steps][i] ? strike_price - paths[self->time_steps][i] : 0;
        }
    }
    for (int i = 0; i <= self->time_steps; i++) {
        free(paths[i]);
    }
    free(paths);
    return payoff;
}

double FinancialModel_price_option(FinancialModel *self, double strike_price, const char *option_type) {
    double *payoff = FinancialModel_calculate_payoff(self, strike_price, option_type);
    double sum = 0;
    for (int i = 0; i < self->simulations; i++) {
        sum += payoff[i];
    }
    double option_price = exp(-self->risk_free_rate * self->time_steps) * (sum / self->simulations);
    free(payoff);
    return option_price;
}

double* mutation_function(double *data, int size) {
    for (int i = 0; i < size; i++) {
        data[i] *= 2;
    }
    return data;
}

int main() {
    double *data = (double*)malloc(100 * sizeof(double));
    for (int i = 0; i < 100; i++) {
        data[i] = ((double)rand() / RAND_MAX);
    }
    DataMutation data_mutator;
    DataMutation_init(&data_mutator, data, 100);
    data = DataMutation_apply_mutation(&data_mutator, mutation_function);
    FinancialModel financial_model;
    FinancialModel_init(&financial_model, data[0], 0.2, 0.05, 252, 10000);
    double option_price = FinancialModel_price_option(&financial_model, 100, "call");
    printf("%f\n", option_price);
    free(data);
    return 0;
}