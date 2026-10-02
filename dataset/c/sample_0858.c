#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int iterations;
    char *option_type;
    double strike;
    double underlying;
    double sigma;
    double r;
    double t;
} MonteCarlo;

typedef struct {
    char *type;
    double strike;
    double underlying;
    double sigma;
    double r;
    double t;
} Option;

double gauss(double mean, double stddev) {
    double u1, u2, z0;
    do {
        u1 = ((double)rand() / RAND_MAX);
        u2 = ((double)rand() / RAND_MAX);
    } while (u1 == 0.0);
    z0 = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
    return z0 * stddev + mean;
}

double payoff(MonteCarlo *self, double price) {
    if (strcmp(self->option_type, "call") == 0) {
        return fmax(price - self->strike, 0);
    } else if (strcmp(self->option_type, "put") == 0) {
        return fmax(self->strike - price, 0);
    }
    return 0;
}

double price(MonteCarlo *self) {
    double total = 0;
    for (int i = 0; i < self->iterations; i++) {
        double price = self->underlying * exp(self->r * self->t + self->sigma * sqrt(self->t) * gauss(0, 1));
        double payoff_value = payoff(self, price);
        double discounted_payoff = payoff_value * exp(-self->r * self->t);
        total += discounted_payoff;
    }
    return total / self->iterations;
}

Option *Option_new(char *type, double strike, double underlying, double sigma, double r, double t) {
    Option *self = (Option *)malloc(sizeof(Option));
    self->type = type;
    self->strike = strike;
    self->underlying = underlying;
    self->sigma = sigma;
    self->r = r;
    self->t = t;
    return self;
}

MonteCarlo *MonteCarlo_new(int iterations, char *option_type, double strike, double underlying, double sigma, double r, double t) {
    MonteCarlo *self = (MonteCarlo *)malloc(sizeof(MonteCarlo));
    self->iterations = iterations;
    self->option_type = option_type;
    self->strike = strike;
    self->underlying = underlying;
    self->sigma = sigma;
    self->r = r;
    self->t = t;
    return self;
}

double Option_evaluate(Option *self) {
    MonteCarlo *model = MonteCarlo_new(10000, self->type, self->strike, self->underlying, self->sigma, self->r, self->t);
    double result = price(model);
    free(model);
    return result;
}

void main() {
    Option *option = Option_new("call", 100, 100, 0.2, 0.05, 1);
    double result = Option_evaluate(option);
    printf("Option price: %f\n", result);
    free(option);
}