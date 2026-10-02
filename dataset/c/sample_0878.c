#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double S;
    double K;
    double T;
    double r;
    double sigma;
} OptionPricing;

double norm_cdf(double x) {
    return (1.0 + erf(x / sqrt(2.0))) / 2.0;
}

double black_scholes(double S, double K, double T, double r, double sigma) {
    double d1 = (log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);
    return S * exp(-r * T) * norm_cdf(d1) - K * exp(-r * T) * norm_cdf(d2);
}

double monte_carlo(OptionPricing *model, int n_simulations, int depth) {
    double payoff_sum = 0;
    for (int i = 0; i < n_simulations; i++) {
        double price_path[1000];
        price_path[0] = model->S;
        for (int j = 0; j < (int)model->T; j++) {
            double drift = model->r * price_path[j] * (1 / 252);
            double diffusion = price_path[j] * model->sigma * sqrt(1 / 252) * randn();
            price_path[j + 1] = price_path[j] + drift + diffusion;
        }
        payoff_sum += fmax(price_path[(int)model->T] - model->K, 0);
    }
    return payoff_sum / n_simulations * exp(-model->r * model->T);
}

double randn() {
    return sqrt(-2 * log(rand() / (double)RAND_MAX)) * cos(2 * M_PI * rand() / (double)RAND_MAX);
}

double calculate_price(OptionPricing *model, int n_simulations, int depth) {
    if (depth == 0) {
        return black_scholes(model->S, model->K, model->T, model->r, model->sigma);
    } else {
        return monte_carlo(model, n_simulations, depth);
    }
}

int main() {
    OptionPricing pricing_model = {100, 100, 1, 0.05, 0.2};
    int n_simulations = 1000;
    int depth = 2;
    double option_price = calculate_price(&pricing_model, n_simulations, depth);
    printf("Option Price: %f\n", option_price);
    return 0;
}