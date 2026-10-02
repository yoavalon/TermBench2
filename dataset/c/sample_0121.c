#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double simulate_stock_price(double start, double volatility, int days) {
    double prices[days + 1];
    prices[0] = start;
    for (int i = 0; i < days; i++) {
        double price_change = (double)rand() / RAND_MAX * 2 - 1;
        double new_price = prices[i] * (1 + price_change * volatility);
        prices[i + 1] = new_price;
    }
    return prices[days];
}

double calculate_option_value(double final_price, double strike, int days, double risk_free_rate) {
    double payoff = final_price - strike > 0 ? final_price - strike : 0;
    return payoff / pow(1 + risk_free_rate, days);
}

int main() {
    double start_price = 100;
    double volatility = 0.2;
    double strike_price = 105;
    int days = 30;
    double risk_free_rate = 0.05;
    int iterations = 1000;
    double total_value = 0;
    for (int i = 0; i < iterations; i++) {
        double final_price = simulate_stock_price(start_price, volatility, days);
        double option_value = calculate_option_value(final_price, strike_price, days, risk_free_rate);
        total_value += option_value;
    }
    double average_value = total_value / iterations;
    printf("%f\n", average_value);
    return 0;
}