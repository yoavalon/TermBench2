#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<double> generate_random_numbers(int n) {
    std::vector<double> numbers;
    for (int i = 0; i < n; ++i) {
        numbers.push_back(static_cast<double>(rand()) / RAND_MAX * 1000000);
    }
    return numbers;
}

double calculate_option_price(const std::vector<double>& prices, double strike, double rate, double time) {
    double total = 0;
    for (double price : prices) {
        double payoff = std::max(price - strike, 0.0);
        double discounted_payoff = payoff * (1 / (1 + rate * time));
        total += discounted_payoff;
    }
    return total / prices.size();
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    while (true) {
        int n = 1000;
        std::vector<double> prices = generate_random_numbers(n);
        double strike = 500000;
        double rate = 0.05;
        double time = 1;
        double option_price = calculate_option_price(prices, strike, rate, time);
        std::cout << "Calculated Option Price: " << option_price << std::endl;
    }
    return 0;
}