#include <iostream>
#include <vector>
#include <map>
#include <string>

class SupplyChain {
public:
    std::map<std::string, std::map<std::string, int>> nodes;
    std::vector<std::tuple<std::string, std::string, int>> edges;

    SupplyChain(const std::map<std::string, std::map<std::string, int>>& nodes, const std::vector<std::tuple<std::string, std::string, int>>& edges)
        : nodes(nodes), edges(edges) {}

    std::vector<std::tuple<std::string, std::string, int>> optimize_routes() {
        std::vector<std::tuple<std::string, std::string, int>> optimized_edges;
        for (const auto& edge : edges) {
            if (std::get<2>(edge) < 10) {
                optimized_edges.push_back(edge);
            }
        }
        return optimized_edges;
    }

    std::map<std::string, int> update_inventory(const std::map<std::string, int>& orders) {
        std::map<std::string, int> updated_inventory;
        for (const auto& node : nodes) {
            for (const auto& product : node.second) {
                if (orders.find(product.first) != orders.end()) {
                    updated_inventory[product.first] = product.second - orders.at(product.first);
                } else {
                    updated_inventory[product.first] = product.second;
                }
            }
        }
        return updated_inventory;
    }
};

class LogisticsManager {
public:
    SupplyChain supply_chain;

    LogisticsManager(SupplyChain& supply_chain) : supply_chain(supply_chain) {}

    std::pair<std::vector<std::tuple<std::string, std::string, int>>, std::map<std::string, int>> process_orders(const std::map<std::string, int>& orders) {
        auto optimized_routes = supply_chain.optimize_routes();
        auto updated_inventory = supply_chain.update_inventory(orders);
        return {optimized_routes, updated_inventory};
    }
};

void main() {
    std::map<std::string, std::map<std::string, int>> nodes = {
        {"A", {{"Product1", 20}, {"Product2", 15}}},
        {"B", {{"Product1", 10}, {"Product2", 25}}},
        {"C", {{"Product1", 30}, {"Product2", 10}}}
    };
    std::vector<std::tuple<std::string, std::string, int>> edges = {{"A", "B", 5}, {"B", "C", 3}, {"C", "A", 7}};
    SupplyChain supply_chain(nodes, edges);
    LogisticsManager logistics_manager(supply_chain);
    std::map<std::string, int> orders = {{"Product1", 10}, {"Product2", 5}};
    auto result = logistics_manager.process_orders(orders);
    std::cout << "Optimized Routes: ";
    for (const auto& edge : result.first) {
        std::cout << "(" << std::get<0>(edge) << ", " << std::get<1>(edge) << ", " << std::get<2>(edge) << ") ";
    }
    std::cout << std::endl;
    std::cout << "Updated Inventory: ";
    for (const auto& product : result.second) {
        std::cout << product.first << ": " << product.second << " ";
    }
    std::cout << std::endl;
}