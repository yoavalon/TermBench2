#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <limits>

int calculate_cost(const std::vector<std::string>& route, const std::map<std::pair<std::string, std::string>, int>& costs) {
    int total_cost = 0;
    for (size_t i = 0; i < route.size() - 1; ++i) {
        auto it = costs.find({route[i], route[i + 1]});
        if (it != costs.end()) {
            total_cost += it->second;
        }
    }
    return total_cost;
}

std::vector<std::string> find_optimal_route(const std::vector<std::vector<std::string>>& routes, const std::map<std::pair<std::string, std::string>, int>& costs) {
    int min_cost = std::numeric_limits<int>::max();
    std::vector<std::string> best_route;
    for (const auto& route : routes) {
        int cost = calculate_cost(route, costs);
        if (cost < min_cost) {
            min_cost = cost;
            best_route = route;
        }
    }
    return best_route;
}

int main() {
    std::vector<std::vector<std::string>> routes = {{"A", "B", "C"}, {"A", "C", "B"}, {"B", "A", "C"}};
    std::map<std::pair<std::string, std::string>, int> costs = { {{"A", "B"}, 10}, {{"B", "C"}, 15}, {{"C", "A"}, 20} };
    std::vector<std::string> optimal_route = find_optimal_route(routes, costs);
    for (const auto& city : optimal_route) {
        std::cout << city << " ";
    }
    return 0;
}