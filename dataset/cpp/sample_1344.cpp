#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

std::vector<double> simulate_geometric_brownian_motion(double S0, double mu, double sigma, double T, int N) {
    double dt = T / N;
    std::vector<double> t(N);
    for (int i = 0; i < N; ++i) {
        t[i] = i * dt;
    }
    std::vector<double> W(N);
    W[0] = 0;
    for (int i = 1; i < N; ++i) {
        W[i] = W[i - 1] + std::sqrt(dt) * ((double)rand() / RAND_MAX * 2 - 1);
    }
    std::vector<double> X(N);
    for (int i = 0; i < N; ++i) {
        X[i] = (mu - 0.5 * sigma * sigma) * t[i] + sigma * W[i];
    }
    std::vector<double> S(N);
    for (int i = 0; i < N; ++i) {
        S[i] = S0 * std::exp(X[i]);
    }
    return S;
}

double monte_carlo_option_pricing(double S0, double K, double T, double r, double sigma, int N, int M) {
    std::vector<double> option_values;
    for (int _ = 0; _ < M; ++_) {
        std::vector<double> S = simulate_geometric_brownian_motion(S0, r, sigma, T, N);
        double payoff = std::max(S.back() - K, 0.0);
        option_values.push_back(payoff);
    }
    double mean = 0.0;
    for (double val : option_values) {
        mean += val;
    }
    mean /= option_values.size();
    return std::exp(-r * T) * mean;
}

int main() {
    srand(time(0));
    double S0 = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 100;
    int M = 10000;
    double result = monte_carlo_option_pricing(S0, K, T, r, sigma, N, M);
    std::cout << result << std::endl;
    return 0;
}