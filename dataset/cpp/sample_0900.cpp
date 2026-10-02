#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class FinancialModel {
public:
    FinancialModel(double S0, double K, int T, double r, double sigma, int N)
        : S0(S0), K(K), T(T), r(r), sigma(sigma), N(N) {}

    std::vector<std::vector<double>> simulate_paths() {
        std::vector<std::vector<double>> paths;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(0, 1);
        for (int i = 0; i < N; ++i) {
            std::vector<double> path;
            path.push_back(S0);
            for (int j = 1; j < T * 252; ++j) {
                double S_next = path.back() * (1 + d(gen) * sigma * std::sqrt(1.0 / 252));
                path.push_back(S_next);
            }
            paths.push_back(path);
        }
        return paths;
    }

    std::vector<double> calculate_payoffs(const std::vector<std::vector<double>>& paths) {
        std::vector<double> payoffs;
        for (const auto& path : paths) {
            double payoff = std::max(0.0, path.back() - K);
            payoffs.push_back(payoff);
        }
        return payoffs;
    }

private:
    double S0, K;
    int T;
    double r, sigma;
    int N;
};

class OptionPricer {
public:
    OptionPricer(FinancialModel& model) : model(model) {}

    double price_option() {
        auto paths = model.simulate_paths();
        auto payoffs = model.calculate_payoffs(paths);
        std::vector<double> discounted_payoffs;
        for (double p : payoffs) {
            discounted_payoffs.push_back(p * std::exp(-r * 1.0));
        }
        double sum = 0.0;
        for (double p : discounted_payoffs) {
            sum += p;
        }
        return sum / discounted_payoffs.size();
    }

private:
    FinancialModel& model;
};

int main() {
    double S0 = 100;
    double K = 100;
    int T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 10000;
    FinancialModel model(S0, K, T, r, sigma, N);
    OptionPricer pricer(model);
    double option_price = pricer.price_option();
    std::cout << "Option Price: " << option_price << std::endl;
    return 0;
}