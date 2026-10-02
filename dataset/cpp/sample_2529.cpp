#include <iostream>
#include <vector>
#include <cmath>
#include <random>

std::vector<double> simulate_price_changes(int steps, double initial_price, double volatility) {
    std::vector<double> prices;
    prices.push_back(initial_price);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, volatility);
    for (int _ = 0; _ < steps; ++_) {
        double change = d(gen);
        prices.push_back(prices.back() * std::exp(change));
    }
    return prices;
}

double calculate_option_value(const std::vector<double>& prices, double strike, double r, double T) {
    double value = 0;
    for (double price : prices) {
        value += std::max(price - strike, 0.0) * std::exp(-r * T);
    }
    return value / prices.size();
}

int main() {
    double initial_price = 100;
    double strike = 105;
    double r = 0.05;
    double T = 1;
    double volatility = 0.2;
    int steps = 1000;
    std::vector<double> prices = simulate_price_changes(steps, initial_price, volatility);
    double option_value = calculate_option_value(prices, strike, r, T);
    std::cout << "Option Value: " << option_value << std::endl;
    return 0;
}