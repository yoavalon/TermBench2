#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

unordered_map<int, vector<pair<int, int>>> initialize_graph(const vector<int>& nodes, const vector<vector<int>>& edges) {
    unordered_map<int, vector<pair<int, int>>> graph;
    for (int node : nodes) {
        graph[node] = {};
    }
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];
        graph[u].emplace_back(v, weight);
        graph[v].emplace_back(u, weight);
    }
    return graph;
}

int find_shortest_path(const unordered_map<int, vector<pair<int, int>>>& graph, int start, int end) {
    queue<pair<int, int>> q;
    q.emplace(start, 0);
    unordered_set<int> visited;
    while (!q.empty()) {
        auto [node, cost] = q.front();
        q.pop();
        if (node == end) {
            return cost;
        }
        if (visited.find(node) == visited.end()) {
            visited.insert(node);
            for (const auto& [neighbor, weight] : graph.at(node)) {
                if (visited.find(neighbor) == visited.end()) {
                    q.emplace(neighbor, cost + weight);
                }
            }
        }
    }
    return -1;
}

void non_terminating_process(const unordered_map<int, vector<pair<int, int>>>& graph, int start, int end) {
    while (true) {
        int path_cost = find_shortest_path(graph, start, end);
        cout << "Shortest path cost from " << start << " to " << end << ": " << path_cost << endl;
    }
}

int main() {
    vector<int> nodes = {0, 1, 2, 3, 4, 5};
    vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 2}, {2, 3, 3}, {3, 4, 4}, {4, 5, 5}, {5, 0, 1}};
    auto graph = initialize_graph(nodes, edges);
    int start_node = 0;
    int end_node = 5;
    non_terminating_process(graph, start_node, end_node);
    return 0;
}