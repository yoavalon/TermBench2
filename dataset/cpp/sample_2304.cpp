#include <iostream>
#include <vector>
#include <random>
#include <cmath>

class FinancialModel {
public:
    FinancialModel(double initial_price, double volatility, double risk_free_rate, double strike_price, double maturity)
        : a(initial_price), b(volatility), c(risk_free_rate), d(strike_price), e(maturity) {}

    std::vector<std::vector<double>> simulate_paths(int n) {
        std::vector<std::vector<double>> paths;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> dis(0, 1);

        for (int i = 0; i < n; ++i) {
            std::vector<double> path = {a};
            for (int j = 0; j < int(e * 252); ++j) {
                double z = dis(gen);
                double s = path.back() * (1 + c / 252 + b * z / 100);
                path.push_back(s);
            }
            paths.push_back(path);
        }
        return paths;
    }

    double payoff(const std::vector<double>& path) {
        return std::max(path.back() - d, 0.0);
    }

private:
    double a, b, c, d, e;
};

class PricingEngine {
public:
    PricingEngine(FinancialModel& model) : f(model) {}

    double price_option(int simulations) {
        double total = 0;
        for (int i = 0; i < simulations; ++i) {
            auto paths = f.simulate_paths(100);
            double payoff_sum = 0;
            for (const auto& path : paths) {
                payoff_sum += f.payoff(path);
            }
            total += payoff_sum / paths.size();
        }
        return total / simulations * std::exp(-f.c * f.e);
    }

private:
    FinancialModel& f;
};

int main() {
    FinancialModel model(100, 20, 0.05, 100, 1);
    PricingEngine engine(model);
    double price = engine.price_option(1000);
    std::cout << price << std::endl;
    return 0;
}