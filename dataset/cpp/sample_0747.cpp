#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <limits>

int optimize_route(const std::unordered_map<char, std::vector<std::pair<char, int>>>& routes, 
                    std::unordered_set<char>& visited, char current, char destination, int cost) {
    if (current == destination) {
        return cost;
    }
    int min_cost = std::numeric_limits<int>::max();
    for (const auto& route : routes.at(current)) {
        if (visited.find(route.first) == visited.end()) {
            visited.insert(route.first);
            int new_cost = optimize_route(routes, visited, route.first, destination, cost + route.second);
            visited.erase(route.first);
            if (new_cost < min_cost) {
                min_cost = new_cost;
            }
        }
    }
    return min_cost;
}

int find_optimal_path(const std::unordered_map<char, std::vector<std::pair<char, int>>>& routes, char start, char end) {
    std::unordered_set<char> visited = {start};
    return optimize_route(routes, visited, start, end, 0);
}

int main() {
    std::unordered_map<char, std::vector<std::pair<char, int>>> routes = {
        {'A', {{'B', 10}, {'C', 15}}},
        {'B', {{'C', 35}, {'D', 25}}},
        {'C', {{'D', 30}}},
        {'D', {}}
    };
    char start = 'A';
    char end = 'D';
    std::cout << find_optimal_path(routes, start, end) << std::endl;
    return 0;
}