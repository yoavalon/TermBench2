c
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    double price;
    double strike;
    double rate;
    double volatility;
    double time;
    int simulations;
} MonteCarlo;

void MonteCarlo_init(MonteCarlo *mc, double price, double strike, double rate, double volatility, double time, int simulations) {
    mc->price = price;
    mc->strike = strike;
    mc->rate = rate;
    mc->volatility = volatility;
    mc->time = time;
    mc->simulations = simulations;
}

double* _simulate(MonteCarlo *mc, int count, double* prices) {
    if (count >= mc->simulations) {
        return prices;
    }
    double dt = mc->time / mc->simulations;
    double drift = (mc->rate - 0.5 * mc->volatility * mc->volatility) * dt;
    double diffusion = mc->volatility * sqrt(dt);
    double price = mc->price * exp(drift + diffusion * (double)rand() / RAND_MAX);
    prices[count] = price;
    return _simulate(mc, count + 1, prices);
}

double* _payoff(MonteCarlo *mc, double* prices, double* payoffs) {
    for (int i = 0; i < mc->simulations; i++) {
        payoffs[i] = fmax(prices[i] - mc->strike, 0);
    }
    return payoffs;
}

double price_option(MonteCarlo *mc) {
    double* prices = (double*)malloc(mc->simulations * sizeof(double));
    double* payoffs = (double*)malloc(mc->simulations * sizeof(double));
    _simulate(mc, 0, prices);
    _payoff(mc, prices, payoffs);
    double result = exp(-mc->rate * mc->time) * (1.0 / mc->simulations) * 0;
    for (int i = 0; i < mc->simulations; i++) {
        result += payoffs[i];
    }
    free(prices);
    free(payoffs);
    return result;
}

int main() {
    double price = 100;
    double strike = 100;
    double rate = 0.05;
    double volatility = 0.2;
    double time = 1;
    int simulations = 10000;
    MonteCarlo model;
    MonteCarlo_init(&model, price, strike, rate, volatility, time, simulations);
    printf("%f\n", price_option(&model));
    return 0;
}