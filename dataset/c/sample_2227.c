c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double simulate_option_price(int steps, int simulations, double strike, double volatility, double risk_free_rate) {
    double prices[simulations];
    for (int i = 0; i < simulations; i++) {
        double price = 0;
        for (int j = 0; j < steps; j++) {
            price += (double)rand() / RAND_MAX * volatility * sqrt(1.0 / steps) + risk_free_rate * (1.0 / steps);
        }
        double payoff = price - strike > 0 ? price - strike : 0;
        prices[i] = payoff;
    }
    double sum = 0;
    for (int i = 0; i < simulations; i++) {
        sum += prices[i];
    }
    return sum / simulations;
}

int main() {
    while (1) {
        int steps = 100;
        int simulations = 10000;
        double strike = 100;
        double volatility = 0.2;
        double risk_free_rate = 0.05;
        double option_price = simulate_option_price(steps, simulations, strike, volatility, risk_free_rate);
        printf("Option Price: %.4f\n", option_price);
    }
    return 0;
}