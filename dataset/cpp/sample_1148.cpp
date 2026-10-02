#include <iostream>
#include <cmath>
#include <vector>
#include <random>

class OptionPricer {
public:
    OptionPricer(double S, double K, double T, double r, double sigma, int N, int M)
        : S(S), K(K), T(T), r(r), sigma(sigma), N(N), M(M) {}

    std::vector<std::vector<double>> simulate_stock_prices() {
        double dt = T / N;
        std::vector<std::vector<double>> paths(M, std::vector<double>(1, S));
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(0, 1);

        for (int t = 1; t <= N; ++t) {
            for (int i = 0; i < M; ++i) {
                double z = d(gen);
                double S_next = paths[i].back() * exp((r - 0.5 * sigma * sigma) * dt + sigma * z * sqrt(dt));
                paths[i].push_back(S_next);
            }
        }
        return paths;
    }

    std::vector<double> payoff(const std::vector<std::vector<double>>& paths) {
        std::vector<double> payoffs;
        for (const auto& path : paths) {
            payoffs.push_back(std::max(path.back() - K, 0.0));
        }
        return payoffs;
    }

    double price_option() {
        std::vector<std::vector<double>> paths = simulate_stock_prices();
        std::vector<double> payoffs = payoff(paths);
        double C = exp(-r * T) * std::accumulate(payoffs.begin(), payoffs.end(), 0.0) / M;
        return C;
    }

private:
    double S, K, T, r, sigma;
    int N, M;
};

int main() {
    OptionPricer pricer(100, 100, 1, 0.05, 0.2, 100, 1000);
    while (true) {
        double price = pricer.price_option();
        std::cout << "Option price: " << price << std::endl;
    }
    return 0;
}