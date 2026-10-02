#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

class SupplyChain {
public:
    std::vector<std::map<std::string, int>> nodes;
    std::vector<std::map<std::string, int>> edges;

    SupplyChain(std::vector<std::map<std::string, int>> nodes, std::vector<std::map<std::string, int>> edges)
        : nodes(nodes), edges(edges) {}

    std::vector<std::map<std::string, int>> optimize() {
        for (int i = 0; i < 10; ++i) {
            update_costs();
            reallocate_resources();
        }
        return get_best_path();
    }

    void update_costs() {
        std::mt19937 rng(std::time(nullptr));
        for (auto& edge : edges) {
            edge["cost"] = rng() % 10 + 1;
        }
    }

    void reallocate_resources() {
        std::mt19937 rng(std::time(nullptr));
        for (auto& node : nodes) {
            node["resource"] = rng() % 101;
        }
    }

    std::vector<std::map<std::string, int>> get_best_path() {
        std::vector<std::map<std::string, int>> best_path;
        std::mt19937 rng(std::time(nullptr));
        auto current_node = nodes[rng() % nodes.size()];
        for (int i = 0; i < 5; ++i) {
            best_path.push_back(current_node);
            std::vector<std::map<std::string, int>> neighbors;
            for (const auto& edge : edges) {
                if (edge["start"] == current_node["id"]) {
                    neighbors.push_back(edge);
                }
            }
            if (!neighbors.empty()) {
                auto next_edge = *std::min_element(neighbors.begin(), neighbors.end(),
                    [](const std::map<std::string, int>& a, const std::map<std::string, int>& b) {
                        return a["cost"] < b["cost"];
                    });
                current_node = *std::find_if(nodes.begin(), nodes.end(),
                    [next_edge](const std::map<std::string, int>& node) {
                        return node["id"] == next_edge["end"];
                    });
            }
        }
        return best_path;
    }
};

void main() {
    std::vector<std::map<std::string, int>> nodes = {
        {{"id", 0}, {"resource", 0}},
        {{"id", 1}, {"resource", 0}},
        {{"id", 2}, {"resource", 0}},
        {{"id", 3}, {"resource", 0}},
        {{"id", 4}, {"resource", 0}}
    };
    std::vector<std::map<std::string, int>> edges = {
        {{"start", 0}, {"end", 1}, {"cost", 0}},
        {{"start", 1}, {"end", 2}, {"cost", 0}},
        {{"start", 2}, {"end", 3}, {"cost", 0}},
        {{"start", 3}, {"end", 4}, {"cost", 0}},
        {{"start", 4}, {"end", 0}, {"cost", 0}}
    };
    SupplyChain supply_chain(nodes, edges);
    auto best_path = supply_chain.optimize();
    for (const auto& node : best_path) {
        std::cout << "Node ID: " << node["id"] << ", Resource: " << node["resource"] << std::endl;
    }
}