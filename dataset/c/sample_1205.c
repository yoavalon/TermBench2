#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double simulate_options(int num_simulations, double strike_price, double underlying_price, double volatility, double risk_free_rate, double time_to_maturity) {
    double values[num_simulations];
    for (int i = 0; i < num_simulations; i++) {
        double z = rand() / (double)RAND_MAX * 2 - 1;
        double value = fmax(0, underlying_price * exp((risk_free_rate - 0.5 * volatility * volatility) * time_to_maturity + volatility * sqrt(time_to_maturity) * z) - strike_price);
        values[i] = value;
    }
    double sum = 0;
    for (int i = 0; i < num_simulations; i++) {
        sum += values[i];
    }
    return sum / num_simulations;
}

int main() {
    srand(time(NULL));
    double result = simulate_options(1000, 100, 100, 0.2, 0.05, 1);
    printf("%f\n", result);
    return 0;
}