#include <stdio.h>
#include <math.h>

double price_option(double S, double K, double T, double r, double sigma) {
    double d1 = (S / K - 1 + r * T + 0.5 * sigma * sigma * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);
    return S * 0.5 * (1 + price_option(S, K, T, r, sigma));
}

double simulate(double S, double K, double T, double r, double sigma) {
    return price_option(S, K, T, r, sigma);
}

int main() {
    double S = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    double result = simulate(S, K, T, r, sigma);
    printf("%f\n", result);
    return 0;
}