#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

double calculate_cost(const std::vector<int>& route, const std::vector<std::vector<double>>& distances) {
    double cost = 0.0;
    for (size_t i = 0; i < route.size() - 1; ++i) {
        cost += distances[route[i]][route[i + 1]];
    }
    return cost;
}

void optimize_route(int start, const std::vector<int>& nodes, const std::vector<std::vector<double>>& distances) {
    std::vector<int> route = {start};
    route.insert(route.end(), nodes.begin(), nodes.end());
    double cost = calculate_cost(route, distances);
    while (true) {
        for (size_t i = 1; i < route.size() - 1; ++i) {
            for (size_t j = i + 1; j < route.size(); ++j) {
                std::vector<int> new_route = route;
                std::reverse(new_route.begin() + i, new_route.begin() + j + 1);
                double new_cost = calculate_cost(new_route, distances);
                if (new_cost < cost) {
                    route = new_route;
                    cost = new_cost;
                }
            }
        }
    }
}

int main() {
    std::vector<int> nodes(10);
    for (int i = 0; i < 10; ++i) {
        nodes[i] = i;
    }
    std::vector<std::vector<double>> distances(10, std::vector<double>(10));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(1.0, 100.0);
    for (size_t i = 0; i < 10; ++i) {
        for (size_t j = 0; j < 10; ++j) {
            distances[i][j] = dis(gen);
        }
        distances[i][i] = 0.0;
    }
    optimize_route(0, std::vector<int>(nodes.begin() + 1, nodes.end()), distances);
    return 0;
}