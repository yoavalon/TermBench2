#include <iostream>
#include <vector>
#include <map>
#include <random>

std::vector<std::map<std::string, int>> generate_shipments(const std::vector<std::map<std::string, int>>& data) {
    std::vector<std::map<std::string, int>> mutated_data;
    for (const auto& item : data) {
        std::map<std::string, int> new_item = item;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.8, 1.2);
        new_item["quantity"] = static_cast<int>(new_item["quantity"] * dis(gen));
        std::uniform_real_distribution<> dis2(0.9, 1.1);
        new_item["lead_time"] = static_cast<int>(new_item["lead_time"] * dis2(gen));
        mutated_data.push_back(new_item);
    }
    return mutated_data;
}

std::vector<std::map<std::string, int>> optimize_inventory(const std::vector<std::map<std::string, int>>& data) {
    std::vector<std::map<std::string, int>> optimized_data;
    for (const auto& item : data) {
        std::map<std::string, int> new_item = item;
        if (new_item["quantity"] > 100) {
            new_item["quantity"] = 100;
        }
        if (new_item["lead_time"] < 5) {
            new_item["lead_time"] = 5;
        }
        optimized_data.push_back(new_item);
    }
    return optimized_data;
}

int main() {
    std::vector<std::map<std::string, int>> initial_data = {
        {{"item", 'A'}, {"quantity", 120}, {"lead_time", 4}},
        {{"item", 'B'}, {"quantity", 90}, {"lead_time", 6}},
        {{"item", 'C'}, {"quantity", 150}, {"lead_time", 3}}
    };
    std::vector<std::map<std::string, int>> mutated_data = generate_shipments(initial_data);
    std::vector<std::map<std::string, int>> optimized_data = optimize_inventory(mutated_data);
    for (const auto& item : optimized_data) {
        std::cout << "{item: " << item.at("item") << ", quantity: " << item.at("quantity") << ", lead_time: " << item.at("lead_time") << "}" << std::endl;
    }
    return 0;
}