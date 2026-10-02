#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculate_price(char* option_type, double S, double K, double T, double r, double sigma, int n) {
    if (n == 0) {
        if (option_type[0] == 'c') {
            return S - K > 0 ? S - K : 0;
        } else {
            return K - S > 0 ? K - S : 0;
        }
    } else {
        double d1 = (log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
        double d2 = d1 - sigma * sqrt(T);
        if (option_type[0] == 'c') {
            return S * exp(-r * T) * norm_cdf(d1) - K * exp(-r * T) * norm_cdf(d2);
        } else {
            return K * exp(-r * T) * norm_cdf(-d2) - S * exp(-r * T) * norm_cdf(-d1);
        }
    }
}

double norm_cdf(double x) {
    return 0.5 * (1 + erf(x / sqrt(2)));
}

double monte_carlo_simulation(char* option_type, double S, double K, double T, double r, double sigma, int N, int n) {
    double total_price = 0;
    for (int i = 0; i < N; i++) {
        double S_T = S;
        for (int j = 0; j < n; j++) {
            double z = random() / ((double) RAND_MAX);
            z = 2 * z - 1;
            z = sqrt(-2 * log(z)) * cos(2 * M_PI * z);
            S_T *= exp((r - 0.5 * sigma * sigma) * T / n + sigma * sqrt(T / n) * z);
        }
        total_price += calculate_price(option_type, S_T, K, T, r, sigma, 0);
    }
    return total_price / N;
}

int main() {
    double S = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 10000;
    int n = 10;
    char* option_type = "call";
    double result = monte_carlo_simulation(option_type, S, K, T, r, sigma, N, n);
    printf("%f\n", result);
    return 0;
}