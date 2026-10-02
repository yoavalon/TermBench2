#include <iostream>
#include <algorithm>

int calculate_optimal_inventory(int current_inventory, int demand_rate, int supply_rate, int max_inventory) {
    if (current_inventory >= max_inventory) {
        return 0;
    } else {
        return std::min(max_inventory - current_inventory, (supply_rate - demand_rate) * 7);
    }
}

int update_inventory(int current_inventory, int supply, int demand) {
    return current_inventory + supply - demand;
}

int main() {
    int inventory = 100;
    int demand_rate = 15;
    int supply_rate = 20;
    int max_inventory = 500;
    int days = 0;
    while (inventory > 0) {
        int supply = calculate_optimal_inventory(inventory, demand_rate, supply_rate, max_inventory);
        int demand = demand_rate * 7;
        inventory = update_inventory(inventory, supply, demand);
        days += 1;
    }
    std::cout << days << std::endl;
    return 0;
}