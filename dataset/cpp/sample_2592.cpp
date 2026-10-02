#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
#include <map>
#include <string>

using namespace std;

vector<string> bfs_shortest_path(map<string, vector<string>>& graph, string start, string end) {
    queue<pair<string, vector<string>>> q;
    q.push({start, {start}});
    unordered_set<string> visited;
    while (!q.empty()) {
        auto [node, path] = q.front();
        q.pop();
        if (node == end) {
            return path;
        }
        if (visited.find(node) == visited.end()) {
            visited.insert(node);
            for (const string& neighbor : graph[node]) {
                if (visited.find(neighbor) == visited.end()) {
                    q.push({neighbor, path});
                    q.back().second.push_back(neighbor);
                }
            }
        }
    }
    return {};
}

void main() {
    map<string, vector<string>> graph = {
        {"A", {"B", "C"}},
        {"B", {"D", "E"}},
        {"C", {"F"}},
        {"D", {}},
        {"E", {"F"}},
        {"F", {}}
    };
    string start = "A";
    string end = "F";
    vector<string> path = bfs_shortest_path(graph, start, end);
    if (!path.empty()) {
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i < path.size() - 1) {
                cout << " -> ";
            }
        }
    } else {
        cout << "No path found";
    }
}