cpp
#include <iostream>
#include <vector>
#include <algorithm>

int optimize_supply_chain(const std::vector<std::vector<int>>& costs, int index, int result) {
    if (index == costs.size()) {
        return result;
    }
    int min_cost = *std::min_element(costs[index].begin(), costs[index].end());
    return optimize_supply_chain(costs, index + 1, result + min_cost);
}

int main() {
    std::vector<std::vector<int>> costs = {{10, 20, 30}, {15, 25, 35}, {5, 15, 25}};
    std::cout << optimize_supply_chain(costs, 0, 0) << std::endl;
    return 0;
}