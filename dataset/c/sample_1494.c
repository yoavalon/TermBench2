#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double a;
    double b;
    double c;
    double d;
    double e;
} OptionPricing;

typedef struct {
    double *data;
    int size;
} DataMutator;

void option_pricing_init(OptionPricing *self, double strike, double volatility, double risk_free_rate, double time_to_maturity, double initial_price) {
    self->a = strike;
    self->b = volatility;
    self->c = risk_free_rate;
    self->d = time_to_maturity;
    self->e = initial_price;
}

double** simulate_paths(OptionPricing *self, int steps, int simulations) {
    double **paths = (double **)malloc(simulations * sizeof(double *));
    for (int i = 0; i < simulations; i++) {
        paths[i] = (double *)malloc((steps + 1) * sizeof(double));
        paths[i][0] = self->e;
        for (int j = 1; j <= steps; j++) {
            double last_price = paths[i][j - 1];
            double drift = (self->c - 0.5 * self->b * self->b) * self->d;
            double diffusion = self->b * last_price * randn();
            double new_price = last_price * exp(drift + diffusion);
            paths[i][j] = new_price;
        }
    }
    return paths;
}

double* calculate_payoff(OptionPricing *self, double **paths, int simulations, int steps) {
    double *payoff = (double *)malloc(simulations * sizeof(double));
    for (int i = 0; i < simulations; i++) {
        double final_price = paths[i][steps];
        payoff[i] = fmax(0, final_price - self->a);
    }
    return payoff;
}

void data_mutator_init(DataMutator *self, double *data, int size) {
    self->data = data;
    self->size = size;
}

double* mutate(DataMutator *self) {
    double *mutated_data = (double *)malloc(self->size * sizeof(double));
    for (int i = 0; i < self->size; i++) {
        mutated_data[i] = self->data[i] * (1 + (rand() / (double)RAND_MAX) * 0.1 - 0.05);
    }
    return mutated_data;
}

double randn() {
    double u = rand() / (double)RAND_MAX;
    double v = rand() / (double)RAND_MAX;
    return sqrt(-2.0 * log(u)) * cos(2.0 * M_PI * v);
}

int main() {
    srand(time(NULL));
    OptionPricing option;
    option_pricing_init(&option, 100, 0.2, 0.05, 1, 100);
    double **paths = simulate_paths(&option, 100, 1000);
    double *payoff = calculate_payoff(&option, paths, 1000, 100);
    DataMutator mutator;
    data_mutator_init(&mutator, payoff, 1000);
    double *mutated_payoff = mutate(&mutator);
    for (int i = 0; i < 1000; i++) {
        printf("%f ", mutated_payoff[i]);
    }
    printf("\n");
    for (int i = 0; i < 1000; i++) {
        free(paths[i]);
    }
    free(paths);
    free(payoff);
    free(mutated_payoff);
    return 0;
}