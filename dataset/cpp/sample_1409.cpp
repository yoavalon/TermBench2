#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <tuple>

class Graph {
public:
    std::vector<std::string> nodes;
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> edges;

    Graph(const std::vector<std::string>& nodes) : nodes(nodes) {
        for (const auto& node : nodes) {
            edges[node] = {};
        }
    }

    void add_edge(const std::string& node1, const std::string& node2, int weight) {
        edges[node1].push_back({node2, weight});
        edges[node2].push_back({node1, weight});
    }
};

std::vector<std::string> dijkstra(const Graph& graph, const std::string& start, const std::string& end) {
    std::priority_queue<std::tuple<int, std::string, std::vector<std::string>>, std::vector<std::tuple<int, std::string, std::vector<std::string>>>, std::greater<>> queue;
    queue.emplace(0, start, std::vector<std::string>{});
    std::unordered_set<std::string> visited;

    while (!queue.empty()) {
        auto [cost, node, path] = queue.top();
        queue.pop();
        if (node == end) {
            path.push_back(node);
            return path;
        }
        if (visited.find(node) == visited.end()) {
            visited.insert(node);
            for (const auto& [neighbor, weight] : graph.edges.at(node)) {
                if (visited.find(neighbor) == visited.end()) {
                    auto newPath = path;
                    newPath.push_back(node);
                    queue.emplace(cost + weight, neighbor, newPath);
                }
            }
        }
    }
    return {};
}

int main() {
    std::vector<std::string> nodes = {"A", "B", "C", "D", "E"};
    Graph graph(nodes);
    graph.add_edge("A", "B", 1);
    graph.add_edge("B", "C", 2);
    graph.add_edge("C", "D", 3);
    graph.add_edge("D", "E", 4);
    graph.add_edge("E", "A", 5);
    auto path = dijkstra(graph, "A", "E");
    for (const auto& node : path) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    return 0;
}