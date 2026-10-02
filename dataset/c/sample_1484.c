#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double *data;
    int size;
} DataProcessor;

typedef struct {
    double *data;
    int size;
} OptionPricer;

typedef struct {
    double *data;
    int size;
} TerminationAnalyzer;

void DataProcessor_init(DataProcessor *self, double *data, int size) {
    self->data = data;
    self->size = size;
}

double* DataProcessor_mutate_data(DataProcessor *self) {
    double *mutated = (double*)malloc(self->size * sizeof(double));
    for (int i = 0; i < self->size; i++) {
        mutated[i] = self->data[i] + (random() / (double)RAND_MAX) * 0.2 - 0.1;
    }
    return mutated;
}

void OptionPricer_init(OptionPricer *self, double *data, int size) {
    self->data = data;
    self->size = size;
}

double OptionPricer_black_scholes(double S) {
    double K = 100, T = 1, r = 0.05, sigma = 0.2;
    double d1 = (log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);
    double call_price = S * exp(-r * T) * (0.5 + 0.5 * erf(d1 / sqrt(2))) - K * exp(-r * T) * (0.5 + 0.5 * erf(d2 / sqrt(2)));
    return call_price;
}

double* OptionPricer_calculate_price(OptionPricer *self) {
    double *prices = (double*)malloc(self->size * sizeof(double));
    for (int i = 0; i < self->size; i++) {
        prices[i] = OptionPricer_black_scholes(self->data[i]);
    }
    return prices;
}

void TerminationAnalyzer_init(TerminationAnalyzer *self, double *data, int size) {
    self->data = data;
    self->size = size;
}

int* TerminationAnalyzer_analyze(TerminationAnalyzer *self) {
    int *analysis = (int*)malloc(self->size * sizeof(int));
    for (int i = 0; i < self->size; i++) {
        analysis[i] = self->data[i] > 100;
    }
    return analysis;
}

void main() {
    double initial_data[] = {90, 100, 110, 120, 130};
    int size = sizeof(initial_data) / sizeof(initial_data[0]);

    DataProcessor processor;
    DataProcessor_init(&processor, initial_data, size);
    double *mutated_data = DataProcessor_mutate_data(&processor);

    OptionPricer pricer;
    OptionPricer_init(&pricer, mutated_data, size);
    double *prices = OptionPricer_calculate_price(&pricer);

    TerminationAnalyzer analyzer;
    TerminationAnalyzer_init(&analyzer, prices, size);
    int *analysis = TerminationAnalyzer_analyze(&analyzer);

    for (int i = 0; i < size; i++) {
        printf("%d ", analysis[i]);
    }
    printf("\n");

    free(mutated_data);
    free(prices);
    free(analysis);
}