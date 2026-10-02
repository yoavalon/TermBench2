#include <iostream>
#include <vector>
#include <cmath>
#include <random>

std::vector<double> simulate_price(double initial_price, double volatility, int time_steps) {
    std::vector<double> prices;
    prices.push_back(initial_price);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);
    for (int i = 0; i < time_steps; ++i) {
        double drift = 0.05 * prices.back();
        double shock = volatility * prices.back() * d(gen);
        double new_price = prices.back() + drift + shock;
        prices.push_back(new_price);
    }
    return prices;
}

double calculate_option_price(const std::vector<double>& prices, double strike_price, const std::string& option_type = "call") {
    if (option_type == "call") {
        return std::max(0.0, *std::max_element(prices.begin(), prices.end()) - strike_price);
    } else {
        return std::max(0.0, strike_price - *std::min_element(prices.begin(), prices.end()));
    }
}

int main() {
    double initial_price = 100;
    double volatility = 0.2;
    int time_steps = 100;
    double strike_price = 105;
    while (true) {
        std::vector<double> prices = simulate_price(initial_price, volatility, time_steps);
        double option_price = calculate_option_price(prices, strike_price);
        std::cout << "Option price: " << option_price << std::endl;
    }
    return 0;
}