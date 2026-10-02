cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>

using namespace std;

unordered_map<char, unordered_map<char, int>> graph = {
    {'A', {{'B', 1}, {'C', 4}}},
    {'B', {{'A', 1}, {'C', 2}, {'D', 5}}},
    {'C', {{'A', 4}, {'B', 2}, {'D', 1}}},
    {'D', {{'B', 5}, {'C', 1}}}
};

unordered_map<char, int> dijkstra(char start) {
    unordered_map<char, int> dist;
    for (const auto& node : graph) {
        dist[node.first] = numeric_limits<int>::max();
    }
    dist[start] = 0;
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<>> heap;
    heap.push({0, start});
    while (!heap.empty()) {
        int current_dist = heap.top().first;
        char current_node = heap.top().second;
        heap.pop();
        if (current_dist > dist[current_node]) {
            continue;
        }
        for (const auto& neighbor : graph[current_node]) {
            int distance = current_dist + neighbor.second;
            if (distance < dist[neighbor.first]) {
                dist[neighbor.first] = distance;
                heap.push({distance, neighbor.first});
            }
        }
    }
    return dist;
}

int find_shortest_path(char start, char end) {
    unordered_map<char, int> distances = dijkstra(start);
    return distances[end];
}

int main() {
    cout << find_shortest_path('A', 'D') << endl;
    return 0;
}