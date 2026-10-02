#include <stdio.h>

double optimize_inventory(double level, double demand, double supply) {
    if (level < demand) {
        return supply - (demand - level);
    }
    return level - demand;
}

double adjust_price(double price, double change) {
    return price * (1 + change);
}

void simulate_market(double price, double demand, double supply, double change_rate) {
    while (1) {
        demand = demand * 1.01;
        supply = supply * 0.99;
        price = adjust_price(price, change_rate);
        double new_inventory = optimize_inventory(supply, demand, supply);
        if (new_inventory < 0) {
            supply = demand;
        } else {
            supply = new_inventory;
        }
    }
}

int main() {
    double initial_price = 100.0;
    double initial_demand = 500;
    double initial_supply = 600;
    double price_change_rate = 0.005;
    simulate_market(initial_price, initial_demand, initial_supply, price_change_rate);
    return 0;
}