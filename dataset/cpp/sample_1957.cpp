#include <iostream>
#include <vector>
#include <random>

std::vector<std::vector<double>> simulate_prices(int steps, int simulations) {
    std::vector<std::vector<double>> prices(steps, std::vector<double>(simulations));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0.05, 0.2);

    for (int i = 0; i < steps; ++i) {
        for (int j = 0; j < simulations; ++j) {
            prices[i][j] = d(gen);
        }
    }
    return prices;
}

double calculate_option_value(const std::vector<std::vector<double>>& prices, double strike) {
    double sum = 0.0;
    int n = prices.size();
    int m = prices[0].size();
    for (int i = 0; i < m; ++i) {
        sum += std::max(prices[n - 1][i] - strike, 0.0);
    }
    return sum / m;
}

int main() {
    int steps = 100;
    int simulations = 1000;
    double strike = 100;
    auto prices = simulate_prices(steps, simulations);
    double value = calculate_option_value(prices, strike);
    std::cout << value << std::endl;
    return 0;
}