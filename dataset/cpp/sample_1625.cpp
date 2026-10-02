#include <iostream>
#include <vector>
#include <cmath>
#include <random>

double simulate_prices(double base_price, double volatility, int days, std::vector<double>& prices) {
    prices.resize(days);
    prices[0] = base_price;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, volatility);
    for (int i = 1; i < days; ++i) {
        double daily_return = d(gen);
        prices[i] = prices[i - 1] * (1 + daily_return);
    }
    return prices.back();
}

double calculate_option_premium(const std::vector<double>& prices, double strike_price, int days) {
    double option_values = 0;
    for (double price : prices) {
        option_values += std::max(price - strike_price, 0.0);
    }
    return option_values * 365 / days;
}

int main() {
    double base_price = 100;
    double volatility = 0.2;
    int days = 365;
    double strike_price = 100;
    std::vector<double> prices;
    while (true) {
        simulate_prices(base_price, volatility, days, prices);
        double premium = calculate_option_premium(prices, strike_price, days);
        std::cout << "Calculated option premium: " << premium << std::endl;
    }
    return 0;
}