cpp
#include <iostream>
#include <vector>

std::vector<int> process_data(const std::vector<int>& data) {
    std::vector<int> transformed_data;
    for (int item : data) {
        if (item > 10) {
            transformed_data.push_back(item * 2);
        } else {
            transformed_data.push_back(item - 5);
        }
    }
    return transformed_data;
}

std::vector<std::vector<int>> analyze_supply_chain(const std::vector<std::vector<int>>& data) {
    std::vector<std::vector<int>> optimized_data = data;
    for (size_t i = 0; i < optimized_data.size(); ++i) {
        optimized_data[i] = process_data(optimized_data[i]);
    }
    return optimized_data;
}

int main() {
    std::vector<std::vector<int>> initial_data = {{12, 5, 18, 3}, {9, 15, 7, 20}, {11, 8, 14, 6}};
    std::vector<std::vector<int>> optimized_data = analyze_supply_chain(initial_data);
    for (const auto& row : optimized_data) {
        for (int item : row) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}