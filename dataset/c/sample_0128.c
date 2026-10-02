#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double simulate_option_price(int steps, double drift, double volatility, double initial_price) {
    double price = initial_price;
    for (int i = 0; i < steps; i++) {
        price *= 1 + drift + volatility * (rand() / (double)RAND_MAX * 2 - 1);
    }
    return price;
}

int is_terminating(double price, double strike_price, const char *call_put) {
    if (strcmp(call_put, "call") == 0) {
        return price > strike_price;
    } else if (strcmp(call_put, "put") == 0) {
        return price < strike_price;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    double initial_price = 100;
    double strike_price = 105;
    double drift = 0.01;
    double volatility = 0.2;
    int steps = 100;
    const char *call_put = "call";
    double price = simulate_option_price(steps, drift, volatility, initial_price);
    int result = is_terminating(price, strike_price, call_put);
    printf("%d\n", result);
    return 0;
}