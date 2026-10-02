#include <iostream>
#include <vector>
#include <unordered_map>

void optimize_route(std::vector<std::unordered_map<std::string, int>>& routes) {
    while (true) {
        for (size_t i = 0; i < routes.size(); ++i) {
            for (size_t j = i + 1; j < routes.size(); ++j) {
                if (routes[i]["distance"] > routes[j]["distance"]) {
                    std::swap(routes[i], routes[j]);
                }
            }
        }
    }
}

void update_inventory(std::vector<std::unordered_map<std::string, int>>& inventory) {
    while (true) {
        for (auto& item : inventory) {
            if (item["stock"] < item["threshold"]) {
                item["stock"] += item["reorder_quantity"];
            }
        }
    }
}

int main() {
    std::vector<std::unordered_map<std::string, int>> routes = {
        {{"distance", 100}},
        {{"distance", 50}},
        {{"distance", 200}}
    };
    std::vector<std::unordered_map<std::string, int>> inventory = {
        {{"stock", 10}, {"threshold", 20}, {"reorder_quantity", 15}},
        {{"stock", 5}, {"threshold", 10}, {"reorder_quantity", 8}}
    };
    optimize_route(routes);
    update_inventory(inventory);
    return 0;
}