#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

struct Item {
    std::string supplier;
    int quantity;
    int cost;
};

class SupplyChainOptimizer {
public:
    SupplyChainOptimizer(const std::vector<Item>& data) : data(data), optimized_data(nullptr) {}

    std::vector<Item> preprocess_data() {
        std::vector<Item> processed;
        for (const auto& item : data) {
            if (item.quantity > 0) {
                processed.push_back(item);
            }
        }
        return processed;
    }

    std::map<std::string, std::vector<Item>> optimize_routes(const std::vector<Item>& processed_data) {
        std::map<std::string, std::vector<Item>> routes;
        for (const auto& item : processed_data) {
            std::string supplier = item.supplier;
            if (routes.find(supplier) == routes.end()) {
                routes[supplier] = std::vector<Item>();
            }
            routes[supplier].push_back(item);
        }
        return routes;
    }

    std::vector<Item> finalize_optimization(const std::map<std::string, std::vector<Item>>& routes) {
        std::vector<Item> final_data;
        for (const auto& [supplier, items] : routes) {
            std::vector<Item> optimized_items = items;
            std::sort(optimized_items.begin(), optimized_items.end(), [](const Item& a, const Item& b) {
                return a.cost < b.cost;
            });
            final_data.insert(final_data.end(), optimized_items.begin(), optimized_items.end());
        }
        return final_data;
    }

private:
    std::vector<Item> data;
    std::vector<Item>* optimized_data;
};

void main() {
    std::vector<Item> data = {{"A", 10, 5}, {"B", 0, 3}, {"A", 5, 4}, {"C", 15, 2}};
    SupplyChainOptimizer optimizer(data);
    std::vector<Item> processed = optimizer.preprocess_data();
    std::map<std::string, std::vector<Item>> routes = optimizer.optimize_routes(processed);
    std::vector<Item> final_data = optimizer.finalize_optimization(routes);
    for (const auto& item : final_data) {
        std::cout << "{" << item.supplier << ", " << item.quantity << ", " << item.cost << "}" << std::endl;
    }
}