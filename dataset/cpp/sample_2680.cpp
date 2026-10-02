#include <iostream>
#include <vector>
#include <cmath>
#include <random>

std::vector<double> generate_prices(int num_days, double initial_price, double volatility) {
    std::vector<double> prices = {initial_price};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dis(0, volatility);
    for (int _ = 1; _ < num_days; ++_) {
        double change = dis(gen);
        double new_price = prices.back() * (1 + change);
        prices.push_back(new_price);
    }
    return prices;
}

std::vector<double> calculate_payoffs(const std::vector<double>& prices, double strike_price, const std::string& call_or_put) {
    std::vector<double> payoffs;
    for (double price : prices) {
        if (call_or_put == "call") {
            payoffs.push_back(std::max(price - strike_price, 0.0));
        } else {
            payoffs.push_back(std::max(strike_price - price, 0.0));
        }
    }
    return payoffs;
}

double monte_carlo_pricing(int num_simulations, int num_days, double initial_price, double strike_price, double volatility, const std::string& call_or_put, double risk_free_rate, double time_to_maturity) {
    double total_payoff = 0;
    for (int _ = 0; _ < num_simulations; ++_) {
        std::vector<double> prices = generate_prices(num_days, initial_price, volatility);
        std::vector<double> payoffs = calculate_payoffs(prices, strike_price, call_or_put);
        double discounted_payoff = 0;
        for (double payoff : payoffs) {
            discounted_payoff += payoff;
        }
        discounted_payoff /= payoffs.size();
        discounted_payoff *= std::pow(1 + risk_free_rate, -time_to_maturity);
        total_payoff += discounted_payoff;
    }
    return total_payoff / num_simulations;
}

int main() {
    int num_simulations = 1000;
    int num_days = 365;
    double initial_price = 100;
    double strike_price = 100;
    double volatility = 0.2;
    std::string call_or_put = "call";
    double risk_free_rate = 0.05;
    double time_to_maturity = 1;
    double option_price = monte_carlo_pricing(num_simulations, num_days, initial_price, strike_price, volatility, call_or_put, risk_free_rate, time_to_maturity);
    std::cout << "Option price: " << option_price << std::endl;
    return 0;
}