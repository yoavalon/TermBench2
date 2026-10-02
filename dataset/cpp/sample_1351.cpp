#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

std::vector<double> simulate_prices(int steps, double mean, double volatility) {
    std::vector<double> prices(steps);
    prices[0] = 100;
    for (int i = 1; i < steps; ++i) {
        prices[i] = prices[i - 1] * (1 + mean + volatility * sqrt(-2 * log((double)rand() / RAND_MAX)) * cos(2 * M_PI * (double)rand() / RAND_MAX));
    }
    return prices;
}

double calculate_option_value(const std::vector<double>& prices, double strike, double r, double t) {
    double payoff = std::max(prices.back() - strike, 0.0);
    double value = payoff * exp(-r * t);
    return value;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int steps = 100;
    double mean = 0.001;
    double volatility = 0.01;
    double strike = 105;
    double r = 0.05;
    double t = 1.0;
    std::vector<double> prices = simulate_prices(steps, mean, volatility);
    double option_value = calculate_option_value(prices, strike, r, t);
    std::cout << option_value << std::endl;
    return 0;
}