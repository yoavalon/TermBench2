#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <limits>

using namespace std;

unordered_map<char, vector<pair<char, int>>> initialize_graph(vector<char> nodes, vector<tuple<char, char, int>> edges) {
    unordered_map<char, vector<pair<char, int>>> graph;
    for (char node : nodes) {
        graph[node] = {};
    }
    for (auto [u, v, weight] : edges) {
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }
    return graph;
}

pair<int, vector<char>> find_shortest_path(unordered_map<char, vector<pair<char, int>>> graph, char start, char end) {
    priority_queue<tuple<int, char, vector<char>>, vector<tuple<int, char, vector<char>>>, greater<>> queue;
    unordered_set<char> visited;
    queue.push({0, start, {start}});
    while (!queue.empty()) {
        auto [cost, node, path] = queue.top();
        queue.pop();
        if (visited.find(node) != visited.end()) {
            continue;
        }
        path.push_back(node);
        visited.insert(node);
        if (node == end) {
            return {cost, path};
        }
        for (auto [neighbor, weight] : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                queue.push({cost + weight, neighbor, path});
            }
        }
    }
    return {numeric_limits<int>::max(), {}};
}

int main() {
    vector<char> nodes = {'A', 'B', 'C', 'D', 'E'};
    vector<tuple<char, char, int>> edges = {make_tuple('A', 'B', 1), make_tuple('B', 'C', 2), make_tuple('C', 'D', 3), make_tuple('D', 'E', 4), make_tuple('E', 'A', 5)};
    auto graph = initialize_graph(nodes, edges);
    char start = 'A', end = 'E';
    auto [cost, path] = find_shortest_path(graph, start, end);
    cout << "Cost: " << cost << ", Path: ";
    for (char node : path) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}