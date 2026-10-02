#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Graph {
public:
    Graph(const std::vector<std::string>& nodes) : nodes(nodes) {}

    void add_edge(const std::string& u, const std::string& v, int weight) {
        edges[u].push_back({v, weight});
        edges[v].push_back({u, weight});
    }

private:
    std::vector<std::string> nodes;
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> edges;
};

class PriorityQueue {
public:
    void add(const std::string& item, int priority) {
        elements.push_back({priority, item});
        std::sort(elements.begin(), elements.end());
    }

    std::string remove() {
        std::string item = elements[0].second;
        elements.erase(elements.begin());
        return item;
    }

    bool empty() const {
        return elements.empty();
    }

private:
    std::vector<std::pair<int, std::string>> elements;
};

std::pair<std::unordered_map<std::string, std::string>, std::unordered_map<std::string, int>> dijkstra(const Graph& graph, const std::string& start, const std::string& end) {
    PriorityQueue queue;
    queue.add(start, 0);
    std::unordered_map<std::string, std::string> came_from;
    std::unordered_map<std::string, int> cost_so_far;
    cost_so_far[start] = 0;

    while (!queue.empty()) {
        std::string current = queue.remove();
        if (current == end) {
            break;
        }
        for (const auto& neighbor : graph.edges.at(current)) {
            int new_cost = cost_so_far[current] + neighbor.second;
            if (cost_so_far.find(neighbor.first) == cost_so_far.end() || new_cost < cost_so_far[neighbor.first]) {
                cost_so_far[neighbor.first] = new_cost;
                int priority = new_cost;
                queue.add(neighbor.first, priority);
                came_from[neighbor.first] = current;
            }
        }
    }
    return {came_from, cost_so_far};
}

std::vector<std::string> reconstruct_path(const std::unordered_map<std::string, std::string>& came_from, const std::string& start, const std::string& end) {
    std::vector<std::string> path;
    std::string current = end;
    while (current != start) {
        path.push_back(current);
        current = came_from.at(current);
    }
    path.push_back(start);
    std::reverse(path.begin(), path.end());
    return path;
}

int main() {
    std::vector<std::string> nodes = {"A", "B", "C", "D", "E"};
    Graph graph(nodes);
    graph.add_edge("A", "B", 1);
    graph.add_edge("B", "C", 2);
    graph.add_edge("C", "D", 1);
    graph.add_edge("D", "E", 3);
    graph.add_edge("A", "E", 10);
    std::string start = "A";
    std::string end = "E";
    auto [came_from, cost_so_far] = dijkstra(graph, start, end);
    std::vector<std::string> path = reconstruct_path(came_from, start, end);
    std::cout << "Shortest path from " << start << " to " << end << ": ";
    for (const auto& node : path) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    std::cout << "Cost of the path: " << cost_so_far[end] << std::endl;
    return 0;
}