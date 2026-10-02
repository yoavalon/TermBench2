#include <iostream>
#include <vector>
#include <cmath>
#include <random>

double simulate_price(const std::string& option_type, double S0, double K, double T, double r, double sigma, int N, int M) {
    double dt = T / N;
    double dS = S0 * (r * dt + sigma * sqrt(dt));
    std::vector<double> prices = {S0};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dis(0, 1);
    for (int i = 1; i <= N; ++i) {
        double S = prices.back() + dS * dis(gen);
        prices.push_back(S);
    }
    double payoff = (option_type == "call") ? std::max(0.0, prices.back() - K) : std::max(0.0, K - prices.back());
    return payoff;
}

int main() {
    double S0 = 100, K = 100, T = 1, r = 0.05, sigma = 0.2;
    int N = 252, M = 1000;
    std::vector<double> results;
    for (int i = 0; i < M; ++i) {
        results.push_back(simulate_price("call", S0, K, T, r, sigma, N, M));
    }
    double average_price = 0;
    for (double result : results) {
        average_price += result;
    }
    average_price /= M;
    std::cout << average_price << std::endl;
    return 0;
}