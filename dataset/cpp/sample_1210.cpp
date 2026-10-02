#include <iostream>
#include <vector>
#include <limits>

std::vector<std::pair<int, int>> optimize_supply_chain(const std::vector<std::pair<int, int>>& data) {
    if (data.empty()) {
        return {};
    }
    int cost = std::numeric_limits<int>::max();
    std::vector<std::pair<int, int>> route;
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = i + 1; j < data.size(); ++j) {
            int temp_cost = data[i].first + data[j].second;
            if (temp_cost < cost) {
                cost = temp_cost;
                route = {data[i], data[j]};
            }
        }
    }
    return route;
}

int main() {
    std::vector<std::pair<int, int>> data = {{10, 20}, {15, 25}, {5, 30}, {20, 10}};
    std::vector<std::pair<int, int>> result = optimize_supply_chain(data);
    for (const auto& pair : result) {
        std::cout << "(" << pair.first << ", " << pair.second << ")";
    }
    return 0;
}