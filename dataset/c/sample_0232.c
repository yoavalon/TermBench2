#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double generate_paths(double S0, double mu, double sigma, double T, int N, int M, double paths[M][N+1]) {
    double dt = T / N;
    for (int i = 0; i < M; i++) {
        paths[i][0] = S0;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            double Z = sqrt(-2.0 * log(rand() / (double)RAND_MAX)) * cos(2.0 * M_PI * rand() / (double)RAND_MAX);
            double S = paths[j][i-1] * exp((mu - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Z);
            paths[j][i] = S;
        }
    }
}

double payoff_function(double S, double K, const char* option_type) {
    if (strcmp(option_type, "call") == 0) {
        return S - K > 0 ? S - K : 0;
    } else if (strcmp(option_type, "put") == 0) {
        return K - S > 0 ? K - S : 0;
    }
    return 0;
}

double monte_carlo_pricing(double paths[][101], double K, double r, double T, const char* option_type, int M) {
    double payoffs = 0;
    for (int i = 0; i < M; i++) {
        payoffs += payoff_function(paths[i][100], K, option_type);
    }
    double present_value = exp(-r * T) * payoffs / M;
    return present_value;
}

int main() {
    double S0 = 100;
    double K = 100;
    double r = 0.05;
    double T = 1;
    int N = 100;
    int M = 10000;
    const char* option_type = "call";
    double paths[M][N+1];
    generate_paths(S0, r, 0.2, T, N, M, paths);
    double price = monte_carlo_pricing(paths, K, r, T, option_type, M);
    printf("Option price: %f\n", price);
    return 0;
}