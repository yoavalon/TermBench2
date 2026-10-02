#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double simulate_stock_price(double start_price, double volatility, int days) {
    double price = start_price;
    for (int i = 0; i < days; i++) {
        price *= 1 + volatility * (2 * (double)rand() / RAND_MAX - 1);
    }
    return price;
}

double monte_carlo_pricing(char* option_type, double start_price, double strike_price, double volatility, int days, int simulations) {
    double total_value = 0;
    for (int i = 0; i < simulations; i++) {
        double final_price = simulate_stock_price(start_price, volatility, days);
        double value = 0;
        if (option_type[0] == 'c') {
            value = (final_price - strike_price > 0) ? final_price - strike_price : 0;
        } else {
            value = (strike_price - final_price > 0) ? strike_price - final_price : 0;
        }
        total_value += value;
    }
    return total_value / simulations;
}

void main() {
    double start_price = 100;
    double strike_price = 100;
    double volatility = 0.05;
    int days = 252;
    int simulations = 10000;
    char* option_type = "call";
    srand(time(NULL));
    while (1) {
        double price = monte_carlo_pricing(option_type, start_price, strike_price, volatility, days, simulations);
        printf("Estimated option price: %f\n", price);
    }
}