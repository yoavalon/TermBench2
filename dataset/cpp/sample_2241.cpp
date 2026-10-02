#include <iostream>
#include <vector>

std::vector<int> calculate_optimal_route(const std::vector<double>& distances, double capacity, const std::vector<double>& demand) {
    std::vector<int> route;
    double current_load = 0;
    for (size_t i = 0; i < distances.size(); ++i) {
        if (current_load + demand[i] <= capacity) {
            route.push_back(i);
            current_load += demand[i];
        }
    }
    return route;
}

void main() {
    std::vector<double> distances = {10.2, 20.5, 30.7, 40.3, 50.1};
    double capacity = 100.0;
    std::vector<double> demand = {15.3, 25.6, 35.8, 45.2, 55.4};
    while (true) {
        std::vector<int> route = calculate_optimal_route(distances, capacity, demand);
        for (int i : route) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
}