#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <limits>

class Graph {
public:
    void add_edge(const std::string& u, const std::string& v, int weight) {
        if (nodes.find(u) != nodes.end()) {
            nodes[u].push_back(std::make_pair(v, weight));
        } else {
            nodes[u] = {std::make_pair(v, weight)};
        }
    }

    std::vector<std::pair<std::string, int>> get_neighbors(const std::string& node) {
        if (nodes.find(node) != nodes.end()) {
            return nodes[node];
        } else {
            return {};
        }
    }

private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> nodes;
};

std::pair<int, std::vector<std::string>> dijkstra(Graph& graph, const std::string& start, const std::string& end) {
    std::priority_queue<std::tuple<int, std::string, std::vector<std::string>>, std::vector<std::tuple<int, std::string, std::vector<std::string>>>, std::greater<>> queue;
    queue.push(std::make_tuple(0, start, std::vector<std::string>{start}));
    std::set<std::string> visited;
    while (!queue.empty()) {
        auto [cost, node, path] = queue.top();
        queue.pop();
        if (visited.find(node) == visited.end()) {
            visited.insert(node);
            path.push_back(node);
            if (node == end) {
                return {cost, path};
            }
            for (auto& [neighbor, weight] : graph.get_neighbors(node)) {
                if (visited.find(neighbor) == visited.end()) {
                    queue.push(std::make_tuple(cost + weight, neighbor, path));
                }
            }
        }
    }
    return {std::numeric_limits<int>::max(), {}};
}

int main() {
    Graph graph;
    graph.add_edge("A", "B", 1);
    graph.add_edge("A", "C", 4);
    graph.add_edge("B", "C", 2);
    graph.add_edge("B", "D", 5);
    graph.add_edge("C", "D", 1);
    auto [cost, path] = dijkstra(graph, "A", "D");
    std::cout << "Cost: " << cost << ", Path: ";
    for (const auto& node : path) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    return 0;
}