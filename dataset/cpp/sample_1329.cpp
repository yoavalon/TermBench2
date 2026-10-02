#include <iostream>
#include <vector>
#include <numeric>

std::vector<int> calculate_route_costs(const std::vector<std::vector<int>>& routes) {
    std::vector<int> costs;
    for (const auto& route : routes) {
        int cost = std::accumulate(route.begin(), route.end(), 0);
        costs.push_back(cost);
    }
    return costs;
}

std::vector<std::vector<int>> optimize_routes(const std::vector<std::vector<int>>& routes, const std::vector<int>& budgets) {
    std::vector<std::vector<int>> optimized_routes;
    for (size_t i = 0; i < routes.size(); ++i) {
        if (std::accumulate(routes[i].begin(), routes[i].end(), 0) <= budgets[i]) {
            optimized_routes.push_back(routes[i]);
        }
    }
    return optimized_routes;
}

int main() {
    std::vector<std::vector<int>> routes = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}};
    std::vector<int> budgets = {150, 200, 250};
    std::vector<int> costs = calculate_route_costs(routes);
    std::vector<std::vector<int>> optimized_routes = optimize_routes(routes, budgets);
    for (const auto& route : optimized_routes) {
        for (int cost : route) {
            std::cout << cost << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}