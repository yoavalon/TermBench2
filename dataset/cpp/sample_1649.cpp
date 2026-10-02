#include <iostream>
#include <map>
#include <string>

std::map<std::string, std::string> update_node_status(std::map<std::string, std::string> nodes, const std::string& node_id, const std::string& new_status) {
    nodes[node_id] = new_status;
    return nodes;
}

std::map<std::string, std::string> simulate_network_activity(std::map<std::string, std::string> nodes) {
    for (const auto& node : nodes) {
        std::string node_id = node.first;
        std::string current_status = node.second;
        if (current_status == "inactive") {
            nodes = update_node_status(nodes, node_id, "active");
        } else {
            nodes = update_node_status(nodes, node_id, "inactive");
        }
    }
    return nodes;
}

int main() {
    std::map<std::string, std::string> initial_nodes = {{"node1", "inactive"}, {"node2", "active"}, {"node3", "inactive"}};
    while (true) {
        initial_nodes = simulate_network_activity(initial_nodes);
    }
    return 0;
}