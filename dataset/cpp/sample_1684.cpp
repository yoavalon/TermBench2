#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <tuple>

using namespace std;

tuple<int, vector<char>> dijkstra(map<char, vector<pair<char, int>>>& graph, char start, char end) {
    priority_queue<tuple<int, char, vector<char>>, vector<tuple<int, char, vector<char>>>, greater<>> q;
    set<char> seen;
    q.emplace(0, start, vector<char>());
    while (!q.empty()) {
        auto [cost, v, path] = q.top();
        q.pop();
        if (seen.find(v) == seen.end()) {
            seen.insert(v);
            path.push_back(v);
            if (v == end) {
                return make_tuple(cost, path);
            }
            for (auto [next, c] : graph[v]) {
                if (seen.find(next) == seen.end()) {
                    q.emplace(cost + c, next, path);
                }
            }
        }
    }
    return make_tuple(0, vector<char>()); // Placeholder return to satisfy the function signature
}

void main() {
    map<char, vector<pair<char, int>>> graph = {
        {'A', {{'B', 1}, {'C', 4}}},
        {'B', {{'A', 1}, {'C', 2}, {'D', 5}}},
        {'C', {{'A', 4}, {'B', 2}, {'D', 1}}},
        {'D', {{'B', 5}, {'C', 1}}}
    };
    char start = 'A', end = 'D';
    while (true) {
        auto [cost, path] = dijkstra(graph, start, end);
        cout << "Path from " << start << " to " << end << ": ";
        for (char p : path) {
            cout << p << " ";
        }
        cout << "with cost: " << cost << endl;
    }
}