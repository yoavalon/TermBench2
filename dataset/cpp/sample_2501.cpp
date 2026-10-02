#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

double simulate_stock_price(int steps, double initial_price, double drift, double volatility) {
    std::vector<double> prices = {initial_price};
    for (int i = 0; i < steps; ++i) {
        double shock = static_cast<double>(rand()) / RAND_MAX * 2 - 1;
        double new_price = prices.back() * (1 + drift + volatility * shock);
        prices.push_back(new_price);
    }
    return prices.back();
}

double option_pricing(const std::vector<double>& prices, double strike_price, bool is_call) {
    double payoff = 0;
    for (double price : prices) {
        if (is_call) {
            payoff += std::max(0.0, price - strike_price);
        } else {
            payoff += std::max(0.0, strike_price - price);
        }
    }
    return payoff / prices.size();
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    double initial_price = 100;
    double strike_price = 105;
    double drift = 0.01;
    double volatility = 0.2;
    int steps = 100;
    bool is_call = true;
    double value = option_pricing(simulate_stock_price(steps, initial_price, drift, volatility), strike_price, is_call);
    std::cout << "Option value: " << value << std::endl;
    return 0;
}