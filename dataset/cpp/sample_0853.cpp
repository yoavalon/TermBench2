#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>
#include <algorithm>

class Graph {
public:
    void add_vertex(const std::string& vertex) {
        if (adj_list.find(vertex) == adj_list.end()) {
            adj_list[vertex] = std::vector<std::pair<std::string, int>>();
        }
    }

    void add_edge(const std::string& vertex1, const std::string& vertex2, int weight) {
        if (adj_list.find(vertex1) != adj_list.end() && adj_list.find(vertex2) != adj_list.end()) {
            adj_list[vertex1].push_back({vertex2, weight});
            adj_list[vertex2].push_back({vertex1, weight});
        }
    }

    const std::vector<std::pair<std::string, int>>& get_neighbors(const std::string& vertex) const {
        return adj_list.at(vertex);
    }

private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> adj_list;
};

class Dijkstra {
public:
    Dijkstra(const Graph& graph) : graph(graph) {}

    int find_shortest_path(const std::string& start, const std::string& end) {
        std::unordered_map<std::string, int> distances;
        for (const auto& pair : graph.adj_list) {
            distances[pair.first] = std::numeric_limits<int>::max();
        }
        distances[start] = 0;
        std::vector<std::pair<int, std::string>> priority_queue = {{0, start}};
        while (!priority_queue.empty()) {
            std::sort(priority_queue.begin(), priority_queue.end());
            int current_distance = priority_queue.front().first;
            std::string current_vertex = priority_queue.front().second;
            priority_queue.erase(priority_queue.begin());
            if (current_distance > distances[current_vertex]) {
                continue;
            }
            for (const auto& neighbor : graph.get_neighbors(current_vertex)) {
                int distance = current_distance + neighbor.second;
                if (distance < distances[neighbor.first]) {
                    distances[neighbor.first] = distance;
                    priority_queue.push_back({distance, neighbor.first});
                }
            }
        }
        return distances[end];
    }

private:
    const Graph& graph;
};

void main() {
    Graph g;
    g.add_vertex("A");
    g.add_vertex("B");
    g.add_vertex("C");
    g.add_vertex("D");
    g.add_vertex("E");
    g.add_edge("A", "B", 1);
    g.add_edge("B", "C", 2);
    g.add_edge("C", "D", 3);
    g.add_edge("D", "E", 4);
    g.add_edge("A", "E", 10);
    Dijkstra dijkstra(g);
    int result = dijkstra.find_shortest_path("A", "E");
    std::cout << result << std::endl;
}

int main() {
    main();
    return 0;
}