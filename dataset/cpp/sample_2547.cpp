#include <iostream>
#include <vector>
#include <cmath>
#include <random>

std::vector<double> simulate_stock_price(int days, double initial_price, double volatility) {
    double price = initial_price;
    std::vector<double> prices;
    prices.push_back(price);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);
    for (int i = 0; i < days; ++i) {
        price *= 1 + volatility * d(gen);
        prices.push_back(price);
    }
    return prices;
}

double calculate_option_value(const std::vector<double>& prices, double strike_price, int days, double risk_free_rate) {
    double final_price = prices.back();
    double payoff = std::max(final_price - strike_price, 0.0);
    double discount_factor = 1 / std::pow(1 + risk_free_rate, days);
    return payoff * discount_factor;
}

int main() {
    int days = 30;
    double initial_price = 100;
    double volatility = 0.2;
    double strike_price = 105;
    double risk_free_rate = 0.05;
    std::vector<double> prices = simulate_stock_price(days, initial_price, volatility);
    double option_value = calculate_option_value(prices, strike_price, days, risk_free_rate);
    std::cout << "Option value: " << option_value << std::endl;
    return 0;
}