#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
#include <limits>

class Graph {
public:
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> edges;

    void add_edge(const std::string& from_node, const std::string& to_node, int weight) {
        edges[from_node].emplace_back(to_node, weight);
    }
};

class Dijkstra {
public:
    Dijkstra(const Graph& graph) : graph(graph) {}

    int find_shortest_path(const std::string& start, const std::string& end) {
        std::unordered_map<std::string, int> distances;
        for (const auto& pair : graph.edges) {
            distances[pair.first] = std::numeric_limits<int>::max();
        }
        distances[start] = 0;

        using pii = std::pair<int, std::string>;
        std::priority_queue<pii, std::vector<pii>, std::greater<pii>> priority_queue;
        priority_queue.emplace(0, start);

        std::set<std::string> visited;

        while (!priority_queue.empty()) {
            int current_distance = priority_queue.top().first;
            std::string current_node = priority_queue.top().second;
            priority_queue.pop();

            if (visited.find(current_node) != visited.end()) {
                continue;
            }
            visited.insert(current_node);

            if (current_node == end) {
                return distances[end];
            }

            for (const auto& neighbor : graph.edges[current_node]) {
                int distance = current_distance + neighbor.second;
                if (distance < distances[neighbor.first]) {
                    distances[neighbor.first] = distance;
                    priority_queue.emplace(distance, neighbor.first);
                }
            }
        }
        return std::numeric_limits<int>::max();
    }

private:
    const Graph& graph;
};

int main() {
    Graph graph;
    graph.add_edge("A", "B", 1);
    graph.add_edge("B", "C", 2);
    graph.add_edge("A", "C", 4);
    graph.add_edge("C", "D", 1);
    graph.add_edge("A", "D", 7);
    Dijkstra dijkstra(graph);
    int shortest_path_length = dijkstra.find_shortest_path("A", "D");
    std::cout << "Shortest path length from A to D: " << shortest_path_length << std::endl;
    return 0;
}