#include <stdio.h>
#include <math.h>

typedef struct {
    int state;
} RandomNumberGenerator;

void RandomNumberGenerator_init(RandomNumberGenerator *self, int seed) {
    self->state = seed;
}

double RandomNumberGenerator_next(RandomNumberGenerator *self) {
    self->state = (self->state * 1103515245 + 12345) % (1 << 31);
    return (double)self->state / (1 << 31);
}

typedef struct {
    RandomNumberGenerator *rng;
    double strike;
    double maturity;
    double volatility;
    double risk_free_rate;
} OptionPricer;

void OptionPricer_init(OptionPricer *self, RandomNumberGenerator *rng, double strike, double maturity, double volatility, double risk_free_rate) {
    self->rng = rng;
    self->strike = strike;
    self->maturity = maturity;
    self->volatility = volatility;
    self->risk_free_rate = risk_free_rate;
}

double* OptionPricer_simulate(OptionPricer *self, int steps) {
    double *price_paths = (double *)malloc(steps * sizeof(double));
    for (int i = 0; i < steps; i++) {
        double price = 1.0;
        for (int j = 0; j < steps; j++) {
            double drift = self->risk_free_rate - 0.5 * self->volatility * self->volatility;
            double diffusion = self->volatility * RandomNumberGenerator_next(self->rng);
            price *= 1 + drift + diffusion;
        }
        price_paths[i] = price;
    }
    return price_paths;
}

double* OptionPricer_payoff(OptionPricer *self, double *price_paths, int steps) {
    double *payoff_values = (double *)malloc(steps * sizeof(double));
    for (int i = 0; i < steps; i++) {
        payoff_values[i] = fmax(price_paths[i] - self->strike, 0);
    }
    return payoff_values;
}

double OptionPricer_price(OptionPricer *self, int steps) {
    double *price_paths = OptionPricer_simulate(self, steps);
    double *payoff_values = OptionPricer_payoff(self, price_paths, steps);
    double sum = 0;
    for (int i = 0; i < steps; i++) {
        sum += payoff_values[i];
    }
    free(price_paths);
    free(payoff_values);
    return sum * exp(-self->risk_free_rate * self->maturity) / steps;
}

void main() {
    RandomNumberGenerator rng;
    RandomNumberGenerator_init(&rng, 42);
    OptionPricer pricer;
    OptionPricer_init(&pricer, &rng, 100, 1, 0.2, 0.05);
    double option_price = OptionPricer_price(&pricer, 1000);
    printf("%f\n", option_price);
}