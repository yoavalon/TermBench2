#include <iostream>
#include <vector>
#include <cmath>
#include <random>

std::vector<std::vector<double>> simulate_prices(int steps, int simulations) {
    double drift = 0.05;
    double volatility = 0.2;
    double initial_price = 100;
    double dt = 1.0 / steps;
    std::vector<std::vector<double>> paths(simulations, std::vector<double>(steps));
    for (int i = 0; i < simulations; ++i) {
        paths[i][0] = initial_price;
    }
    for (int t = 1; t < steps; ++t) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(0.0, 1.0);
        for (int i = 0; i < simulations; ++i) {
            double z = d(gen);
            paths[i][t] = paths[i][t - 1] * std::exp((drift - 0.5 * volatility * volatility) * dt + volatility * std::sqrt(dt) * z);
        }
    }
    return paths;
}

std::vector<double> option_pricing(const std::vector<double>& prices, double strike, const std::string& option_type = "call") {
    std::vector<double> option_values;
    if (option_type == "call") {
        for (double price : prices) {
            option_values.push_back(std::max(price - strike, 0.0));
        }
    } else if (option_type == "put") {
        for (double price : prices) {
            option_values.push_back(std::max(strike - price, 0.0));
        }
    } else {
        return {};
    }
    return option_values;
}

int main() {
    int steps = 252;
    int simulations = 10000;
    double strike = 105;
    auto prices = simulate_prices(steps, simulations);
    auto option_values = option_pricing({prices[0].back()}, strike);
    double mean_value = 0.0;
    for (double value : option_values) {
        mean_value += value;
    }
    mean_value /= option_values.size();
    std::cout << mean_value << std::endl;
    return 0;
}