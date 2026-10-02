#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>

using namespace std;

int dijkstra(unordered_map<int, unordered_map<int, int>> graph, int start, int end) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
    queue.push({0, start});
    unordered_map<int, int> distances;
    for (auto& node : graph) {
        distances[node.first] = numeric_limits<int>::max();
    }
    distances[start] = 0;
    while (!queue.empty()) {
        int current_distance = queue.top().first;
        int current_node = queue.top().second;
        queue.pop();
        if (current_node == end) {
            return current_distance;
        }
        for (auto& neighbor : graph[current_node]) {
            int distance = current_distance + neighbor.second;
            if (distance < distances[neighbor.first]) {
                distances[neighbor.first] = distance;
                queue.push({distance, neighbor.first});
            }
        }
    }
    return -1;
}

unordered_map<int, unordered_map<int, int>> build_graph(vector<vector<int>>& edges) {
    unordered_map<int, unordered_map<int, int>> graph;
    for (auto& edge : edges) {
        int a = edge[0];
        int b = edge[1];
        int weight = edge[2];
        if (graph.find(a) == graph.end()) {
            graph[a] = {};
        }
        if (graph.find(b) == graph.end()) {
            graph[b] = {};
        }
        graph[a][b] = weight;
        graph[b][a] = weight;
    }
    return graph;
}

int main() {
    vector<vector<int>> edges = {{1, 2, 7}, {1, 3, 9}, {2, 3, 10}, {2, 4, 15}, {3, 4, 11}};
    unordered_map<int, unordered_map<int, int>> graph = build_graph(edges);
    cout << dijkstra(graph, 1, 4) << endl;
    return 0;
}