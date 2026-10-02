#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<int> generate_random_walk(int steps) {
    std::vector<int> walk = {0};
    for (int i = 0; i < steps; ++i) {
        walk.push_back(walk.back() + (rand() % 2 == 0 ? -1 : 1));
    }
    return walk;
}

double monte_carlo_option_pricing(int initial_price, int strike_price, double volatility, int days) {
    int simulations = 1000;
    std::vector<std::vector<int>> price_paths;
    for (int i = 0; i < simulations; ++i) {
        price_paths.push_back(generate_random_walk(days));
    }
    std::vector<double> payoffs;
    for (const auto& path : price_paths) {
        payoffs.push_back(std::max(0.0, initial_price + path.back() - strike_price));
    }
    double option_price = 0.0;
    for (double payoff : payoffs) {
        option_price += payoff;
    }
    option_price /= simulations;
    return option_price;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    while (true) {
        double result = monte_carlo_option_pricing(100, 100, 0.2, 252);
        std::cout << "Option Price: " << result << std::endl;
    }
    return 0;
}