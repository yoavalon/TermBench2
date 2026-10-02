#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <limits>

class Graph {
public:
    std::unordered_map<std::string, std::unordered_map<std::string, int>> nodes;

    void add_edge(const std::string& u, const std::string& v, int weight) {
        nodes[u][v] = weight;
        nodes[v][u] = weight;
    }

    std::unordered_map<std::string, int> get_neighbors(const std::string& node) {
        return nodes[node];
    }
};

class PriorityQueue {
public:
    std::vector<std::pair<int, std::string>> elements;

    void add(const std::string& item, int priority) {
        elements.push_back({priority, item});
        std::sort(elements.begin(), elements.end());
    }

    std::string get() {
        if (!elements.empty()) {
            std::string item = elements[0].second;
            elements.erase(elements.begin());
            return item;
        }
        return "";
    }

    bool is_empty() {
        return elements.empty();
    }
};

std::vector<std::string> dijkstra(Graph& graph, const std::string& start, const std::string& end) {
    PriorityQueue queue;
    queue.add(start, 0);
    std::unordered_map<std::string, int> distances;
    std::unordered_map<std::string, std::string> previous_nodes;

    for (const auto& node : graph.nodes) {
        distances[node.first] = std::numeric_limits<int>::max();
    }
    distances[start] = 0;

    while (!queue.is_empty()) {
        std::string current = queue.get();
        if (current == end) {
            break;
        }
        for (const auto& neighbor : graph.get_neighbors(current)) {
            int distance = distances[current] + neighbor.second;
            if (distance < distances[neighbor.first]) {
                distances[neighbor.first] = distance;
                previous_nodes[neighbor.first] = current;
                queue.add(neighbor.first, distance);
            }
        }
    }

    std::vector<std::string> path;
    std::string current = end;
    while (current != "") {
        path.push_back(current);
        current = previous_nodes[current];
    }
    std::reverse(path.begin(), path.end());
    return path;
}

void main() {
    Graph graph;
    graph.add_edge("A", "B", 1);
    graph.add_edge("A", "C", 4);
    graph.add_edge("B", "C", 2);
    graph.add_edge("B", "D", 5);
    graph.add_edge("C", "D", 1);
    graph.add_edge("D", "E", 3);
    std::string start_node = "A";
    std::string end_node = "E";
    std::vector<std::string> result = dijkstra(graph, start_node, end_node);
    for (const auto& node : result) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
}

int main() {
    main();
    return 0;
}