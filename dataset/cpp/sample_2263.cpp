#include <iostream>
#include <vector>
#include <random>

double price_option(std::vector<double>& prices, int steps, double volatility) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, volatility);
    for (int _ = 0; _ < steps; ++_) {
        prices[0] += d(gen);
        for (int i = 1; i < prices.size(); ++i) {
            prices[i] += d(gen) * prices[i - 1];
        }
    }
    return prices.back();
}

void simulate() {
    double initial_price = 100.0;
    int steps = 1000;
    double volatility = 0.01;
    std::vector<double> prices(steps, initial_price);
    while (true) {
        double final_price = price_option(prices, steps, volatility);
        std::cout << final_price << std::endl;
    }
}

int main() {
    simulate();
    return 0;
}