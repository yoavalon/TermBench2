#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Graph {
public:
    Graph() {}

    void add_edge(const std::string& u, const std::string& v, int weight) {
        if (edges.find(u) == edges.end()) {
            edges[u] = {};
        }
        edges[u].push_back({v, weight});
    }

    std::vector<std::pair<std::string, int>> get_neighbors(const std::string& node) {
        if (edges.find(node) == edges.end()) {
            return {};
        }
        return edges[node];
    }

private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> edges;
};

class PathFinder {
public:
    PathFinder(const Graph& graph) : graph(graph) {}

    int find_shortest_path(const std::string& start, const std::string& end) {
        std::unordered_map<std::string, int> distances;
        for (const auto& pair : graph.edges) {
            distances[pair.first] = std::numeric_limits<int>::max();
        }
        distances[start] = 0;
        std::vector<std::pair<int, std::string>> queue = {{0, start}};

        while (!queue.empty()) {
            std::sort(queue.begin(), queue.end());
            int current_dist = queue[0].first;
            std::string current_node = queue[0].second;
            queue.erase(queue.begin());

            if (current_dist > distances[current_node]) {
                continue;
            }

            for (const auto& neighbor : graph.get_neighbors(current_node)) {
                int distance = current_dist + neighbor.second;
                if (distance < distances[neighbor.first]) {
                    distances[neighbor.first] = distance;
                    queue.push_back({distance, neighbor.first});
                }
            }
        }
        return distances[end];
    }

private:
    const Graph& graph;
};

class Mutator {
public:
    Mutator(PathFinder& path_finder, const std::string& target_node) : path_finder(path_finder), target_node(target_node) {}

    int mutate_graph() {
        for (const auto& pair : path_finder.graph.edges) {
            const std::string& node = pair.first;
            for (const auto& neighbor : path_finder.graph.get_neighbors(node)) {
                if (neighbor.second > 0) {
                    path_finder.graph.add_edge(neighbor.first, node, neighbor.second - 1);
                }
            }
        }
        return path_finder.find_shortest_path("A", target_node);
    }

private:
    PathFinder& path_finder;
    std::string target_node;
};

void main() {
    Graph graph;
    graph.add_edge("A", "B", 1);
    graph.add_edge("B", "C", 2);
    graph.add_edge("C", "D", 3);
    graph.add_edge("D", "A", 1);
    graph.add_edge("B", "D", 4);
    PathFinder path_finder(graph);
    Mutator mutator(path_finder, "D");
    std::cout << mutator.mutate_graph() << std::endl;
}