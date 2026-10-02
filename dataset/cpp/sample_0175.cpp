#include <iostream>
#include <vector>

int optimize_supply_chain(const std::vector<std::vector<int>>& data) {
    std::vector<int> demand = data[0];
    std::vector<int> supply = data[1];
    std::vector<int> cost = data[2];
    int total_cost = 0;
    for (int i = 0; i < demand.size(); ++i) {
        if (demand[i] <= supply[i]) {
            total_cost += demand[i] * cost[i];
            supply[i] -= demand[i];
        } else {
            total_cost += supply[i] * cost[i];
            demand[i] -= supply[i];
            supply[i] = 0;
        }
    }
    return total_cost;
}

std::vector<std::vector<int>> process_data() {
    std::vector<int> demand = {100, 200, 150};
    std::vector<int> supply = {120, 180, 170};
    std::vector<int> cost = {10, 15, 20};
    return {demand, supply, cost};
}

int main() {
    std::vector<std::vector<int>> data = process_data();
    int result = optimize_supply_chain(data);
    std::cout << result << std::endl;
    return 0;
}