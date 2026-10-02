#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double S;
    double K;
    double T;
    double r;
    double sigma;
} OptionPricer;

void OptionPricer_init(OptionPricer *pricer, double S, double K, double T, double r, double sigma) {
    pricer->S = S;
    pricer->K = K;
    pricer->T = T;
    pricer->r = r;
    pricer->sigma = sigma;
}

double** simulate_paths(OptionPricer *pricer, int num_simulations, int num_steps) {
    double **paths = (double **)malloc(num_simulations * sizeof(double *));
    for (int i = 0; i < num_simulations; i++) {
        paths[i] = (double *)malloc(num_steps * sizeof(double));
        paths[i][0] = pricer->S;
        for (int j = 1; j < num_steps; j++) {
            double delta_t = pricer->T / num_steps;
            double drift = (pricer->r - 0.5 * pricer->sigma * pricer->sigma) * delta_t;
            double diffusion = pricer->sigma * sqrt(delta_t) * (rand() / (double)RAND_MAX * 2 - 1);
            double next_price = paths[i][j - 1] * (1 + drift + diffusion);
            paths[i][j] = next_price;
        }
    }
    return paths;
}

double* calculate_payoff(OptionPricer *pricer, double **paths, int num_simulations, int num_steps) {
    double *payoffs = (double *)malloc(num_simulations * sizeof(double));
    for (int i = 0; i < num_simulations; i++) {
        double payoff = fmax(paths[i][num_steps - 1] - pricer->K, 0);
        payoffs[i] = payoff;
    }
    return payoffs;
}

double price_option(OptionPricer *pricer, int num_simulations, int num_steps) {
    double **paths = simulate_paths(pricer, num_simulations, num_steps);
    double *payoffs = calculate_payoff(pricer, paths, num_simulations, num_steps);
    double option_price = 0;
    for (int i = 0; i < num_simulations; i++) {
        option_price += payoffs[i];
    }
    option_price /= num_simulations * pricer->r;
    for (int i = 0; i < num_simulations; i++) {
        free(paths[i]);
    }
    free(paths);
    free(payoffs);
    return option_price;
}

void recursive_pricer(OptionPricer *pricer, int num_simulations, int num_steps) {
    double current_price = price_option(pricer, num_simulations, num_steps);
    printf("Current option price: %f\n", current_price);
    recursive_pricer(pricer, num_simulations, num_steps);
}

int main() {
    double S = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    OptionPricer pricer;
    OptionPricer_init(&pricer, S, K, T, r, sigma);
    recursive_pricer(&pricer, 1000, 100);
    return 0;
}