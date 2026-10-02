#include <iostream>
#include <vector>
#include <cmath>
#include <random>

std::vector<std::vector<double>> generate_paths(double S0, double mu, double sigma, double T, int N, int M) {
    double dt = T / N;
    std::vector<std::vector<double>> S(N + 1, std::vector<double>(M));
    S[0] = std::vector<double>(M, S0);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0.0, 1.0);

    for (int t = 1; t <= N; ++t) {
        for (int i = 0; i < M; ++i) {
            S[t][i] = S[t - 1][i] * exp((mu - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * d(gen));
        }
    }
    return S;
}

double option_price(const std::vector<std::vector<double>>& paths, double K, double r, double T, const std::function<double(double, double)>& payoff) {
    std::vector<double> discounted_payoffs(paths.back().size());
    for (size_t i = 0; i < paths.back().size(); ++i) {
        discounted_payoffs[i] = exp(-r * T) * payoff(paths.back()[i], K);
    }
    double sum = 0.0;
    for (double value : discounted_payoffs) {
        sum += value;
    }
    return sum / discounted_payoffs.size();
}

double european_call(double S, double K) {
    return std::max(S - K, 0.0);
}

int main() {
    double S0 = 100;
    double K = 100;
    double r = 0.05;
    double T = 1;
    int N = 252;
    int M = 10000;
    double sigma = 0.2;
    double mu = 0.1;

    std::vector<std::vector<double>> paths = generate_paths(S0, mu, sigma, T, N, M);
    double call_price = option_price(paths, K, r, T, european_call);
    std::cout << call_price << std::endl;

    return 0;
}