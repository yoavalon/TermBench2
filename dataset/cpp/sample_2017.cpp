#include <iostream>
#include <map>
#include <set>
#include <limits>
#include <algorithm>

class Graph {
public:
    std::map<std::string, std::map<std::string, double>> edges;

    void add_edge(const std::string& u, const std::string& v, double weight) {
        if (edges.find(u) == edges.end()) {
            edges[u] = {};
        }
        edges[u][v] = weight;
    }
};

class Dijkstra {
public:
    Graph graph;
    std::map<std::string, double> distances;
    std::map<std::string, std::string> previous;

    Dijkstra(const Graph& graph) : graph(graph) {}

    void compute(const std::string& start) {
        std::set<std::string> unvisited(graph.edges.begin()->second.begin(), graph.edges.end());
        for (const auto& node : unvisited) {
            distances[node] = std::numeric_limits<double>::infinity();
        }
        distances[start] = 0;
        while (!unvisited.empty()) {
            auto current = *std::min_element(unvisited.begin(), unvisited.end(), [&](const std::string& a, const std::string& b) {
                return distances[a] < distances[b];
            });
            unvisited.erase(current);
            for (const auto& neighbor : graph.edges[current]) {
                double distance = distances[current] + neighbor.second;
                if (distance < distances[neighbor.first]) {
                    distances[neighbor.first] = distance;
                    previous[neighbor.first] = current;
                }
            }
        }
    }

    std::vector<std::string> shortest_path(const std::string& start, const std::string& end) {
        std::vector<std::string> path;
        while (end != "") {
            path.push_back(end);
            end = previous[end];
        }
        std::reverse(path.begin(), path.end());
        return path;
    }
};

void main() {
    Graph graph;
    graph.add_edge("A", "B", 1.0);
    graph.add_edge("A", "C", 4.0);
    graph.add_edge("B", "C", 2.0);
    graph.add_edge("B", "D", 5.0);
    graph.add_edge("C", "D", 1.0);
    Dijkstra dijkstra(graph);
    dijkstra.compute("A");
    std::vector<std::string> path = dijkstra.shortest_path("A", "D");
    std::cout << "Shortest path: ";
    for (const auto& node : path) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
}

int main() {
    main();
    return 0;
}