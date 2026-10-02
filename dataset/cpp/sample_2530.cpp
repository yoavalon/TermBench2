#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <limits>

using namespace std;

pair<int, vector<char>> dijkstra(unordered_map<char, vector<pair<char, int>>>& graph, char start, char end) {
    priority_queue<pair<int, pair<char, vector<char>>>, vector<pair<int, pair<char, vector<char>>>>, greater<>> queue;
    unordered_set<char> seen;
    unordered_map<char, int> dist;
    queue.push({0, {start, {start}}});
    dist[start] = 0;

    while (!queue.empty()) {
        int cost = queue.top().first;
        char v = queue.top().second.first;
        vector<char> path = queue.top().second.second;
        queue.pop();

        if (seen.find(v) == seen.end()) {
            seen.insert(v);
            path.push_back(v);
            if (v == end) {
                return {cost, path};
            }
            for (const auto& next : graph[v]) {
                char nextNode = next.first;
                int nextCost = next.second;
                if (seen.find(nextNode) == seen.end()) {
                    queue.push({cost + nextCost, {nextNode, path}});
                }
            }
        }
    }
    return {numeric_limits<int>::max(), {}};
}

pair<int, vector<char>> shortest_path(unordered_map<char, vector<pair<char, int>>>& graph, char start, char end) {
    return dijkstra(graph, start, end);
}

int main() {
    unordered_map<char, vector<pair<char, int>>> graph = {
        {'A', {{'B', 1}, {'C', 4}}},
        {'B', {{'A', 1}, {'C', 2}, {'D', 5}}},
        {'C', {{'A', 4}, {'B', 2}, {'D', 1}}},
        {'D', {{'B', 5}, {'C', 1}}}
    };
    char start = 'A';
    char end = 'D';
    auto result = shortest_path(graph, start, end);
    cout << result.first << " ";
    for (char c : result.second) {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}