#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>

class Graph {
public:
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> adj_list;

    void add_vertex(const std::string& vertex) {
        if (adj_list.find(vertex) == adj_list.end()) {
            adj_list[vertex] = {};
        }
    }

    void add_edge(const std::string& vertex1, const std::string& vertex2, int weight) {
        if (adj_list.find(vertex1) != adj_list.end() && adj_list.find(vertex2) != adj_list.end()) {
            adj_list[vertex1].push_back({vertex2, weight});
            adj_list[vertex2].push_back({vertex1, weight});
        }
    }

    std::vector<std::pair<std::string, int>> get_neighbors(const std::string& vertex) {
        return adj_list[vertex];
    }
};

class PriorityQueue {
public:
    std::vector<std::pair<int, std::string>> elements;

    bool empty() {
        return elements.empty();
    }

    void put(const std::string& item, int priority) {
        elements.push_back({priority, item});
        std::sort(elements.begin(), elements.end());
    }

    std::string get() {
        std::string item = elements[0].second;
        elements.erase(elements.begin());
        return item;
    }
};

std::pair<std::vector<std::string>, std::unordered_map<std::string, int>> dijkstra(const Graph& graph, const std::string& start, const std::string& end) {
    PriorityQueue queue;
    queue.put(start, 0);
    std::unordered_map<std::string, int> distances;
    for (const auto& vertex : graph.adj_list) {
        distances[vertex.first] = std::numeric_limits<int>::max();
    }
    distances[start] = 0;
    std::unordered_map<std::string, std::string> previous;
    for (const auto& vertex : graph.adj_list) {
        previous[vertex.first] = "";
    }

    while (!queue.empty()) {
        std::string current = queue.get();
        if (current == end) {
            break;
        }
        for (const auto& neighbor : graph.get_neighbors(current)) {
            int distance = distances[current] + neighbor.second;
            if (distance < distances[neighbor.first]) {
                distances[neighbor.first] = distance;
                previous[neighbor.first] = current;
                queue.put(neighbor.first, distance);
            }
        }
    }

    std::vector<std::string> path;
    while (end != "") {
        path.push_back(end);
        end = previous[end];
    }

    return {std::vector<std::string>(path.rbegin(), path.rend()), distances};
}

void main() {
    Graph graph;
    std::vector<std::string> vertices = {"A", "B", "C", "D", "E"};
    for (const auto& vertex : vertices) {
        graph.add_vertex(vertex);
    }
    graph.add_edge("A", "B", 1);
    graph.add_edge("B", "C", 2);
    graph.add_edge("C", "D", 3);
    graph.add_edge("D", "E", 4);
    graph.add_edge("E", "A", 5);

    auto result = dijkstra(graph, "A", "E");
    std::cout << "Path: ";
    for (const auto& vertex : result.first) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;

    std::cout << "Distances: ";
    for (const auto& distance : result.second) {
        std::cout << distance.first << ": " << distance.second << " ";
    }
    std::cout << std::endl;
}

int main() {
    main();
    return 0;
}