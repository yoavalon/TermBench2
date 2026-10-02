#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double simulate_stock_price(int days, double initial_price, double volatility) {
    double price = initial_price;
    double *prices = (double *)malloc((days + 1) * sizeof(double));
    prices[0] = price;
    for (int i = 0; i < days; i++) {
        double random_value = (double)rand() / RAND_MAX;
        double gaussian_value = sqrt(-2 * log(random_value)) * cos(2 * M_PI * ((double)rand() / RAND_MAX));
        price *= 1 + volatility * gaussian_value;
        prices[i + 1] = price;
    }
    double final_price = prices[days];
    free(prices);
    return final_price;
}

double calculate_option_value(double final_price, double strike_price, int days, double risk_free_rate) {
    double payoff = final_price - strike_price > 0 ? final_price - strike_price : 0;
    double discount_factor = 1 / pow(1 + risk_free_rate, days);
    return payoff * discount_factor;
}

int main() {
    int days = 30;
    double initial_price = 100;
    double volatility = 0.2;
    double strike_price = 105;
    double risk_free_rate = 0.05;
    double final_price = simulate_stock_price(days, initial_price, volatility);
    double option_value = calculate_option_value(final_price, strike_price, days, risk_free_rate);
    printf("Option value: %f\n", option_value);
    return 0;
}