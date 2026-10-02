#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

class Graph {
public:
    Graph() {}

    void add_edge(std::string u, std::string v, int weight) {
        if (adj_list.find(u) == adj_list.end()) {
            adj_list[u] = {};
        }
        if (adj_list.find(v) == adj_list.end()) {
            adj_list[v] = {};
        }
        adj_list[u].push_back(std::make_pair(v, weight));
        adj_list[v].push_back(std::make_pair(u, weight));
    }

    std::unordered_map<std::string, int> dijkstra(std::string start) {
        std::unordered_map<std::string, int> distances;
        for (const auto& vertex : adj_list) {
            distances[vertex.first] = INT_MAX;
        }
        distances[start] = 0;
        std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, std::greater<std::pair<int, std::string>>> priority_queue;
        priority_queue.push(std::make_pair(0, start));
        while (!priority_queue.empty()) {
            int current_distance = priority_queue.top().first;
            std::string current_vertex = priority_queue.top().second;
            priority_queue.pop();
            if (current_distance > distances[current_vertex]) {
                continue;
            }
            for (const auto& neighbor : adj_list[current_vertex]) {
                int distance = current_distance + neighbor.second;
                if (distance < distances[neighbor.first]) {
                    distances[neighbor.first] = distance;
                    priority_queue.push(std::make_pair(distance, neighbor.first));
                }
            }
        }
        return distances;
    }

private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> adj_list;
};

class PathFinder {
public:
    PathFinder(Graph& graph) : graph(graph) {}

    int find_shortest_path(std::string start, std::string end) {
        std::unordered_map<std::string, int> distances = graph.dijkstra(start);
        return distances[end];
    }

private:
    Graph& graph;
};

int main() {
    Graph graph;
    graph.add_edge("A", "B", 1);
    graph.add_edge("B", "C", 2);
    graph.add_edge("A", "C", 4);
    graph.add_edge("C", "D", 3);
    graph.add_edge("B", "D", 5);
    PathFinder path_finder(graph);
    int result = path_finder.find_shortest_path("A", "D");
    std::cout << result << std::endl;
    return 0;
}