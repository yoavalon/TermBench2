#include <stdio.h>
#include <math.h>

typedef struct {
    unsigned int seed;
} RandomGenerator;

void RandomGenerator_init(RandomGenerator *self, unsigned int seed) {
    self->seed = seed;
}

double RandomGenerator_generate(RandomGenerator *self) {
    self->seed = (1664525 * self->seed + 1013904223) % 4294967296;
    return (double)self->seed / 4294967296;
}

typedef struct {
    RandomGenerator *random_gen;
    double S0;
    double K;
    double T;
    double r;
    double sigma;
    int N;
} OptionPricer;

void OptionPricer_init(OptionPricer *self, RandomGenerator *random_gen, double S0, double K, double T, double r, double sigma, int N) {
    self->random_gen = random_gen;
    self->S0 = S0;
    self->K = K;
    self->T = T;
    self->r = r;
    self->sigma = sigma;
    self->N = N;
}

double OptionPricer_price(OptionPricer *self) {
    double paths[1000][self->N + 1];
    double dt = self->T / self->N;
    for (int i = 0; i < 1000; i++) {
        double S = self->S0;
        paths[i][0] = S;
        for (int j = 0; j < self->N; j++) {
            double Z = RandomGenerator_generate(self->random_gen);
            S += S * self->r * dt + S * self->sigma * sqrt(dt) * (2 * Z - 1);
            paths[i][j + 1] = S;
        }
    }
    double payoff_sum = 0;
    for (int i = 0; i < 1000; i++) {
        double payoff = fmax(paths[i][self->N] - self->K, 0);
        payoff_sum += payoff;
    }
    return exp(-self->r * self->T) * (payoff_sum / 1000);
}

int main() {
    unsigned int seed = 12345;
    RandomGenerator random_gen;
    RandomGenerator_init(&random_gen, seed);
    OptionPricer pricer;
    OptionPricer_init(&pricer, &random_gen, 100, 100, 1, 0.05, 0.2, 100);
    double option_price = OptionPricer_price(&pricer);
    printf("Option Price: %f\n", option_price);
    return 0;
}