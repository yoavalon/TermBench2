cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

double simulate_geometric_brownian_motion(double S0, double mu, double sigma, double T, int N) {
    double dt = T / N;
    std::vector<double> S;
    S.push_back(S0);
    for (int i = 1; i <= N; i++) {
        double dS = S[i - 1] * (mu * dt + sigma * sqrt(dt) * rand() / RAND_MAX);
        S.push_back(S[i - 1] + dS);
    }
    return S.back();
}

double monte_carlo_option_pricing(double S0, double K, double T, double r, double sigma, int N, int M) {
    double C = 0;
    for (int _ = 0; _ < M; _++) {
        double ST = simulate_geometric_brownian_motion(S0, r, sigma, T, N);
        C += std::max(ST - K, 0.0);
    }
    return C / M;
}

int main() {
    double S0 = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 100;
    int M = 1000;
    double option_price = monte_carlo_option_pricing(S0, K, T, r, sigma, N, M);
    std::cout << option_price << std::endl;
    return 0;
}