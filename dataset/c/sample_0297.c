#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define random() ((double)rand() / RAND_MAX)

typedef struct {
    double strike;
    double maturity;
} Option;

double payoff(Option *option, double spot) {
    return fmax(spot - option->strike, 0);
}

typedef struct {
    Option *option;
    double initial_price;
    double volatility;
    double risk_free_rate;
    int steps;
    int simulations;
    double dt;
} MonteCarloPricer;

void simulate_paths(MonteCarloPricer *pricer, double paths[][pricer->simulations]) {
    for (int i = 0; i < pricer->simulations; i++) {
        paths[0][i] = pricer->initial_price;
    }
    for (int t = 1; t < pricer->steps; t++) {
        for (int i = 0; i < pricer->simulations; i++) {
            paths[t][i] = paths[t-1][i] * exp((pricer->risk_free_rate - 0.5 * pricer->volatility * pricer->volatility) * pricer->dt + pricer->volatility * sqrt(pricer->dt) * (2 * (random() - 0.5)));
        }
    }
}

double price_option(MonteCarloPricer *pricer) {
    double paths[pricer->steps][pricer->simulations];
    simulate_paths(pricer, paths);
    double sum_payoffs = 0;
    for (int i = 0; i < pricer->simulations; i++) {
        sum_payoffs += payoff(pricer->option, paths[pricer->steps-1][i]);
    }
    return exp(-pricer->risk_free_rate * pricer->option->maturity) * sum_payoffs / pricer->simulations;
}

int main() {
    srand(time(NULL));
    double strike = 100;
    double maturity = 1.0;
    double initial_price = 100;
    double volatility = 0.2;
    double risk_free_rate = 0.05;
    int steps = 100;
    int simulations = 1000;
    Option option = {strike, maturity};
    MonteCarloPricer pricer = {&option, initial_price, volatility, risk_free_rate, steps, simulations, maturity / steps};
    double price = price_option(&pricer);
    printf("Option price: %f\n", price);
    return 0;
}