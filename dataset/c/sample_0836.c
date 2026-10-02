#include <stdio.h>
#include <math.h>

typedef struct {
    double price;
    double strike;
    double volatility;
    double rate;
    double time;
} FinancialModel;

double d1(FinancialModel* model) {
    return (log(model->price / model->strike) + (model->rate + 0.5 * model->volatility * model->volatility) * model->time) / (model->volatility * sqrt(model->time));
}

double d2(FinancialModel* model) {
    return d1(model) - model->volatility * sqrt(model->time);
}

double call_price(FinancialModel* model) {
    return model->price * exp(-model->rate * model->time) * cdf(d1(model)) - model->strike * exp(-model->rate * model->time) * cdf(d2(model));
}

double put_price(FinancialModel* model) {
    return model->strike * exp(-model->rate * model->time) * cdf(-d2(model)) - model->price * exp(-model->rate * model->time) * cdf(-d1(model));
}

double cdf(double x) {
    return 0.5 * (1 + erf(x / sqrt(2)));
}

double simulate_pricing(FinancialModel* model, int simulations, int depth) {
    if (depth == 0) {
        return 0;
    }
    double call_value = call_price(model);
    double put_value = put_price(model);
    return call_value + put_value + simulate_pricing(model, simulations, depth - 1);
}

void main() {
    FinancialModel model = {100, 100, 0.2, 0.05, 1};
    int simulations = 1000;
    int depth = 5;
    double total_value = simulate_pricing(&model, simulations, depth);
    printf("Total Estimated Value: %f\n", total_value);
}