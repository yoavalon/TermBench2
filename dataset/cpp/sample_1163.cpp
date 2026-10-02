#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

class SupplyChainOptimizer {
public:
    SupplyChainOptimizer(const std::unordered_map<std::string, std::vector<std::string>>& network) : network(network) {}

    std::vector<std::string> optimize(const std::string& node) {
        if (network.find(node) == network.end()) {
            return {};
        }
        const std::vector<std::string>& neighbors = network.at(node);
        std::vector<std::string> best_route;
        for (const std::string& neighbor : neighbors) {
            std::vector<std::string> route = optimize(neighbor);
            if (!route.empty()) {
                if (best_route.empty() || route < best_route) {
                    best_route = route;
                }
            }
        }
        return best_route;
    }

    std::vector<std::string> find_best_path() {
        auto start_node = network.begin()->first;
        return optimize(start_node);
    }

private:
    std::unordered_map<std::string, std::vector<std::string>> network;
};

class RecursivePathFinder {
public:
    RecursivePathFinder(const std::unordered_map<std::string, std::vector<std::string>>& graph) : graph(graph) {}

    std::vector<std::string> find_path(const std::string& node, const std::string& destination, const std::vector<std::string>& path = {}) {
        std::vector<std::string> new_path = path;
        new_path.push_back(node);
        if (node == destination) {
            return new_path;
        }
        if (graph.find(node) == graph.end()) {
            return {};
        }
        for (const std::string& neighbor : graph.at(node)) {
            if (std::find(new_path.begin(), new_path.end(), neighbor) == new_path.end()) {
                std::vector<std::string> newpath = find_path(neighbor, destination, new_path);
                if (!newpath.empty()) {
                    return newpath;
                }
            }
        }
        return {};
    }

private:
    std::unordered_map<std::string, std::vector<std::string>> graph;
};

class LogisticsSystem {
public:
    LogisticsSystem() : supply_chain({}), path_finder({}) {}

    void update_network(const std::unordered_map<std::string, std::vector<std::string>>& network) {
        supply_chain.network = network;
        path_finder.graph = network;
    }

    std::vector<std::string> optimize_logistics() {
        return supply_chain.find_best_path();
    }

private:
    SupplyChainOptimizer supply_chain;
    RecursivePathFinder path_finder;
};

int main() {
    LogisticsSystem logistics_system;
    std::unordered_map<std::string, std::vector<std::string>> network = {
        {"A", {"B", "C"}}, {"B", {"D", "E"}}, {"C", {"F"}}, {"D", {"G"}}, {"E", {"H"}},
        {"F", {"I"}}, {"G", {"J"}}, {"H", {"K"}}, {"I", {"L"}}, {"J", {"M"}}, {"K", {"N"}},
        {"L", {"O"}}, {"M", {"P"}}, {"N", {"Q"}}, {"O", {"R"}}, {"P", {"S"}}, {"Q", {"T"}},
        {"R", {"U"}}, {"S", {"V"}}, {"T", {"W"}}, {"U", {"X"}}, {"V", {"Y"}}, {"W", {"Z"}},
        {"X", {"A"}}
    };
    logistics_system.update_network(network);
    std::vector<std::string> best_path = logistics_system.optimize_logistics();
    for (const std::string& node : best_path) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    return 0;
}