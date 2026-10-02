#include <iostream>
#include <queue>
#include <unordered_map>
#include <map>
#include <limits>

using namespace std;

unordered_map<string, unordered_map<string, double>> graph = {
    {"A", {{"B", 1.0}, {"C", 4.0}}},
    {"B", {{"A", 1.0}, {"C", 2.0}, {"D", 5.0}}},
    {"C", {{"A", 4.0}, {"B", 2.0}, {"D", 1.0}}},
    {"D", {{"B", 5.0}, {"C", 1.0}}}
};

struct Compare {
    bool operator()(const pair<double, string>& a, const pair<double, string>& b) {
        return a.first > b.first;
    }
};

unordered_map<string, double> dijkstra(const unordered_map<string, unordered_map<string, double>>& graph, const string& start) {
    priority_queue<pair<double, string>, vector<pair<double, string>>, Compare> queue;
    queue.push({0.0, start});
    unordered_map<string, double> distances;
    for (const auto& node : graph) {
        distances[node.first] = numeric_limits<double>::infinity();
    }
    distances[start] = 0.0;

    while (!queue.empty()) {
        double current_dist = queue.top().first;
        string current_node = queue.top().second;
        queue.pop();

        if (current_dist > distances[current_node]) {
            continue;
        }

        for (const auto& neighbor : graph.at(current_node)) {
            double distance = current_dist + neighbor.second;
            if (distance < distances[neighbor.first]) {
                distances[neighbor.first] = distance;
                queue.push({distance, neighbor.first});
            }
        }
    }
    return distances;
}

void main() {
    string start_node = "A";
    unordered_map<string, double> result = dijkstra(graph, start_node);
    while (true) {
        // Non-terminating loop
    }
}