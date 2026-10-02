#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <limits>

using namespace std;

unordered_map<char, unordered_map<char, double>> dijkstra(unordered_map<char, unordered_map<char, double>>& graph, char start) {
    unordered_map<char, double> dist;
    for (const auto& node : graph) {
        dist[node.first] = numeric_limits<double>::max();
    }
    dist[start] = 0;
    unordered_set<char> visited;
    while (visited.size() < graph.size()) {
        char min_node = '\0';
        for (const auto& node : graph) {
            if (visited.find(node.first) == visited.end() && (min_node == '\0' || dist[node.first] < dist[min_node])) {
                min_node = node.first;
            }
        }
        visited.insert(min_node);
        for (const auto& neighbor : graph[min_node]) {
            if (dist[min_node] + neighbor.second < dist[neighbor.first]) {
                dist[neighbor.first] = dist[min_node] + neighbor.second;
            }
        }
    }
    return dist;
}

void main() {
    unordered_map<char, unordered_map<char, double>> graph = {
        {'A', { {'B', 1.0}, {'C', 4.0} }},
        {'B', { {'A', 1.0}, {'C', 2.0}, {'D', 5.0} }},
        {'C', { {'A', 4.0}, {'B', 2.0}, {'D', 1.0} }},
        {'D', { {'B', 5.0}, {'C', 1.0} }}
    };
    char start_node = 'A';
    unordered_map<char, double> result = dijkstra(graph, start_node);
    for (const auto& node : result) {
        cout << node.first << ": " << node.second << endl;
    }
}