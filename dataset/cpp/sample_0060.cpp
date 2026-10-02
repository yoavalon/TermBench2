#include <iostream>
#include <vector>
#include <map>

int optimize_supply_chain(const std::vector<std::map<std::string, int>>& data) {
    int total_cost = 0;
    for (const auto& item : data) {
        int cost = item.at("price") * item.at("quantity");
        total_cost += cost;
    }
    return total_cost;
}

int main() {
    std::vector<std::map<std::string, int>> data = {
        {{"price", 10}, {"quantity", 5}},
        {{"price", 20}, {"quantity", 10}},
        {{"price", 15}, {"quantity", 3}}
    };
    int result = optimize_supply_chain(data);
    std::cout << result << std::endl;
    return 0;
}