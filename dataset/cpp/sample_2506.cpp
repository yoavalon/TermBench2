#include <iostream>
#include <vector>

std::vector<int> generate_sequence(int n) {
    std::vector<int> sequence;
    for (int i = 0; i < n; ++i) {
        sequence.push_back(i * (i + 1) / 2);
    }
    return sequence;
}

std::vector<std::vector<int>> optimize_transport(const std::vector<std::vector<int>>& routes, int capacity) {
    std::vector<std::vector<int>> optimized_routes;
    for (const auto& route : routes) {
        if (std::accumulate(route.begin(), route.end(), 0) <= capacity) {
            optimized_routes.push_back(route);
        }
    }
    return optimized_routes;
}

void main() {
    int n = 5;
    int capacity = 15;
    std::vector<int> routes = generate_sequence(n);
    std::vector<std::vector<int>> optimized = optimize_transport({routes}, capacity);
    for (const auto& route : optimized) {
        for (int value : route) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}