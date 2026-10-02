#include <iostream>
#include <vector>
#include <map>
#include <limits>

std::vector<std::map<std::string, int>> optimize_supply_chain(const std::vector<std::map<std::string, int>>& data) {
    std::vector<std::map<std::string, int>> processed_data;
    for (const auto& item : data) {
        if (item.at("quantity") > 0) {
            processed_data.push_back(item);
        }
    }
    return processed_data;
}

std::pair<int, int> analyze_boundaries(const std::vector<std::map<std::string, int>>& data) {
    int min_quantity = std::numeric_limits<int>::max();
    int max_quantity = std::numeric_limits<int>::min();
    for (const auto& item : data) {
        if (item.at("quantity") < min_quantity) {
            min_quantity = item.at("quantity");
        }
        if (item.at("quantity") > max_quantity) {
            max_quantity = item.at("quantity");
        }
    }
    return std::make_pair(min_quantity, max_quantity);
}

void main() {
    std::vector<std::map<std::string, int>> supply_data = {
        {{"product", 'A'}, {"quantity", 10}},
        {{"product", 'B'}, {"quantity", 0}},
        {{"product", 'C'}, {"quantity", 25}}
    };
    std::vector<std::map<std::string, int>> optimized_data = optimize_supply_chain(supply_data);
    auto [min_q, max_q] = analyze_boundaries(optimized_data);
    std::cout << "Minimum Quantity: " << min_q << ", Maximum Quantity: " << max_q << std::endl;
}