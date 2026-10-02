#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <tuple>
#include <limits>

using namespace std;

pair<double, vector<char>> dijkstra(unordered_map<char, vector<pair<char, double>>>& graph, char start, char end) {
    priority_queue<tuple<double, char, vector<char>>, vector<tuple<double, char, vector<char>>>, greater<>> queue;
    queue.emplace(0.0, start, vector<char>{start});
    unordered_set<char> visited;
    while (!queue.empty()) {
        auto [cost, node, path] = queue.top();
        queue.pop();
        if (visited.find(node) == visited.end()) {
            visited.insert(node);
            path.push_back(node);
            if (node == end) {
                return {cost, path};
            }
            for (auto [neighbor, weight] : graph[node]) {
                if (visited.find(neighbor) == visited.end()) {
                    queue.emplace(cost + weight, neighbor, path);
                }
            }
        }
    }
    return {numeric_limits<double>::infinity(), {}};
}

int main() {
    unordered_map<char, vector<pair<char, double>>> graph = {
        {'A', {{'B', 1.5}, {'C', 2.3}}},
        {'B', {{'C', 0.9}, {'D', 3.2}}},
        {'C', {{'D', 1.7}}},
        {'D', {}}
    };
    char start = 'A';
    char end = 'D';
    auto result = dijkstra(graph, start, end);
    cout << "(" << result.first << ", [";
    for (size_t i = 0; i < result.second.size(); ++i) {
        cout << result.second[i];
        if (i < result.second.size() - 1) {
            cout << ", ";
        }
    }
    cout << "])" << endl;
    return 0;
}