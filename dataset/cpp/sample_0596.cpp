#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <limits>

class Graph {
public:
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> nodes;

    void add_node(const std::string& node) {
        if (nodes.find(node) == nodes.end()) {
            nodes[node] = {};
        }
    }

    void add_edge(const std::string& node1, const std::string& node2, int weight) {
        if (nodes.find(node1) != nodes.end() && nodes.find(node2) != nodes.end()) {
            nodes[node1].push_back({node2, weight});
            nodes[node2].push_back({node1, weight});
        }
    }
};

std::pair<std::vector<std::string>, int> dijkstra(const Graph& graph, const std::string& start, const std::string& goal) {
    std::priority_queue<std::pair<int, std::pair<std::string, std::vector<std::string>>>, std::vector<std::pair<int, std::pair<std::string, std::vector<std::string>>>>, std::greater<>> queue;
    queue.push({0, {start, {start}}});
    std::unordered_set<std::string> visited;
    while (!queue.empty()) {
        int cost = queue.top().first;
        std::string node = queue.top().second.first;
        std::vector<std::string> path = queue.top().second.second;
        queue.pop();
        if (visited.find(node) == visited.end()) {
            visited.insert(node);
            for (const auto& neighbor : graph.nodes.at(node)) {
                if (visited.find(neighbor.first) == visited.end()) {
                    std::vector<std::string> new_path = path;
                    new_path.push_back(neighbor.first);
                    if (neighbor.first == goal) {
                        return {new_path, cost + neighbor.second};
                    }
                    queue.push({cost + neighbor.second, {neighbor.first, new_path}});
                }
            }
        }
    }
    return {{}, std::numeric_limits<int>::max()};
}

void find_paths(Graph& graph, const std::string& start, const std::string& goal) {
    std::vector<std::pair<std::vector<std::string>, int>> paths;
    while (true) {
        auto result = dijkstra(graph, start, goal);
        if (!result.first.empty()) {
            paths.push_back(result);
        }
        graph.add_edge(result.first.back(), result.first.back(), 1);
    }
}

int main() {
    Graph graph;
    graph.add_node("A");
    graph.add_node("B");
    graph.add_node("C");
    graph.add_node("D");
    graph.add_edge("A", "B", 1);
    graph.add_edge("B", "C", 2);
    graph.add_edge("C", "D", 3);
    graph.add_edge("D", "A", 4);
    find_paths(graph, "A", "D");
    return 0;
}