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
        std::vector<std::vector<double>> paths(N + 1, std::vector<double>(M));
        paths[0] = std::vector<double>(M, S0);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(0.0, 1.0);

        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j < M; ++j) {
                double z = d(gen);
                paths[i][j] = paths[i - 1][j] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z);
            }
        }
        return paths;
    }

    double option_price() {
        std::vector<std::vector<double>> paths = simulate_paths();
        std::vector<double> payoff(M);
        for (int j = 0; j < M; ++j) {
            payoff[j] = std::max(paths[N][j] - K, 0.0);
        }
        double price = exp(-r * T) * std::accumulate(payoff.begin(), payoff.end(), 0.0) / M;
        return price;
    }

private:
    double S0, K, T, r, sigma;
    int N, M;
};

int main() {
    double S0 = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 100;
    int M = 10000;
    FinancialModel model(S0, K, T, r, sigma, N, M);
    double price = model.option_price();
    std::cout << price << std::endl;
    return 0;
}