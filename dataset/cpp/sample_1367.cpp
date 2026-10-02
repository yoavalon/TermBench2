cpp
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <map>

using namespace std;

pair<vector<char>, int> dijkstra(map<char, map<char, int>> graph, char start, char end) {
    priority_queue<pair<int, pair<char, vector<char>>>, vector<pair<int, pair<char, vector<char>>>>, greater<>> queue;
    queue.push({0, {start, {start}}});
    unordered_set<char> visited;
    while (!queue.empty()) {
        auto current = queue.top(); queue.pop();
        int cost = current.first;
        char node = current.second.first;
        vector<char> path = current.second.second;
        if (visited.find(node) == visited.end()) {
            visited.insert(node);
            path.push_back(node);
            if (node == end) {
                return {path, cost};
            }
            for (auto neighbor : graph[node]) {
                char next_node = neighbor.first;
                int next_cost = neighbor.second;
                if (visited.find(next_node) == visited.end()) {
                    queue.push({cost + next_cost, {next_node, path}});
                }
            }
        }
    }
    return {{}, 0};
}

int main() {
    map<char, map<char, int>> graph = {
        {'A', { {'B', 1}, {'C', 4} }},
        {'B', { {'A', 1}, {'C', 2}, {'D', 5} }},
        {'C', { {'A', 4}, {'B', 2}, {'D', 1} }},
        {'D', { {'B', 5}, {'C', 1} }}
    };
    char start_node = 'A';
    char end_node = 'D';
    auto result = dijkstra(graph, start_node, end_node);
    cout << "Path: ";
    for (char node : result.first) {
        cout << node << " ";
    }
    cout << "Cost: " << result.second << endl;
    return 0;
}