#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> optimize_routes(std::vector<std::vector<int>>& routes, std::vector<int>& demands, std::vector<int>& capacities) {
    for (int i = 0; i < routes.size(); ++i) {
        if (demands[i] > capacities[i]) {
            routes = redistribute_load(routes, demands, capacities, i);
        }
    }
    return routes;
}

std::vector<std::vector<int>> redistribute_load(std::vector<std::vector<int>>& routes, std::vector<int>& demands, std::vector<int>& capacities, int index) {
    int excess = demands[index] - capacities[index];
    for (int j = 0; j < routes.size(); ++j) {
        if (j != index && capacities[j] > 0) {
            int transfer = std::min(excess, capacities[j]);
            demands[j] += transfer;
            demands[index] -= transfer;
            excess -= transfer;
            if (excess == 0) {
                break;
            }
        }
    }
    return routes;
}

void main() {
    std::vector<std::vector<int>> routes = {{1, 2}, {3, 4}, {5, 6}};
    std::vector<int> demands = {10, 15, 20};
    std::vector<int> capacities = {10, 10, 10};
    std::vector<std::vector<int>> optimized_routes = optimize_routes(routes, demands, capacities);
    for (const auto& route : optimized_routes) {
        for (int item : route) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
}