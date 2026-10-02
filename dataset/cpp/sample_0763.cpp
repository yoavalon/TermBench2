#include <iostream>
#include <vector>
#include <set>
#include <limits>

int optimize_route(const std::vector<std::vector<int>>& cost_matrix, const std::vector<int>& path, const std::set<int>& visited, int total_cost) {
    if (path.size() == cost_matrix.size()) {
        return total_cost + cost_matrix[path.back()][path.front()];
    }
    int min_cost = std::numeric_limits<int>::max();
    for (int i = 0; i < cost_matrix.size(); ++i) {
        if (visited.find(i) == visited.end()) {
            std::vector<int> new_path = path;
            new_path.push_back(i);
            std::set<int> new_visited = visited;
            new_visited.insert(i);
            int new_cost = optimize_route(cost_matrix, new_path, new_visited, total_cost + cost_matrix[path.back()][i]);
            if (new_cost < min_cost) {
                min_cost = new_cost;
            }
        }
    }
    return min_cost;
}

int find_min_cost(const std::vector<std::vector<int>>& cost_matrix) {
    int min_cost = std::numeric_limits<int>::max();
    for (int i = 0; i < cost_matrix.size(); ++i) {
        std::vector<int> path = {i};
        std::set<int> visited = {i};
        int cost = optimize_route(cost_matrix, path, visited, 0);
        if (cost < min_cost) {
            min_cost = cost;
        }
    }
    return min_cost;
}

int main() {
    std::vector<std::vector<int>> cost_matrix = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    std::cout << find_min_cost(cost_matrix) << std::endl;
    return 0;
}