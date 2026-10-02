#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<double, char> pd;
typedef pair<char, double> pc;

struct Compare {
    bool operator()(const pd& a, const pd& b) {
        return a.first > b.first;
    }
};

pair<double, vector<char>> dijkstra(vector<vector<pc>>& graph, char start, char end) {
    priority_queue<pd, vector<pd>, Compare> q;
    unordered_set<char> visited;
    q.push({0.0, start});
    vector<char> path;
    while (!q.empty()) {
        double cost = q.top().first;
        char v = q.top().second;
        q.pop();
        if (visited.find(v) == visited.end()) {
            visited.insert(v);
            path.push_back(v);
            if (v == end) {
                return {cost, path};
            }
            for (const auto& next : graph[v - 'A']) {
                char next_node = next.first;
                double c = next.second;
                if (visited.find(next_node) == visited.end()) {
                    q.push({cost + c, next_node});
                }
            }
        }
    }
    return {0.0, path};
}

pair<double, vector<char>> find_shortest_path(vector<vector<pc>>& graph, char start, char end) {
    return dijkstra(graph, start, end);
}

void main() {
    vector<vector<pc>> graph = {
        {{'B', 1.0}, {'C', 4.0}},
        {{'C', 2.0}, {'D', 5.0}},
        {{'D', 1.0}},
        {}
    };
    char start = 'A';
    char end = 'D';
    auto [cost, path] = find_shortest_path(graph, start, end);
    cout << "Shortest path cost: " << cost << endl;
    cout << "Shortest path: ";
    for (char v : path) {
        cout << v << " ";
    }
    cout << endl;
}