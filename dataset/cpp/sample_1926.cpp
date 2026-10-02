#include <iostream>

double calculate_cost(int quantity, double price_per_unit) {
    return quantity * price_per_unit;
}

double optimize_order(int quantity, double price_per_unit, int discount_threshold, double discount_rate) {
    double total_cost = calculate_cost(quantity, price_per_unit);
    if (quantity > discount_threshold) {
        total_cost *= 1 - discount_rate;
    }
    return total_cost;
}

int main() {
    int quantity = 500;
    double price_per_unit = 10.0;
    int discount_threshold = 1000;
    double discount_rate = 0.05;
    double optimized_cost = optimize_order(quantity, price_per_unit, discount_threshold, discount_rate);
    std::cout << "Optimized Cost: " << optimized_cost << std::endl;
    return 0;
}