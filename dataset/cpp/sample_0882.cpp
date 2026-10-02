#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class FinancialModel {
public:
    FinancialModel(double S0, double K, double T, double r, double sigma, int N) : S0(S0), K(K), T(T), r(r), sigma(sigma), N(N) {}

    std::vector<std::vector<double>> simulate_price_paths() {
        double dt = T / N;
        std::vector<std::vector<double>> paths{{S0}};
        for (int i = 1; i <= N; ++i) {
            std::vector<std::vector<double>> new_paths;
            for (const auto& path : paths) {
                double S = path.back();
                double dW = random_gauss() * std::sqrt(dt);
                double new_S = S * std::exp((r - 0.5 * sigma * sigma) * dt + sigma * dW);
                new_paths.push_back(path);
                new_paths.back().push_back(new_S);
            }
            paths = new_paths;
        }
        return paths;
    }

private:
    double random_gauss() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::normal_distribution<> dis(0, 1);
        return dis(gen);
    }

    double S0, K, T, r, sigma;
    int N;
};

class OptionPricer {
public:
    OptionPricer(FinancialModel& model) : model(model) {}

    double payoff(const std::vector<double>& price_path) {
        return std::max(model.K - price_path.back(), 0.0);
    }

    double price_option() {
        auto paths = model.simulate_price_paths();
        std::vector<double> discounted_payoffs;
        for (const auto& path : paths) {
            double payoff_value = payoff(path);
            double discounted_payoff = payoff_value * std::exp(-model.r * model.T);
            discounted_payoffs.push_back(discounted_payoff);
        }
        double option_price = 0.0;
        for (double dp : discounted_payoffs) {
            option_price += dp;
        }
        return option_price / discounted_payoffs.size();
    }

private:
    FinancialModel& model;
};

int main() {
    double S0 = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 100;
    FinancialModel model(S0, K, T, r, sigma, N);
    OptionPricer pricer(model);
    double option_price = pricer.price_option();
    std::cout << "Option Price: " << option_price << std::endl;
    return 0;
}