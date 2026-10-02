#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

class FinancialModel {
public:
    FinancialModel(double initial_price, double volatility, double risk_free_rate, double strike_price, double maturity)
        : S0(initial_price), sigma(volatility), r(risk_free_rate), K(strike_price), T(maturity) {}

    std::vector<std::vector<double>> simulate_paths(int num_paths, int num_steps) {
        double dt = T / num_steps;
        std::vector<std::vector<double>> paths(num_paths, std::vector<double>(1, S0));
        for (int _ = 0; _ < num_steps; ++_) {
            for (int i = 0; i < num_paths; ++i) {
                double Z = static_cast<double>(rand()) / RAND_MAX * 2 - 1;
                double S_next = paths[i].back() * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Z);
                paths[i].push_back(S_next);
            }
        }
        return paths;
    }

private:
    double S0, sigma, r, K, T;
};

class OptionPricing {
public:
    OptionPricing(FinancialModel& model, int num_paths, int num_steps)
        : model(model), num_paths(num_paths), num_steps(num_steps) {}

    double calculate_option_value() {
        std::vector<std::vector<double>> paths = model.simulate_paths(num_paths, num_steps);
        std::vector<double> option_values;
        for (const auto& path : paths) {
            double payoff = std::max(path.back() - model.K, 0.0);
            option_values.push_back(payoff);
        }
        return std::accumulate(option_values.begin(), option_values.end(), 0.0) / num_paths * exp(-model.r * model.T);
    }

private:
    FinancialModel& model;
    int num_paths, num_steps;
};

int main() {
    double initial_price = 100;
    double volatility = 0.2;
    double risk_free_rate = 0.05;
    double strike_price = 100;
    double maturity = 1;
    int num_paths = 1000;
    int num_steps = 100;
    FinancialModel model(initial_price, volatility, risk_free_rate, strike_price, maturity);
    OptionPricing option_pricing(model, num_paths, num_steps);
    double value = option_pricing.calculate_option_value();
    std::cout << "Option Value: " << value << std::endl;
    return 0;
}