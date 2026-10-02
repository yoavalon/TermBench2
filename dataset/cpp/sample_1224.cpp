#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    std::string item;
    int cost;
};

std::vector<Item> optimize_supply_chain(std::vector<Item>& data) {
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = i + 1; j < data.size(); ++j) {
            if (data[i].cost > data[j].cost) {
                std::swap(data[i], data[j]);
            }
        }
    }
    return data;
}

int main() {
    std::vector<Item> data = {{"A", 50}, {"B", 30}, {"C", 40}};
    std::vector<Item> result = optimize_supply_chain(data);
    
    for (const auto& item : result) {
        std::cout << "{" << item.item << ", " << item.cost << "}" << std::endl;
    }
    
    return 0;
}