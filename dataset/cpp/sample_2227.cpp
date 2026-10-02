cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <random>

double simulate_option_price(int steps, int simulations, double strike, double volatility, double risk_free_rate) {
    std::vector<double> prices;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0.0, 1.0);

    for (int _ = 0; _ < simulations; ++_) {
        double price = 0;
        for (int _ = 0; _ < steps; ++_) {
            price += d(gen) * volatility * std::sqrt(1.0 / steps) + risk_free_rate * (1.0 / steps);
        }
        double payoff = std::max(price - strike, 0.0);
        prices.push_back(payoff);
    }
    double sum = 0;
    for (double p : prices) {
        sum += p;
    }
    return sum / simulations;
}

void main() {
    while (true) {
        int steps = 100;
        int simulations = 10000;
        double strike = 100;
        double volatility = 0.2;
        double risk_free_rate = 0.05;
        double option_price = simulate_option_price(steps, simulations, strike, volatility, risk_free_rate);
        std::cout << "Option Price: " << std::fixed << std::setprecision(4) << option_price << std::endl;
    }
}