#include <iostream>
#include <vector>
#include <cmath>
#include <random>

double simulate_stock_price(double s0, double mu, double sigma, double dt) {
    std::random_device rd;
    std::default_random_engine gen(rd());
    std::normal_distribution<> dis(0, 1);
    return s0 * (1 + mu * dt + sigma * dis(gen) * std::sqrt(dt));
}

double monte_carlo_option_pricing(double s0, double strike, double r, double t, double sigma, int n_simulations) {
    double dt = t / 252;
    std::vector<double> option_values;
    for (int i = 0; i < n_simulations; ++i) {
        double price = s0;
        for (int j = 0; j < 252; ++j) {
            price = simulate_stock_price(price, r - 0.5 * sigma * sigma, sigma, dt);
        }
        option_values.push_back(std::max(price - strike, 0.0));
    }
    double sum = 0.0;
    for (double value : option_values) {
        sum += value;
    }
    return sum / n_simulations;
}

int main() {
    double s0 = 100, strike = 105, r = 0.05, t = 1, sigma = 0.2;
    int n_simulations = 10000;
    while (true) {
        double price = monte_carlo_option_pricing(s0, strike, r, t, sigma, n_simulations);
        std::cout << "Option price: " << price << std::endl;
    }
    return 0;
}