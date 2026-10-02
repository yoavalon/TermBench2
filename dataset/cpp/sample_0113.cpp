#include <iostream>
#include <vector>
#include <map>
#include <random>
#include <iomanip>

std::vector<std::map<std::string, double>> generate_supply_data(int num_items) {
    std::vector<std::map<std::string, double>> data;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> item_id_dist(1, 1000);
    std::uniform_int_distribution<> quantity_dist(10, 100);
    std::uniform_real_distribution<> cost_dist(5.0, 20.0);

    for (int i = 0; i < num_items; ++i) {
        std::map<std::string, double> item;
        item["item_id"] = item_id_dist(gen);
        item["quantity"] = quantity_dist(gen);
        item["cost"] = cost_dist(gen);
        data.push_back(item);
    }
    return data;
}

std::vector<std::map<std::string, double>> optimize_supply_chain(const std::vector<std::map<std::string, double>>& data) {
    double total_cost = 0;
    for (const auto& item : data) {
        total_cost += item.at("quantity") * item.at("cost");
    }
    double average_cost = total_cost / data.size();
    std::vector<std::map<std::string, double>> optimized_data;
    for (const auto& item : data) {
        if (item.at("cost") <= average_cost) {
            optimized_data.push_back(item);
        }
    }
    return optimized_data;
}

int main() {
    int num_items = 50;
    auto supply_data = generate_supply_data(num_items);
    auto optimized_data = optimize_supply_chain(supply_data);

    std::cout << "Optimized supply chain data: [";
    for (size_t i = 0; i < optimized_data.size(); ++i) {
        const auto& item = optimized_data[i];
        std::cout << "{item_id: " << item.at("item_id") << ", quantity: " << item.at("quantity")
                  << ", cost: " << std::fixed << std::setprecision(2) << item.at("cost") << "}";
        if (i < optimized_data.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}