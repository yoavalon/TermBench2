c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double S0;
    double sigma;
    double r;
    double K;
    double T;
} FinancialModel;

FinancialModel* FinancialModel_init(double initial_price, double volatility, double risk_free_rate, double strike_price, double maturity) {
    FinancialModel* model = (FinancialModel*)malloc(sizeof(FinancialModel));
    model->S0 = initial_price;
    model->sigma = volatility;
    model->r = risk_free_rate;
    model->K = strike_price;
    model->T = maturity;
    return model;
}

double** FinancialModel_simulate_paths(FinancialModel* model, int num_paths, int num_steps) {
    double dt = model->T / num_steps;
    double** paths = (double**)malloc(num_paths * sizeof(double*));
    for (int i = 0; i < num_paths; i++) {
        paths[i] = (double*)malloc((num_steps + 1) * sizeof(double));
        paths[i][0] = model->S0;
    }
    for (int step = 0; step < num_steps; step++) {
        for (int path = 0; path < num_paths; path++) {
            double Z = (double)rand() / RAND_MAX * 2 - 1;
            double S_next = paths[path][step] * exp((model->r - 0.5 * model->sigma * model->sigma) * dt + model->sigma * sqrt(dt) * Z);
            paths[path][step + 1] = S_next;
        }
    }
    return paths;
}

typedef struct {
    FinancialModel* model;
    int num_paths;
    int num_steps;
} OptionPricing;

OptionPricing* OptionPricing_init(FinancialModel* model, int num_paths, int num_steps) {
    OptionPricing* pricing = (OptionPricing*)malloc(sizeof(OptionPricing));
    pricing->model = model;
    pricing->num_paths = num_paths;
    pricing->num_steps = num_steps;
    return pricing;
}

double OptionPricing_calculate_option_value(OptionPricing* pricing) {
    double** paths = FinancialModel_simulate_paths(pricing->model, pricing->num_paths, pricing->num_steps);
    double option_values = 0;
    for (int path = 0; path < pricing->num_paths; path++) {
        double payoff = paths[path][pricing->num_steps] - pricing->model->K;
        if (payoff > 0) {
            option_values += payoff;
        }
    }
    for (int i = 0; i < pricing->num_paths; i++) {
        free(paths[i]);
    }
    free(paths);
    return option_values / pricing->num_paths * exp(-pricing->model->r * pricing->model->T);
}

int main() {
    double initial_price = 100;
    double volatility = 0.2;
    double risk_free_rate = 0.05;
    double strike_price = 100;
    double maturity = 1;
    int num_paths = 1000;
    int num_steps = 100;
    FinancialModel* model = FinancialModel_init(initial_price, volatility, risk_free_rate, strike_price, maturity);
    OptionPricing* option_pricing = OptionPricing_init(model, num_paths, num_steps);
    double value = OptionPricing_calculate_option_value(option_pricing);
    printf("Option Value: %f\n", value);
    free(option_pricing);
    free(model);
    return 0;
}