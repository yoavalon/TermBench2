#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> update_demands(const std::vector<int>& demands, const std::vector<int>& adjustments) {
    std::vector<int> updated_demands;
    for (size_t i = 0; i < demands.size(); ++i) {
        updated_demands.push_back(demands[i] + adjustments[i]);
    }
    return updated_demands;
}

int optimize_route(const std::vector<std::vector<int>>& routes, const std::vector<int>& demands) {
    std::vector<int> costs;
    for (const auto& r : routes) {
        int cost = 0;
        for (size_t i = 0; i < demands.size(); ++i) {
            cost += demands[i] * r[i];
        }
        costs.push_back(cost);
    }
    return *std::min_element(costs.begin(), costs.end());
}

int main() {
    std::vector<std::vector<int>> routes = {{2, 3, 1}, {4, 1, 2}, {3, 2, 3}};
    std::vector<int> demands = {5, 10, 15};
    std::vector<int> adjustments = {-1, 2, -3};
    std::vector<int> updated_demands = update_demands(demands, adjustments);
    int best_cost = optimize_route(routes, updated_demands);
    std::cout << best_cost << std::endl;
    return 0;
}