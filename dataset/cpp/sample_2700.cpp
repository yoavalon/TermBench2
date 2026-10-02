#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>

class Graph {
public:
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> nodes;

    void add_node(const std::string& node) {
        nodes[node] = {};
    }

    void add_edge(const std::string& node1, const std::string& node2, int weight) {
        if (nodes.find(node1) != nodes.end() && nodes.find(node2) != nodes.end()) {
            nodes[node1].push_back({node2, weight});
            nodes[node2].push_back({node1, weight});
        }
    }
};

class PathFinder {
public:
    Graph graph;

    PathFinder(Graph& graph) : graph(graph) {}

    std::vector<std::string> find_shortest_path(const std::string& start, const std::string& end) {
        std::queue<std::pair<std::string, int>> queue;
        queue.push({start, 0});
        std::set<std::string> visited;
        std::unordered_map<std::string, std::vector<std::string>> paths;
        paths[start] = {};

        while (!queue.empty()) {
            auto [node, distance] = queue.front();
            queue.pop();

            if (node == end) {
                return paths[node] + {node};
            }

            if (visited.find(node) == visited.end()) {
                visited.insert(node);
                for (auto [neighbor, weight] : graph.nodes[node]) {
                    if (visited.find(neighbor) == visited.end()) {
                        queue.push({neighbor, distance + weight});
                        paths[neighbor] = paths[node] + {node};
                    }
                }
            }
        }

        return {};
    }
};

int main() {
    Graph g;
    g.add_node("A");
    g.add_node("B");
    g.add_node("C");
    g.add_node("D");
    g.add_node("E");
    g.add_node("F");
    g.add_node("G");
    g.add_edge("A", "B", 1);
    g.add_edge("A", "C", 4);
    g.add_edge("B", "C", 2);
    g.add_edge("B", "D", 5);
    g.add_edge("C", "D", 1);
    g.add_edge("C", "E", 3);
    g.add_edge("D", "E", 1);
    g.add_edge("D", "F", 8);
    g.add_edge("E", "F", 2);
    g.add_edge("E", "G", 2);
    g.add_edge("F", "G", 7);

    PathFinder pf(g);
    std::vector<std::string> path = pf.find_shortest_path("A", "G");

    for (const auto& node : path) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    return 0;
}