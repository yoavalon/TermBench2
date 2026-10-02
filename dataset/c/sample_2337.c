#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double initial_value;
    double mu;
    double sigma;
} Params;

typedef struct {
    Params params;
} FinancialModel;

typedef struct {
    FinancialModel *model;
} OptionPricer;

double random_normalvariate(double mu, double sigma) {
    double u1, u2;
    do {
        u1 = (double)rand() / RAND_MAX;
        u2 = (double)rand() / RAND_MAX;
    } while (u1 <= 1e-7);
    return mu + sigma * sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
}

void FinancialModel_init(FinancialModel *self, Params params) {
    self->params = params;
}

void FinancialModel_simulate(FinancialModel *self, int steps, double *data) {
    double current_value = self->params.initial_value;
    for (int i = 0; i < steps; i++) {
        current_value *= 1 + random_normalvariate(self->params.mu, self->params.sigma);
        data[i] = current_value;
    }
}

void OptionPricer_init(OptionPricer *self, FinancialModel *model) {
    self->model = model;
}

void OptionPricer_price_option(OptionPricer *self, int steps, double *strikes, int num_strikes, double *prices) {
    double simulations[steps];
    FinancialModel_simulate(self->model, steps, simulations);
    for (int j = 0; j < num_strikes; j++) {
        double payoff = 0;
        for (int i = 0; i < steps; i++) {
            payoff += fmax(simulations[i] - strikes[j], 0);
        }
        prices[j] = payoff / steps;
    }
}

int main() {
    Params params = {100.0, 0.01, 0.05};
    FinancialModel model;
    OptionPricer pricer;
    FinancialModel_init(&model, params);
    OptionPricer_init(&pricer, &model);
    double strikes[] = {90, 100, 110};
    double result[3];
    while (1) {
        OptionPricer_price_option(&pricer, 1000, strikes, 3, result);
        for (int i = 0; i < 3; i++) {
            printf("%f ", result[i]);
        }
        printf("\n");
    }
    return 0;
}