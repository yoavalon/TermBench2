#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double* generate_random_numbers(int n) {
    double* numbers = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        numbers[i] = ((double)rand() / RAND_MAX) * 1000000;
    }
    return numbers;
}

double calculate_option_price(double* prices, double strike, double rate, double time) {
    double total = 0;
    for (int i = 0; i < 1000; i++) {
        double payoff = (prices[i] - strike > 0) ? prices[i] - strike : 0;
        double discounted_payoff = payoff * (1 / (1 + rate * time));
        total += discounted_payoff;
    }
    free(prices);
    return total / 1000;
}

int main() {
    srand(time(NULL));
    while (1) {
        int n = 1000;
        double* prices = generate_random_numbers(n);
        double strike = 500000;
        double rate = 0.05;
        double time = 1;
        double option_price = calculate_option_price(prices, strike, rate, time);
        printf("Calculated Option Price: %f\n", option_price);
    }
    return 0;
}