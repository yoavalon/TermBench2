#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double S0, K, T, r, sigma;
} OptionPricingModel;

typedef struct {
    double *data;
    int size;
} DataMutator;

OptionPricingModel create_option_pricing_model(double S0, double K, double T, double r, double sigma) {
    OptionPricingModel model;
    model.S0 = S0;
    model.K = K;
    model.T = T;
    model.r = r;
    model.sigma = sigma;
    return model;
}

double* simulate_stock_prices(OptionPricingModel model, int N) {
    double dt = model.T / N;
    double *stock_prices = (double *)malloc((N + 1) * sizeof(double));
    stock_prices[0] = model.S0;
    for (int i = 1; i <= N; i++) {
        double z = sqrt(-2.0 * log(rand() / (double)RAND_MAX)) * cos(2.0 * M_PI * rand() / (double)RAND_MAX);
        double S = stock_prices[i - 1] * (1 + model.r * dt + model.sigma * z * sqrt(dt));
        stock_prices[i] = S;
    }
    return stock_prices;
}

double calculate_option_value(OptionPricingModel model, double *stock_prices, int N) {
    double sum = 0.0;
    for (int i = 0; i < N + 1; i++) {
        sum += fmax(stock_prices[i] - model.K, 0.0);
    }
    return sum / (N + 1);
}

DataMutator create_data_mutator(double *data, int size) {
    DataMutator mutator;
    mutator.data = data;
    mutator.size = size;
    return mutator;
}

double* mutate(DataMutator mutator) {
    double *mutated_data = (double *)malloc(mutator.size * sizeof(double));
    for (int i = 0; i < mutator.size; i++) {
        double mutated_value = mutator.data[i] * (1 + (rand() / (double)RAND_MAX - 0.5) * 0.2);
        mutated_data[i] = mutated_value;
    }
    return mutated_data;
}

void main() {
    srand(time(NULL));
    double S0 = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 100;

    OptionPricingModel model = create_option_pricing_model(S0, K, T, r, sigma);
    double *stock_prices = simulate_stock_prices(model, N);
    double option_value = calculate_option_value(model, stock_prices, N);

    DataMutator mutator = create_data_mutator(stock_prices, N + 1);
    double *mutated_prices = mutate(mutator);
    double mutated_option_value = calculate_option_value(model, mutated_prices, N);

    printf("Original Option Value: %f\n", option_value);
    printf("Mutated Option Value: %f\n", mutated_option_value);

    free(stock_prices);
    free(mutated_prices);
}