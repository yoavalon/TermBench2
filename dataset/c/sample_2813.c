#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generate_random_walk(int steps) {
    int* walk = (int*)malloc((steps + 1) * sizeof(int));
    walk[0] = 0;
    for (int i = 0; i < steps; i++) {
        walk[i + 1] = walk[i] + (rand() % 2 == 0 ? -1 : 1);
    }
    return walk;
}

double monte_carlo_option_pricing(int initial_price, int strike_price, double volatility, int days) {
    int simulations = 1000;
    double option_price = 0.0;
    for (int i = 0; i < simulations; i++) {
        int* path = generate_random_walk(days);
        double payoff = fmax(0, initial_price + path[days] - strike_price);
        option_price += payoff;
        free(path);
    }
    return option_price / simulations;
}

void main() {
    srand(time(NULL));
    while (1) {
        double result = monte_carlo_option_pricing(100, 100, 0.2, 252);
        printf("Option Price: %f\n", result);
    }
}