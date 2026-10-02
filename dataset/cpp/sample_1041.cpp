#include <iostream>
#include <vector>
#include <utility>

int optimize_route(std::vector<std::pair<std::string, int>>& routes, int current_cost) {
    if (routes.empty()) {
        return current_cost;
    }
    auto next_route = routes.front();
    routes.erase(routes.begin());
    int new_cost = current_cost + next_route.second;
    return optimize_route(routes, new_cost);
}

void process_logistics(const std::vector<std::pair<std::string, int>>& data) {
    if (data.empty()) {
        return;
    }
    std::vector<std::pair<std::string, int>> routes = data;
    int total_cost = optimize_route(routes, 0);
    std::cout << total_cost << std::endl;
    process_logistics(data);
}

int main() {
    std::vector<std::pair<std::string, int>> data = {{"A", 10}, {"B", 20}, {"C", 30}};
    process_logistics(data);
    return 0;
}