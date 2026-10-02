#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979323846

double norm_cdf(double x) {
    double t = 1 / (1 + 0.5 * fabs(x));
    double poly = t * (0.31938153 + t * (-0.356563782 + t * (1.781477937 + t * (-1.821255978 + t * 1.330274429))));
    return 0.5 + copysign(0.5, x) * exp(-0.5 * x * x) * poly;
}

typedef struct {
    double strike;
    double spot;
    double vol;
    double rate;
    double div;
    double T;
} OptionPricer;

double OptionPricer_d1(OptionPricer* self, double S, double K, double T, double r, double q, double sigma) {
    return (log(S / K) + (r - q + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
}

double OptionPricer_d2(OptionPricer* self, double d1, double sigma, double T) {
    return d1 - sigma * sqrt(T);
}

double OptionPricer_call_price(OptionPricer* self, double S, double K, double T, double r, double q, double sigma) {
    if (T <= 0) {
        return fmax(0, S - K);
    }
    double d1_val = OptionPricer_d1(self, S, K, T, r, q, sigma);
    double d2_val = OptionPricer_d2(self, d1_val, sigma, T);
    return S * exp(-q * T) * norm_cdf(d1_val) - K * exp(-r * T) * norm_cdf(d2_val);
}

typedef struct {
    OptionPricer* pricer;
    int paths;
    int steps;
} MonteCarloSimulator;

double* MonteCarloSimulator_simulate(MonteCarloSimulator* self) {
    double* prices = (double*)malloc(self->paths * sizeof(double));
    for (int i = 0; i < self->paths; i++) {
        double price_path = self->pricer->spot;
        for (int j = 1; j < self->steps; j++) {
            price_path = MonteCarloSimulator__step(self, price_path);
        }
        prices[i] = price_path;
    }
    return prices;
}

double MonteCarloSimulator__step(MonteCarloSimulator* self, double S) {
    double dt = self->pricer->T / self->steps;
    double dS = S * (self->pricer->rate - self->pricer->div) * dt + S * self->pricer->vol * sqrt(dt) * (sqrt(-2.0 * log((double)rand() / RAND_MAX)) * cos(2.0 * PI * ((double)rand() / RAND_MAX)));
    return S + dS;
}

int main() {
    srand(time(NULL));
    OptionPricer pricer = {100, 100, 0.2, 0.05, 0.02, 1};
    MonteCarloSimulator simulator = {&pricer, 1000, 100};
    double* final_prices = MonteCarloSimulator_simulate(&simulator);
    double option_value = 0;
    for (int i = 0; i < simulator.paths; i++) {
        option_value += OptionPricer_call_price(&pricer, final_prices[i], 100, 1, 0.05, 0.02, 0.2);
    }
    option_value /= simulator.paths;
    printf("%f\n", option_value);
    free(final_prices);
    return 0;
}