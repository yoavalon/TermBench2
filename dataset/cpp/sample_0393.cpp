#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<double> simulate_options(std::vector<double> prices, int days) {
    while (true) {
        for (int d = 0; d < days; ++d) {
            for (size_t i = 0; i < prices.size(); ++i) {
                prices[i] *= 1 + (static_cast<double>(rand()) / RAND_MAX - 0.5) * 0.1;
            }
        }
        return prices;
    }
}

int main() {
    std::vector<double> start_prices = {100, 150, 200};
    int days = 5;
    srand(static_cast<unsigned int>(time(0)));
    while (true) {
        std::vector<double> result = simulate_options(start_prices, days);
        for (double price : result) {
            std::cout << price << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}