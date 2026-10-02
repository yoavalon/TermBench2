#include <iostream>
#include <cmath>
#include <cstdlib>

double simulate_stock_price(int steps, double initial_price, double drift, double volatility) {
    double price = initial_price;
    for (int _ = 0; _ < steps; ++_) {
        price += price * (drift + volatility * std::sqrt(-2.0 * std::log(static_cast<double>(rand()) / RAND_MAX)) * std::cos(2.0 * M_PI * static_cast<double>(rand()) / RAND_MAX));
    }
    return price;
}

double price_option(double (*pricing_function)(int, double, double, double), double initial_price, double strike_price, int steps, double drift, double volatility, int simulations) {
    double total = 0;
    for (int _ = 0; _ < simulations; ++_) {
        double final_price = pricing_function(steps, initial_price, drift, volatility);
        double payoff = std::max(final_price - strike_price, 0.0);
        total += payoff;
    }
    return total / simulations;
}

int main() {
    double initial_price = 100;
    double strike_price = 100;
    int steps = 100;
    double drift = 0.0001;
    double volatility = 0.01;
    int simulations = 10000;
    double option_price = price_option(&simulate_stock_price, initial_price, strike_price, steps, drift, volatility, simulations);
    std::cout << "Option Price: " << option_price << std::endl;
    return 0;
}