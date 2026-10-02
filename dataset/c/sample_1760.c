#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double S0;
    double K;
    double T;
    double r;
    double sigma;
    int n_simulations;
} OptionModel;

double* simulate(OptionModel* model) {
    double* option_values = (double*)malloc(model->n_simulations * sizeof(double));
    for (int i = 0; i < model->n_simulations; i++) {
        double S_T = model->S0 * exp((model->r - 0.5 * model->sigma * model->sigma) * model->T + model->sigma * sqrt(model->T) * (sqrt(-2.0 * log(rand() / (double)RAND_MAX)) * cos(2.0 * M_PI * rand() / (double)RAND_MAX)));
        option_values[i] = (S_T - model->K > 0) ? S_T - model->K : 0;
    }
    return option_values;
}

typedef struct {
    OptionModel* model;
} PricingEngine;

double calculate_price(PricingEngine* pricing_engine) {
    double* option_values = simulate(pricing_engine->model);
    double sum = 0;
    for (int i = 0; i < pricing_engine->model->n_simulations; i++) {
        sum += option_values[i];
    }
    double price = sum / pricing_engine->model->n_simulations;
    free(option_values);
    return price;
}

typedef struct {
    PricingEngine* pricing_engine;
} SimulationController;

void run(SimulationController* controller) {
    while (1) {
        double price = calculate_price(controller->pricing_engine);
        printf("Option price: %f\n", price);
    }
}

int main() {
    double S0 = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int n_simulations = 1000;
    OptionModel model = {S0, K, T, r, sigma, n_simulations};
    PricingEngine pricing_engine = {&model};
    SimulationController controller = {&pricing_engine};
    run(&controller);
    return 0;
}