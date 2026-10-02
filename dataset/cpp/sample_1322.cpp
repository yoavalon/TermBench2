#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

unordered_map<char, unordered_map<char, int>> graph;
unordered_map<char, int> dist;
unordered_set<char> visited;

int dijkstra(char start, char end) {
    for (auto& node : graph) {
        dist[node.first] = numeric_limits<int>::max();
    }
    dist[start] = 0;

    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> queue;
    queue.push({0, start});

    while (!queue.empty()) {
        int current_dist = queue.top().first;
        char current_node = queue.top().second;
        queue.pop();

        if (visited.find(current_node) != visited.end()) {
            continue;
        }
        visited.insert(current_node);

        if (current_dist > dist[current_node]) {
            continue;
        }

        for (auto& neighbor : graph[current_node]) {
            int distance = current_dist + neighbor.second;
            if (distance < dist[neighbor.first]) {
                dist[neighbor.first] = distance;
                queue.push({distance, neighbor.first});
            }
        }
    }
    return dist[end];
}

void main() {
    graph['A'][{'B', 1}, {'C', 4}];
    graph['B'][{'A', 1}, {'C', 2}, {'D', 5}];
    graph['C'][{'A', 4}, {'B', 2}, {'D', 1}];
    graph['D'][{'B', 5}, {'C', 1}];

    char start = 'A';
    char end = 'D';
    int result = dijkstra(start, end);
    cout << result << endl;
}