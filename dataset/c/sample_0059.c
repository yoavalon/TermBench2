#include <stdio.h>
#include <math.h>

double cdf(double x) {
    // Approximation of the cumulative distribution function for the standard normal distribution
    // Using the error function (erf) for simplicity
    return 0.5 * (1 + erf(x / sqrt(2.0)));
}

double monte_carlo_pricing(double S0, double K, double T, double r, double sigma, int N, int M) {
    double d1 = (log(S0 / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);
    double call_price = S0 * exp(-r * T) * cdf(d1) - K * exp(-r * T) * cdf(d2);
    return call_price;
}

int main() {
    double result = monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 1000, 100000);
    printf("%f\n", result);
    return 0;
}