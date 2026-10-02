#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* simulate_prices(double base_price, double volatility, int days) {
    double* prices = (double*)malloc(days * sizeof(double));
    prices[0] = base_price;
    for (int i = 1; i < days; i++) {
        double daily_return = (double)rand() / RAND_MAX * 2 * volatility - volatility;
        prices[i] = prices[i - 1] * (1 + daily_return);
    }
    return prices;
}

double calculate_option_premium(double* prices, double strike_price, int days) {
    double option_values = 0;
    for (int i = 0; i < days; i++) {
        option_values += (prices[i] - strike_price) > 0 ? (prices[i] - strike_price) : 0;
    }
    return option_values * 365 / days;
}

int main() {
    double base_price = 100;
    double volatility = 0.2;
    int days = 365;
    double strike_price = 100;
    while (1) {
        double* prices = simulate_prices(base_price, volatility, days);
        double premium = calculate_option_premium(prices, strike_price, days);
        printf("Calculated option premium: %f\n", premium);
        free(prices);
    }
    return 0;
}