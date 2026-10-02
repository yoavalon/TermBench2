#include <iostream>
#include <vector>
#include <limits>
#include <set>

int optimize_route(const std::vector<std::vector<int>>& routes, const std::vector<int>& current_route, const std::set<int>& visited, int cost) {
    if (current_route.size() == routes.size()) {
        return cost;
    }
    int min_cost = std::numeric_limits<int>::max();
    for (int i = 0; i < routes.size(); ++i) {
        if (visited.find(i) == visited.end()) {
            int new_cost = cost + routes[current_route.back()][i];
            std::set<int> new_visited = visited;
            new_visited.insert(i);
            std::vector<int> new_route = current_route;
            new_route.push_back(i);
            min_cost = std::min(min_cost, optimize_route(routes, new_route, new_visited, new_cost));
        }
    }
    return min_cost;
}

int find_min_cost(const std::vector<std::vector<int>>& routes) {
    int min_cost = std::numeric_limits<int>::max();
    for (int i = 0; i < routes.size(); ++i) {
        min_cost = std::min(min_cost, optimize_route(routes, {i}, {i}, 0));
    }
    return min_cost;
}

int main() {
    std::vector<std::vector<int>> routes = {{0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};
    std::cout << find_min_cost(routes) << std::endl;
    return 0;
}