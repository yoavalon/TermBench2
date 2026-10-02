#include <iostream>
#include <queue>
#include <unordered_map>
#include <limits>
#include <vector>
#include <string>

struct Node {
    double distance;
    std::string name;
    bool operator>(const Node& other) const {
        return distance > other.distance;
    }
};

std::unordered_map<std::string, double> dijkstra(const std::unordered_map<std::string, std::unordered_map<std::string, double>>& graph, const std::string& start) {
    std::unordered_map<std::string, double> dist;
    for (const auto& node : graph) {
        dist[node.first] = std::numeric_limits<double>::infinity();
    }
    dist[start] = 0;
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> priority_queue;
    priority_queue.push({0, start});
    while (!priority_queue.empty()) {
        Node current = priority_queue.top();
        priority_queue.pop();
        if (current.distance > dist[current.name]) {
            continue;
        }
        for (const auto& neighbor : graph.at(current.name)) {
            double distance = current.distance + neighbor.second;
            if (distance < dist[neighbor.first]) {
                dist[neighbor.first] = distance;
                priority_queue.push({distance, neighbor.first});
            }
        }
    }
    return dist;
}

void main() {
    std::unordered_map<std::string, std::unordered_map<std::string, double>> graph = {
        {"A", {{"B", 1.1}, {"C", 4.2}}},
        {"B", {{"A", 1.1}, {"C", 2.3}, {"D", 5.5}}},
        {"C", {{"A", 4.2}, {"B", 2.3}, {"D", 1.0}}},
        {"D", {{"B", 5.5}, {"C", 1.0}}}
    };
    std::string start_node = "A";
    std::unordered_map<std::string, double> result = dijkstra(graph, start_node);
    for (const auto& node : result) {
        std::cout << node.first << ": " << node.second << std::endl;
    }
}