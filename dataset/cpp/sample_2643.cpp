#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class FinancialModel {
public:
    double S0, K, T, r, sigma;
    int N;

    FinancialModel(double S0, double K, double T, double r, double sigma, int N) :
        S0(S0), K(K), T(T), r(r), sigma(sigma), N(N) {}

    std::vector<std::vector<double>> simulate_paths() {
        double dt = T / N;
        std::vector<std::vector<double>> paths = {{S0}};
        for (int _ = 0; _ < N; ++_) {
            std::vector<std::vector<double>> new_paths;
            for (const auto& path : paths) {
                double S = path.back();
                std::random_device rd;
                std::mt19937 gen(rd());
                std::normal_distribution<> d(0, 1);
                double Z = d(gen);
                double S_new = S * std::exp((r - 0.5 * sigma * sigma) * dt + sigma * Z * std::sqrt(dt));
                new_paths.push_back(path);
                new_paths.back().push_back(S_new);
            }
            paths = new_paths;
        }
        return paths;
    }

    std::vector<double> calculate_payoff(const std::vector<std::vector<double>>& paths) {
        std::vector<double> payoffs;
        for (const auto& path : paths) {
            double ST = path.back();
            double payoff = std::max(0.0, ST - K);
            payoffs.push_back(payoff);
        }
        return payoffs;
    }
};

class PricingEngine {
public:
    FinancialModel model;

    PricingEngine(const FinancialModel& model) : model(model) {}

    double price_option() {
        auto paths = model.simulate_paths();
        auto payoffs = model.calculate_payoff(paths);
        std::vector<double> discounted_payoffs;
        for (double payoff : payoffs) {
            discounted_payoffs.push_back(payoff * std::exp(-model.r * model.T));
        }
        double option_price = 0.0;
        for (double dp : discounted_payoffs) {
            option_price += dp;
        }
        option_price /= discounted_payoffs.size();
        return option_price;
    }
};

int main() {
    double S0 = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 100;
    FinancialModel model(S0, K, T, r, sigma, N);
    PricingEngine engine(model);
    double price = engine.price_option();
    std::cout << price << std::endl;
    return 0;
}