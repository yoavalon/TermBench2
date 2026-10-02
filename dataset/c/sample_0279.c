#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double price;
    double volatility;
    double strike;
    double rate;
    double tau;
} FinancialModel;

typedef struct {
    double lower;
    double upper;
    double threshold;
    int max_steps;
} BoundaryConditions;

void FinancialModel_init(FinancialModel *model, double initial_price, double volatility, double strike_price, double risk_free_rate, double time_to_maturity) {
    model->price = initial_price;
    model->volatility = volatility;
    model->strike = strike_price;
    model->rate = risk_free_rate;
    model->tau = time_to_maturity;
}

void FinancialModel_simulate_step(FinancialModel *model) {
    double dW = ((double)rand() / RAND_MAX) * 2 - 1;
    double dS = model->price * model->volatility * dW * sqrt(model->tau);
    model->price += dS;
}

double FinancialModel_calculate_option_value(FinancialModel *model) {
    return model->price - model->strike > 0 ? model->price - model->strike : 0;
}

void BoundaryConditions_init(BoundaryConditions *conditions, double lower_bound, double upper_bound, double threshold, int max_steps) {
    conditions->lower = lower_bound;
    conditions->upper = upper_bound;
    conditions->threshold = threshold;
    conditions->max_steps = max_steps;
}

int BoundaryConditions_check_conditions(BoundaryConditions *conditions, double price, int step_count) {
    if (step_count >= conditions->max_steps || price <= conditions->lower || price >= conditions->upper) {
        return 1;
    }
    return 0;
}

int main() {
    double initial_price = 100;
    double volatility = 0.2;
    double strike_price = 100;
    double risk_free_rate = 0.05;
    double time_to_maturity = 1;
    double lower_bound = 80;
    double upper_bound = 120;
    double threshold = 0.01;
    int max_steps = 1000;
    FinancialModel financial_model;
    BoundaryConditions boundary_conditions;
    int step_count = 0;

    FinancialModel_init(&financial_model, initial_price, volatility, strike_price, risk_free_rate, time_to_maturity);
    BoundaryConditions_init(&boundary_conditions, lower_bound, upper_bound, threshold, max_steps);

    while (!BoundaryConditions_check_conditions(&boundary_conditions, financial_model.price, step_count)) {
        FinancialModel_simulate_step(&financial_model);
        step_count++;
    }

    double option_value = FinancialModel_calculate_option_value(&financial_model);
    printf("Option Value: %f\n", option_value);

    return 0;
}