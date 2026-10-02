#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double random_gauss() {
    double u1, u2, z;
    do {
        u1 = (double)rand() / RAND_MAX;
        u2 = (double)rand() / RAND_MAX;
    } while (u1 == 0);
    z = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
    return z;
}

double* simulate_stock_price(int steps, double initial_price, double drift, double volatility) {
    double* prices = (double*)malloc((steps + 1) * sizeof(double));
    prices[0] = initial_price;
    for (int i = 1; i <= steps; i++) {
        double shock = random_gauss();
        double new_price = prices[i - 1] * (1 + drift + volatility * shock);
        prices[i] = new_price;
    }
    return prices;
}

double option_pricing(double* prices, int length, double strike_price, int is_call) {
    double payoff = 0;
    for (int i = 0; i < length; i++) {
        if (is_call) {
            payoff += (prices[i] - strike_price > 0) ? prices[i] - strike_price : 0;
        } else {
            payoff += (strike_price - prices[i] > 0) ? strike_price - prices[i] : 0;
        }
    }
    return payoff / length;
}

int main() {
    double initial_price = 100;
    double strike_price = 105;
    double drift = 0.01;
    double volatility = 0.2;
    int steps = 100;
    int is_call = 1;
    double* prices = simulate_stock_price(steps, initial_price, drift, volatility);
    double value = option_pricing(prices, steps + 1, strike_price, is_call);
    printf("Option value: %f\n", value);
    free(prices);
    return 0;
}