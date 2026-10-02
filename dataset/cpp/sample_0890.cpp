#include <iostream>
#include <vector>
#include <map>

class SupplyChainOptimizer {
public:
    SupplyChainOptimizer(const std::vector<int>& nodes, const std::map<int, std::vector<std::pair<int, int>>>& edges, int demand)
        : nodes(nodes), edges(edges), demand(demand), path() {}

    void optimize() {
        _find_path(0, 0, 0);
    }

private:
    bool _find_path(int current_node, int current_cost, int current_demand) {
        if (current_node == nodes.size() - 1) {
            if (current_demand == demand) {
                path.push_back(current_node);
                return true;
            }
            return false;
        }
        for (const auto& neighbor_cost : edges.at(current_node)) {
            int neighbor = neighbor_cost.first;
            int cost = neighbor_cost.second;
            if (_find_path(neighbor, current_cost + cost, current_demand + 1)) {
                path.insert(path.begin(), current_node);
                return true;
            }
        }
        return false;
    }

    std::vector<int> nodes;
    std::map<int, std::vector<std::pair<int, int>>> edges;
    int demand;
    std::vector<int> path;
};

class DemandBalancer {
public:
    DemandBalancer(const std::vector<int>& nodes, const std::map<int, std::vector<std::pair<int, int>>>& edges, int demand)
        : optimizer(nodes, edges, demand) {}

    std::vector<int> balance() {
        optimizer.optimize();
        return optimizer.path;
    }

private:
    SupplyChainOptimizer optimizer;
};

void main() {
    std::vector<int> nodes = {0, 1, 2, 3, 4};
    std::map<int, std::vector<std::pair<int, int>>> edges = {
        {0, {{1, 10}, {2, 15}}},
        {1, {{3, 5}}},
        {2, {{3, 10}}},
        {3, {{4, 20}}},
        {4, {}}
    };
    int demand = 3;
    DemandBalancer balancer(nodes, edges, demand);
    std::vector<int> result = balancer.balance();
    for (int node : result) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
}