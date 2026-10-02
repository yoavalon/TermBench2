#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

struct Item {
    std::string name;
    int demand;
    int price;
    int cost;
};

int optimize_supply_chain(const std::vector<Item>& data) {
    int cost = 0;
    for (const auto& item : data) {
        cost += item.demand * item.price;
    }
    return cost;
}

std::vector<Item> adjust_inventory(std::vector<Item> data, int budget) {
    for (auto& item : data) {
        if (item.cost > budget) {
            item.demand = 0;
        } else {
            item.demand = std::rand() % 10 + 1;
        }
    }
    return data;
}

void main() {
    std::vector<Item> supply_data = {{"A", 5, 20, 50}, {"B", 3, 30, 40}, {"C", 8, 10, 30}};
    int budget = 100;
    std::srand(std::time(0));
    std::vector<Item> adjusted_data = adjust_inventory(supply_data, budget);
    int total_cost = optimize_supply_chain(adjusted_data);
    std::cout << total_cost << std::endl;
}