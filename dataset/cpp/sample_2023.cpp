#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class FinancialModel {
public:
    FinancialModel(double S0, double K, double T, double r, double sigma, int N, int M)
        : S0(S0), K(K), T(T), r(r), sigma(sigma), N(N), M(M) {}

    std::vector<std::vector<double>> simulate_paths() {
        double dt = T / N;
        std::vector<std::vector<double>> S(M, std::vector<double>(N + 1, 0.0));
        for (int i = 0; i < M; ++i) {
            S[i][0] = S0;
        }
        for (int t = 1; t <= N; ++t) {
            std::vector<double> Z(M);
            std::random_device rd;
            std::mt19937 gen(rd());
            std::normal_distribution<> d(0.0, 1.0);
            for (int i = 0; i < M; ++i) {
                Z[i] = d(gen);
                S[i][t] = S[i][t - 1] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Z[i]);
            }
        }
        return S;
    }

    double calculate_option_price() {
        auto S = simulate_paths();
        double payoff_sum = 0.0;
        for (int i = 0; i < M; ++i) {
            payoff_sum += std::max(S[i][N] - K, 0.0);
        }
        double option_price = exp(-r * T) * (payoff_sum / M);
        return option_price;
    }

private:
    double S0, K, T, r, sigma;
    int N, M;
};

int main() {
    double S0 = 100.0;
    double K = 100.0;
    double T = 1.0;
    double r = 0.05;
    double sigma = 0.2;
    int N = 252;
    int M = 10000;
    FinancialModel model(S0, K, T, r, sigma, N, M);
    double price = model.calculate_option_price();
    std::cout << "Option price: " << std::fixed << std::setprecision(4) << price << std::endl;
    return 0;
}