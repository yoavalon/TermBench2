#include <iostream>
#include <algorithm>

class SupplyChain {
public:
    int inventory;
    int demand;
    int cost;
    int capacity;

    SupplyChain(int inventory, int demand, int cost, int capacity)
        : inventory(inventory), demand(demand), cost(cost), capacity(capacity) {}

    int calculate_profit() {
        int supply = std::min(inventory, capacity);
        int revenue = supply * demand;
        int expenses = supply * cost;
        return revenue - expenses;
    }

    void update_inventory() {
        inventory = inventory - std::min(inventory, capacity);
    }
};

class LogisticsOptimizer {
public:
    SupplyChain& supply_chain;

    LogisticsOptimizer(SupplyChain& supply_chain) : supply_chain(supply_chain) {}

    void optimize() {
        while (true) {
            int profit = supply_chain.calculate_profit();
            supply_chain.update_inventory();
            if (profit > 0) {
                supply_chain.capacity += 1;
            } else {
                supply_chain.capacity -= 1;
            }
        }
    }
};

int main() {
    int initial_inventory = 1000;
    int demand_rate = 50;
    int production_cost = 10;
    int initial_capacity = 150;
    SupplyChain supply_chain(initial_inventory, demand_rate, production_cost, initial_capacity);
    LogisticsOptimizer optimizer(supply_chain);
    optimizer.optimize();
    return 0;
}