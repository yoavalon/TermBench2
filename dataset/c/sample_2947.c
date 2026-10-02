#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    double value;
    double volatility;
    double risk_free_rate;
} FinancialModel;

typedef struct {
    FinancialModel *model;
    double strike_price;
    int maturity;
} OptionPricing;

void FinancialModel_init(FinancialModel *self, double initial_value, double volatility, double risk_free_rate) {
    self->value = initial_value;
    self->volatility = volatility;
    self->risk_free_rate = risk_free_rate;
}

void FinancialModel_simulate(FinancialModel *self) {
    double drift = self->risk_free_rate;
    double diffusion = self->volatility * rand() / (double)RAND_MAX * 2 - 1;
    self->value *= 1 + drift + diffusion;
}

void OptionPricing_init(OptionPricing *self, FinancialModel *model, double strike_price, int maturity) {
    self->model = model;
    self->strike_price = strike_price;
    self->maturity = maturity;
}

double OptionPricing_price(OptionPricing *self) {
    for (int i = 0; i < self->maturity; i++) {
        FinancialModel_simulate(self->model);
    }
    return self->model->value - self->strike_price > 0 ? self->model->value - self->strike_price : 0;
}

int main() {
    srand(time(NULL));
    double initial_value = 100;
    double volatility = 0.2;
    double risk_free_rate = 0.05;
    double strike_price = 105;
    int maturity = 1000;
    FinancialModel model;
    OptionPricing pricing;
    FinancialModel_init(&model, initial_value, volatility, risk_free_rate);
    OptionPricing_init(&pricing, &model, strike_price, maturity);
    while (1) {
        double price = OptionPricing_price(&pricing);
        printf("Option price: %f\n", price);
        model.value = initial_value;
    }
    return 0;
}