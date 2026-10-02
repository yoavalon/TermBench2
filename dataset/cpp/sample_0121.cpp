#include <iostream>
#include <vector>
#include <cmath>
#include <random>

std::vector<double> simulate_stock_price(double start, double volatility, int days) {
    std::vector<double> prices = {start};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, volatility);
    for (int _ = 0; _ < days; ++_) {
        double price_change = d(gen);
        double new_price = prices.back() * (1 + price_change);
        prices.push_back(new_price);
    }
    return prices;
}

double calculate_option_value(const std::vector<double>& prices, double strike, int days, double risk_free_rate) {
    double final_price = prices.back();
    double payoff = std::max(final_price - strike, 0.0);
    return payoff / std::pow(1 + risk_free_rate, days);
}

int main() {
    double start_price = 100;
    double volatility = 0.2;
    double strike_price = 105;
    int days = 30;
    double risk_free_rate = 0.05;
    int iterations = 1000;
    double total_value = 0;
    for (int _ = 0; _ < iterations; ++_) {
        std::vector<double> prices = simulate_stock_price(start_price, volatility, days);
        double option_value = calculate_option_value(prices, strike_price, days, risk_free_rate);
        total_value += option_value;
    }
    double average_value = total_value / iterations;
    std::cout << average_value << std::endl;
    return 0;
}