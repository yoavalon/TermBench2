#include <iostream>
#include <vector>
#include <set>
#include <limits>

int optimize_route(const std::vector<std::vector<int>>& cost_matrix, const std::vector<int>& current_route, const std::set<int>& visited, int total_cost) {
    if (current_route.size() == cost_matrix.size()) {
        return total_cost;
    }
    int min_cost = std::numeric_limits<int>::max();
    for (int i = 0; i < cost_matrix.size(); ++i) {
        if (visited.find(i) == visited.end()) {
            std::set<int> new_visited = visited;
            new_visited.insert(i);
            std::vector<int> new_route = current_route;
            new_route.push_back(i);
            int cost = optimize_route(cost_matrix, new_route, new_visited, total_cost + cost_matrix[current_route.back()][i]);
            if (cost < min_cost) {
                min_cost = cost;
            }
        }
    }
    return min_cost;
}

int main() {
    std::vector<std::vector<int>> cost_matrix = {{0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};
    std::vector<int> initial_route = {0};
    std::set<int> visited = {0};
    int result = optimize_route(cost_matrix, initial_route, visited, 0);
    std::cout << result << std::endl;
    return 0;
}