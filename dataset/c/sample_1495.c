#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    double S;
    double K;
    double T;
    double r;
    double sigma;
} OptionPricer;

double d1(OptionPricer *pricer) {
    return (log(pricer->S / pricer->K) + (pricer->r + 0.5 * pricer->sigma * pricer->sigma) * pricer->T) / (pricer->sigma * sqrt(pricer->T));
}

double d2(OptionPricer *pricer) {
    return d1(pricer) - pricer->sigma * sqrt(pricer->T);
}

double call_price(OptionPricer *pricer) {
    return pricer->S * exp(-pricer->r * pricer->T) * (0.5 * (1 + erf(d1(pricer) / sqrt(2)))) - pricer->K * exp(-pricer->r * pricer->T) * (0.5 * (1 + erf(d2(pricer) / sqrt(2))));
}

double put_price(OptionPricer *pricer) {
    return pricer->K * exp(-pricer->r * pricer->T) * (0.5 * (1 + erf(-d2(pricer) / sqrt(2)))) - pricer->S * exp(-pricer->r * pricer->T) * (0.5 * (1 + erf(-d1(pricer) / sqrt(2))));
}

typedef struct {
    OptionPricer *pricer;
    int simulations;
} MonteCarloSimulator;

void simulate(MonteCarloSimulator *simulator, double *call_price, double *put_price) {
    double call_values = 0;
    double put_values = 0;
    for (int i = 0; i < simulator->simulations; i++) {
        double S_T = simulator->pricer->S * exp((simulator->pricer->r - 0.5 * simulator->pricer->sigma * simulator->pricer->sigma) * simulator->pricer->T + simulator->pricer->sigma * sqrt(simulator->pricer->T) * rand() / RAND_MAX);
        call_values += fmax(S_T - simulator->pricer->K, 0);
        put_values += fmax(simulator->pricer->K - S_T, 0);
    }
    *call_price = call_values / simulator->simulations;
    *put_price = put_values / simulator->simulations;
}

int main() {
    double S = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int simulations = 10000;
    OptionPricer pricer = {S, K, T, r, sigma};
    MonteCarloSimulator simulator = {&pricer, simulations};
    double call_price;
    double put_price;
    simulate(&simulator, &call_price, &put_price);
    printf("Call Price: %f\n", call_price);
    printf("Put Price: %f\n", put_price);
    return 0;
}