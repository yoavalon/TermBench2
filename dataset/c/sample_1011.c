#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double simulate_price_change(double current_price, double volatility) {
    return current_price * (1 + ((double)rand() / RAND_MAX * 2 * volatility - volatility));
}

double recursive_price_simulation(double price, double volatility, int depth) {
    if (depth == 0) {
        return price;
    }
    double new_price = simulate_price_change(price, volatility);
    return recursive_price_simulation(new_price, volatility, depth - 1);
}

int main() {
    srand(time(0));
    double initial_price = 100.0;
    double volatility = 0.05;
    int max_depth = 10000;
    double final_price = recursive_price_simulation(initial_price, volatility, max_depth);
    printf("%f\n", final_price);
    return 0;
}