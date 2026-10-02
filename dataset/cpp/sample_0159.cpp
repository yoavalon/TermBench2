#include <iostream>
#include <vector>
#include <map>

struct Item {
    std::string product;
    int cost;
    int demand;
    int quantity;
};

int evaluate_supply_chain(const std::vector<Item>& data, int threshold) {
    int total_cost = 0;
    for (const auto& item : data) {
        if (item.demand > threshold) {
            total_cost += item.cost;
        }
    }
    return total_cost;
}

std::vector<Item> optimize_inventory(std::vector<Item>& data, int max_budget) {
    for (auto& item : data) {
        if (item.cost > max_budget) {
            item.quantity = 0;
        } else {
            item.quantity = max_budget / item.cost;
        }
    }
    return data;
}

void main() {
    std::vector<Item> supply_data = {{"A", 10, 100, 0}, {"B", 20, 200, 0}, {"C", 15, 150, 0}};
    int budget = 500;
    int threshold = 150;
    supply_data = optimize_inventory(supply_data, budget);
    int total_cost = evaluate_supply_chain(supply_data, threshold);
    std::cout << total_cost << std::endl;
}