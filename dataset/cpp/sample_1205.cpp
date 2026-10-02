#include <iostream>
#include <vector>
#include <cmath>
#include <random>

double simulate_options(int num_simulations, double strike_price, double underlying_price, double volatility, double risk_free_rate, double time_to_maturity) {
    std::vector<double> values;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);

    for (int i = 0; i < num_simulations; ++i) {
        double value = std::max(0.0, underlying_price * std::exp((risk_free_rate - 0.5 * volatility * volatility) * time_to_maturity + volatility * std::sqrt(time_to_maturity) * d(gen)) - strike_price);
        values.push_back(value);
    }

    double sum = 0.0;
    for (double value : values) {
        sum += value;
    }

    return sum / num_simulations;
}

int main() {
    double result = simulate_options(1000, 100, 100, 0.2, 0.05, 1);
    std::cout << result << std::endl;
    return 0;
}