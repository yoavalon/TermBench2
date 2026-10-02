#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <limits>

using namespace std;

unordered_map<char, vector<pair<char, double>>> initialize_graph(const vector<char>& nodes, const vector<tuple<char, char, double>>& edges) {
    unordered_map<char, vector<pair<char, double>>> graph;
    for (char node : nodes) {
        graph[node] = {};
    }
    for (const auto& [u, v, weight] : edges) {
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }
    return graph;
}

pair<double, vector<char>> dijkstra(const unordered_map<char, vector<pair<char, double>>>& graph, char start, char target) {
    priority_queue<pair<double, pair<char, vector<char>>>, vector<pair<double, pair<char, vector<char>>>>, greater<>> queue;
    queue.push({0.0, {start, {}}});
    unordered_set<char> visited;
    while (!queue.empty()) {
        auto [cost, node_info] = queue.top();
        queue.pop();
        char node = node_info.first;
        vector<char> path = node_info.second;
        if (visited.find(node) == visited.end()) {
            visited.insert(node);
            path.push_back(node);
            if (node == target) {
                return {cost, path};
            }
            for (const auto& [neighbor, weight] : graph.at(node)) {
                if (visited.find(neighbor) == visited.end()) {
                    queue.push({cost + weight, {neighbor, path}});
                }
            }
        }
    }
    return {numeric_limits<double>::infinity(), {}};
}

int main() {
    vector<char> nodes = {'A', 'B', 'C', 'D', 'E'};
    vector<tuple<char, char, double>> edges = {make_tuple('A', 'B', 1.0), make_tuple('B', 'C', 2.5), make_tuple('C', 'D', 1.0), make_tuple('D', 'E', 1.5), make_tuple('A', 'E', 4.0)};
    auto graph = initialize_graph(nodes, edges);
    auto [cost, path] = dijkstra(graph, 'A', 'E');
    cout << "Shortest path cost: " << cost << ", Path: ";
    for (char node : path) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}