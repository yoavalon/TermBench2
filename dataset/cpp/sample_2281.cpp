#include <iostream>
#include <cmath>
#include <cstdlib>

double simulate_stock_price(double start_price, double volatility, int days) {
    double price = start_price;
    for (int _ = 0; _ < days; ++_) {
        price *= 1 + volatility * (2 * static_cast<double>(rand()) / RAND_MAX - 1);
    }
    return price;
}

double monte_carlo_pricing(const std::string& option_type, double start_price, double strike_price, double volatility, int days, int simulations) {
    double total_value = 0;
    for (int _ = 0; _ < simulations; ++_) {
        double final_price = simulate_stock_price(start_price, volatility, days);
        double value;
        if (option_type == "call") {
            value = std::max(final_price - strike_price, 0.0);
        } else {
            value = std::max(strike_price - final_price, 0.0);
        }
        total_value += value;
    }
    return total_value / simulations;
}

int main() {
    double start_price = 100;
    double strike_price = 100;
    double volatility = 0.05;
    int days = 252;
    int simulations = 10000;
    std::string option_type = "call";
    while (true) {
        double price = monte_carlo_pricing(option_type, start_price, strike_price, volatility, days, simulations);
        std::cout << "Estimated option price: " << price << std::endl;
    }
    return 0;
}