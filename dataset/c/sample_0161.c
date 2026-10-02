#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double simulate_stock_price(int steps, double initial_price, double drift, double volatility) {
    double price = initial_price;
    for (int i = 0; i < steps; i++) {
        double gauss = ((double)rand() / RAND_MAX - 0.5) * 2 * sqrt(3);
        price += price * (drift + volatility * gauss);
    }
    return price;
}

double price_option(double (*pricing_function)(int, double, double, double), double initial_price, double strike_price, int steps, double drift, double volatility, int simulations) {
    double total = 0;
    for (int i = 0; i < simulations; i++) {
        double final_price = pricing_function(steps, initial_price, drift, volatility);
        double payoff = final_price - strike_price > 0 ? final_price - strike_price : 0;
        total += payoff;
    }
    return total / simulations;
}

int main() {
    srand(time(NULL));
    double initial_price = 100;
    double strike_price = 100;
    int steps = 100;
    double drift = 0.0001;
    double volatility = 0.01;
    int simulations = 10000;
    double option_price = price_option(simulate_stock_price, initial_price, strike_price, steps, drift, volatility, simulations);
    printf("Option Price: %f\n", option_price);
    return 0;
}