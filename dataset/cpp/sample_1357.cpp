#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>

std::vector<int> optimize_routes(const std::vector<std::vector<int>>& data) {
    std::vector<int> costs = data[0];
    std::vector<int> optimal_indices(data[0].size(), 0);
    
    for (size_t i = 1; i < data.size(); ++i) {
        for (size_t j = 0; j < data[i].size(); ++j) {
            if (data[i][j] < costs[j]) {
                costs[j] = data[i][j];
                optimal_indices[j] = i;
            }
        }
    }
    
    return optimal_indices;
}

std::vector<int> update_inventory(const std::vector<int>& routes, std::vector<int> inventory) {
    for (int route : routes) {
        inventory[route] -= 1;
    }
    return inventory;
}

int main() {
    std::vector<std::vector<int>> data = {{5, 3, 8}, {2, 6, 4}, {7, 1, 9}};
    std::vector<int> inventory = {10, 10, 10};
    std::vector<int> routes = optimize_routes(data);
    std::vector<int> updated_inventory = update_inventory(routes, inventory);
    
    for (int item : updated_inventory) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    
    return 0;
}