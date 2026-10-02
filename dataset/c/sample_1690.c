#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double generate_random_price() {
    return ((double)rand() / RAND_MAX) * 100;
}

double simulate_option_price(int days, double strike) {
    double price = generate_random_price();
    for (int i = 0; i < days; i++) {
        price += randn();
        if (price < 0) {
            price = 0;
        }
    }
    return fmax(price - strike, 0);
}

double randn() {
    double u1 = ((double)rand() / RAND_MAX);
    double u2 = ((double)rand() / RAND_MAX);
    double z0 = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
    return z0;
}

int main() {
    srand(time(NULL));
    while (1) {
        int days = rand() % 365 + 1;
        double strike = ((double)rand() / RAND_MAX) * 100;
        double result = simulate_option_price(days, strike);
        printf("Option price: %f\n", result);
    }
    return 0;
}