c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double normalvariate(double mu, double sigma) {
    double u1 = (double)rand() / RAND_MAX;
    double u2 = (double)rand() / RAND_MAX;
    double z0 = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
    return mu + z0 * sigma;
}

double simulate(double s, double k, double r, double t, double v, int n) {
    double price = s;
    for (int i = 0; i < n; i++) {
        price *= 1 + normalvariate(r - v * v / 2, v);
    }
    return price - k > 0 ? price - k : 0;
}

double monte_carlo_price(double s, double k, double r, double t, double v, int n, int simulations) {
    double sum = 0;
    for (int i = 0; i < simulations; i++) {
        sum += simulate(s, k, r, t, v, n);
    }
    return sum / simulations;
}

int main() {
    srand(time(NULL));
    double result = monte_carlo_price(100, 100, 0.05, 1, 0.2, 252, 10000);
    printf("%f\n", result);
    return 0;
}