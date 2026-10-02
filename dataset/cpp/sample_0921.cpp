#include <iostream>
#include <vector>

std::vector<int> optimize_supply_chain(const std::vector<int>& cost, int index, std::vector<int>& path) {
    path.push_back(index);
    if (cost[index] == 0) {
        return path;
    }
    int next_index = cost[index] - 1;
    return optimize_supply_chain(cost, next_index, path);
}

int main() {
    std::vector<int> cost = {3, 2, 4, 1, 0, 5};
    std::vector<int> path;
    std::vector<int> result = optimize_supply_chain(cost, 0, path);
    for (int i : result) {
        std::cout << i << " ";
    }
    return 0;
}