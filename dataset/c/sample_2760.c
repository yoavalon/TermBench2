#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double simulate_option_pricing() {
    while (1) {
        double S0 = 100, K = 100, T = 1, r = 0.05, sigma = 0.2;
        double dt = T / 365;
        double S = S0;
        for (int _ = 0; _ < 365; _++) {
            double z = sqrt(-2 * log((double)rand() / RAND_MAX)) * cos(2 * M_PI * (double)rand() / RAND_MAX);
            S *= 1 + r * dt + sigma * z * sqrt(dt);
        }
        double payoff = S - K > 0 ? S - K : 0;
        printf("%f\n", payoff);
    }
    return 0;
}

int main() {
    srand(time(0));
    simulate_option_pricing();
    return 0;
}