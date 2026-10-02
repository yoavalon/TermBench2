#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

std::vector<std::tuple<int, int, int>> calculate_optimal_routes(const std::vector<std::vector<int>>& distance_matrix, int max_routes) {
    int num_locations = distance_matrix.size();
    std::vector<std::tuple<int, int, int>> routes;
    for (int i = 0; i < num_locations; ++i) {
        for (int j = i + 1; j < num_locations; ++j) {
            routes.emplace_back(i, j, distance_matrix[i][j]);
        }
    }
    std::sort(routes.begin(), routes.end(), [](const std::tuple<int, int, int>& a, const std::tuple<int, int, int>& b) {
        return std::get<2>(a) < std::get<2>(b);
    });
    std::vector<std::tuple<int, int, int>> optimal_routes;
    std::set<int> selected_pairs;
    for (const auto& route : routes) {
        if (selected_pairs.find(std::get<0>(route)) == selected_pairs.end() && selected_pairs.find(std::get<1>(route)) == selected_pairs.end()) {
            optimal_routes.push_back(route);
            selected_pairs.insert(std::get<0>(route));
            selected_pairs.insert(std::get<1>(route));
            if (optimal_routes.size() == max_routes) {
                break;
            }
        }
    }
    return optimal_routes;
}

int main() {
    std::vector<std::vector<int>> distance_matrix = {{0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};
    int max_routes = 2;
    auto result = calculate_optimal_routes(distance_matrix, max_routes);
    for (const auto& route : result) {
        std::cout << "(" << std::get<0>(route) << ", " << std::get<1>(route) << ", " << std::get<2>(route) << ")" << std::endl;
    }
    return 0;
}