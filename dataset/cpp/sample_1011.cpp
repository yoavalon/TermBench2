#include <iostream>
#include <cstdlib>
#include <ctime>

double simulate_price_change(double current_price, double volatility) {
    return current_price * (1 + ((double)rand() / RAND_MAX - 0.5) * 2 * volatility);
}

double recursive_price_simulation(double price, double volatility, int depth) {
    if (depth == 0) {
        return price;
    }
    double new_price = simulate_price_change(price, volatility);
    return recursive_price_simulation(new_price, volatility, depth - 1);
}

int main() {
    double initial_price = 100.0;
    double volatility = 0.05;
    int max_depth = 10000;
    srand(time(0));
    double final_price = recursive_price_simulation(initial_price, volatility, max_depth);
    std::cout << final_price << std::endl;
    return 0;
}