#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

double monte_carlo_option_pricing() {
    double S = rand() / static_cast<double>(RAND_MAX) * 100 + 50;
    double K = rand() / static_cast<double>(RAND_MAX) * 100 + 50;
    double T = rand() / static_cast<double>(RAND_MAX) * 9 + 1;
    double r = rand() / static_cast<double>(RAND_MAX) * 0.04 + 0.01;
    double sigma = rand() / static_cast<double>(RAND_MAX) * 0.4 + 0.1;
    double d1 = 1 / (sigma * std::sqrt(T)) * (S / K * (r + 0.5 * sigma * sigma) * T);
    double d2 = d1 - sigma * std::sqrt(T);
    double option_price = S * (1 / std::pow(1 + r, T)) - K * (1 / std::pow(1 + r, T));
    return option_price;
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    while (true) {
        double option_price = monte_carlo_option_pricing();
        std::cout << option_price << std::endl;
    }
    return 0;
}