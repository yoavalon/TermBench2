#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int bfs(unordered_map<string, vector<string>>& graph, const string& start, const string& end) {
    queue<pair<string, int>> q;
    q.push({start, 0});
    unordered_set<string> visited;
    while (!q.empty()) {
        auto [node, dist] = q.front();
        q.pop();
        if (node == end) {
            return dist;
        }
        if (visited.find(node) == visited.end()) {
            visited.insert(node);
            for (const auto& neighbor : graph[node]) {
                q.push({neighbor, dist + 1});
            }
        }
    }
    return -1;
}

void main() {
    unordered_map<string, vector<string>> graph = {
        {"A", {"B", "C"}},
        {"B", {"D", "E"}},
        {"C", {"F"}},
        {"D", {}},
        {"E", {"F"}},
        {"F", {}}
    };
    string start = "A";
    string end = "F";
    cout << bfs(graph, start, end) << endl;
}