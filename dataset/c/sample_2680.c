#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* generate_prices(int num_days, double initial_price, double volatility) {
    double* prices = (double*)malloc(num_days * sizeof(double));
    prices[0] = initial_price;
    for (int i = 1; i < num_days; i++) {
        double change = (double)rand() / RAND_MAX * 2 - 1;
        change *= volatility;
        double new_price = prices[i - 1] * (1 + change);
        prices[i] = new_price;
    }
    return prices;
}

double* calculate_payoffs(double* prices, int num_days, double strike_price, const char* call_or_put) {
    double* payoffs = (double*)malloc(num_days * sizeof(double));
    for (int i = 0; i < num_days; i++) {
        if (strcmp(call_or_put, "call") == 0) {
            payoffs[i] = prices[i] - strike_price > 0 ? prices[i] - strike_price : 0;
        } else {
            payoffs[i] = strike_price - prices[i] > 0 ? strike_price - prices[i] : 0;
        }
    }
    return payoffs;
}

double monte_carlo_pricing(int num_simulations, int num_days, double initial_price, double strike_price, double volatility, const char* call_or_put, double risk_free_rate, double time_to_maturity) {
    double total_payoff = 0;
    for (int i = 0; i < num_simulations; i++) {
        double* prices = generate_prices(num_days, initial_price, volatility);
        double* payoffs = calculate_payoffs(prices, num_days, strike_price, call_or_put);
        double sum_payoffs = 0;
        for (int j = 0; j < num_days; j++) {
            sum_payoffs += payoffs[j];
        }
        double discounted_payoff = sum_payoffs / num_days * pow(1 + risk_free_rate, -time_to_maturity);
        total_payoff += discounted_payoff;
        free(prices);
        free(payoffs);
    }
    return total_payoff / num_simulations;
}

int main() {
    int num_simulations = 1000;
    int num_days = 365;
    double initial_price = 100;
    double strike_price = 100;
    double volatility = 0.2;
    const char* call_or_put = "call";
    double risk_free_rate = 0.05;
    double time_to_maturity = 1;
    double option_price = monte_carlo_pricing(num_simulations, num_days, initial_price, strike_price, volatility, call_or_put, risk_free_rate, time_to_maturity);
    printf("Option price: %f\n", option_price);
    return 0;
}